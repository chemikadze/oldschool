unit FractObj;

interface
uses
  Windows, FastDib, FastFX, Dialogs, SysUtils;


const
  DEFAULT_ANGLE: Real = PI/3;           //Default turn angle: PI/3
  DEFAULT_DEEP: Byte = 3;               //Default deep of recursion

  CHR_LEFT = '-';
  CHR_RIGHT = '+';
  CHR_FORWARD = 'F';
  CHR_X = 'X';
  CHR_Y = 'Y';
  CHR_Z = 'Z';
  CHR_B = 'B';
  CHR_PUSH = '[';
  CHR_POP = ']';


type
  //Reading properties
  TFractalReader = class(TObject)
  protected
    FAxiom: String;
    FNewF: String;
    FNewX: String;
    FNewY: String;
    FNewZ: String;
    FNewB: String;
    FMaxDeep: Byte;
    FStartAngle: Real;
  public
    property Axiom: String read FAxiom write FAxiom;
    property NewF: String read FNewF write FNewF;
    property NewX: String read FNewX write FNewX;
    property NewY: String read FNewY write FNewY;
    property NewZ: String read FNewZ write FNewZ;
    property NewB: String read FNewB write FNewB;
    property MaxDeep: Byte read FMaxDeep write FMaxDeep;
    property StartAngle: Real read FStartAngle write FStartAngle;
  end;

  //Fractal builder (abstract)
  PNode = ^TNode;
  TNode = record
    x, y, a: Real;
    Prev: PNode;
  end;

  TFractalBuilder = class(TFractalReader)
  private
    FTerminated: Boolean;
    FAngle: Real;
    FDrawAngle: Real;
    FX, FY: Real;
    FOffX, FOffY: Real;
    FStack: PNode;
    procedure HandleExpression(const Expr: String; CurrentDeep: Byte);
    procedure Push;
    procedure Pop;
  protected
    procedure DoDraw; virtual;
    procedure DoSkip; virtual;
    procedure DoMove; virtual;
    procedure DoChunkUpdate; virtual;
    procedure DoBranchOpen; virtual;
    procedure DoBranchClose; virtual;
  public
    constructor Create;
    destructor Destroy; override;
    property Angle: Real read FAngle write FAngle;
    procedure Build; virtual;
    property Terminated: Boolean read FTerminated write FTerminated default False;
    procedure ClearList; virtual;
  end;

  // Calc screen offsets, dimentions, etc
  TFractalCalc = class(TFractalBuilder)
  private
    FMaxX, FMaxY, FMinX, FMinY: Real;
    FCoeff: Real;
    FCount: DWord;
  protected
    procedure DoDraw; override;
    procedure DoSkip; override;
  public
    procedure Build; override;
    function Coeff(Width, Height: Word): Real;
    function PaddTop(Height: Word): Real;
    function PaddLeft(Width: Word): Real;
    property Count: DWord read FCount;
  end;

  // Drawing fractal
  TDoUpdate = procedure(src: HDC; x1, y1, x2, y2: Integer) of object;

  // Info about color
  TColorInfo = record
    FLineCount: DWord;
    FColorStep: DWord;

    FCr, FCg, FCb: Real;
    FR, FG, FB: Real;
    FColorPos: Byte;

    FDeltaEach: Real;
    FC: Real;
    FMaxColor: Byte;
  end;


  TFractalRender = class(TFractalBuilder)
  private
    FCanvas: HDC;
    FCoeff: Real;
    FDib: TFastDib;
    FAutoUpdate: Boolean;
    FDoUpdate: TDoUpdate;
    FMaxX, FMaxY, FMinX, FMinY: Real;
    FBranches: Byte;
    FUseBranchWidth: Boolean;
    FColorAsTree: Boolean;

    FColorInfo: TColorInfo;
    function GetIntDC: HDC;
    procedure ChangeColor;
    procedure UpdateColor;
    procedure SetMaxColors(Value: Integer);
  protected
    procedure DoDraw; override;
    procedure DoSkip; override;
    procedure DoMove; override;
    procedure DoChunkUpdate; override;
    procedure DoBranchOpen; override;
    procedure DoBranchClose; override;
  public
    ColorData: array[1..30] of tfColor;
    constructor Create(Canvas: HDC);
    destructor Destroy; override;
    procedure Render(OffX, OffY: Real; W, H: Word; LineCount: DWord);
    property Coeff: Real read FCoeff write FCoeff;
    property AutoUpdate: Boolean read FAutoUpdate write FAutoUpdate default False;
    property SrcDC: HDC read GetIntDC;
    property UseBranchWidth: Boolean read FUseBranchWidth write FUseBranchWidth default False;
  published
    property OnDoThisUpdateAsYouWant: TDoUpdate read FDoUpdate write FDoUpdate;
    property Dib: TFastDib read FDib;
    property ColorAsTree: Boolean read FColorAsTree write FColorAsTree default False;
    property MaxColors: Integer write SetMaxColors;
  end;


implementation
//-- TFractalBuilder --\\
constructor TFractalBuilder.Create;
begin
  inherited;
  Angle := DEFAULT_ANGLE;
  MaxDeep := DEFAULT_DEEP;
  FStack := nil;
end;

destructor TFractalBuilder.Destroy;
begin
  inherited;
end;

procedure TFractalBuilder.HandleExpression(const Expr: String; CurrentDeep: Byte);
var
  i: Word;
begin
  if FTerminated then Exit;
  for i := 1 to Length(Expr) do begin
  if FTerminated then Exit;
    case Expr[i] of
      CHR_LEFT: FDrawAngle := FDrawAngle - FAngle;
      CHR_RIGHT: FDrawAngle := FDrawAngle + FAngle;
      CHR_PUSH: begin DoBranchOpen; Push; end;
      CHR_POP: begin DoBranchClose; Pop; end;
      CHR_FORWARD:
        if CurrentDeep < FMaxDeep then begin
          HandleExpression(FNewF, CurrentDeep + 1);
          if (CurrentDeep + 1 = FMaxDeep) then
            DoChunkUpdate;
        end else
          DoDraw;
      CHR_B:
        if CurrentDeep < FMaxDeep then
          HandleExpression(FNewB, CurrentDeep + 1)
        else
          DoSkip;
      CHR_X:
        if CurrentDeep < FMaxDeep then
          HandleExpression(FNewX, CurrentDeep + 1);
      CHR_Y:
        if CurrentDeep < FMaxDeep then
          HandleExpression(FNewY, CurrentDeep + 1);
      CHR_Z:
        if CurrentDeep < FMaxDeep then
          HandleExpression(FNewZ, CurrentDeep + 1);
    end;
  end;
end;

procedure TFractalBuilder.Push;
var
  p: PNode;
begin
  if FStack = nil then begin
    New(FStack);
    FStack.x := FX;
    FStack.y := FY;
    FStack.a := FDrawAngle;
    FStack.Prev := nil;
  end else begin
    New(p);
    p.x := FX;
    p.y := FY;
    p.a := FDrawAngle;
    p.Prev := FStack;
    FStack := p;
  end;
end;

procedure TFractalBuilder.Pop;
var
  p: PNode;
begin
  if FStack <> nil then begin
    FX := FStack.x;
    FY := FStack.y;
    FDrawAngle := FStack.a;
    p := FStack;
    FStack := FStack.Prev;
    Dispose(p);
    DoMove;
  end;
end;

procedure TFractalBuilder.DoDraw;
begin
  FY := FY + Sin(FDrawAngle);
  FX := FX + Cos(FDrawAngle);
end;

procedure TFractalBuilder.DoSkip;
begin
  FY := FY + Sin(FDrawAngle);
  FX := FX + Cos(FDrawAngle);
end;

procedure TFractalBuilder.DoMove;
begin
end;

procedure TFractalBuilder.DoChunkUpdate;
begin
end;

procedure TFractalBuilder.DoBranchOpen;
begin
end;

procedure TFractalBuilder.DoBranchClose;
begin
end;

procedure TFractalBuilder.Build;
begin
  FDrawAngle := FStartAngle;
  HandleExpression(FAxiom, 0);
end;

procedure TFractalBuilder.ClearList;
begin
  while FStack <> nil do Pop;
end;





//-- TFractalCalc --\\
procedure TFractalCalc.Build;
begin
  FX := 0; FY := 0;
  FMaxX := 0; FMaxY := 0;
  FMinX := 0; FMinY := 0;
  FCount := 0;
  FTerminated := False;  
  inherited;
end;

procedure TFractalCalc.DoDraw;
begin
  inherited;
  Inc(FCount);
  if (FX > FMaxX) then FMaxX := FX;
  if (FX < FMinX) then FMinX := FX;
  if (FY > FMaxY) then FMaxY := FY;
  if (FY < FMinY) then FMinY := FY;
end;

procedure TFractalCalc.DoSkip;
begin
  DoDraw;
  Dec(FCount);
end;

function TFractalCalc.Coeff(Width, Height: Word): Real;
var
  XC: Real;
  YC: Real;
begin
  if FMaxX - FMinX = 0 then XC := 1 else
    XC := Width / Abs(FMaxX - FMinX);
  if FMaxY - FMinY = 0 then YC := 1 else
    YC := Height / Abs(FMaxY - FMinY);
  if YC > XC then Result := XC else Result := YC;
  FCoeff := Result;
end;

function TFractalCalc.PaddTop(Height: Word): Real;
begin
  if FMaxY * FCoeff > Height then
    Result := Height - FMaxY * FCoeff
  else if FMinY < 0 then begin
    Result := -FMinY
  end else
    Result := 0;

  Result := Result +
    Abs(
      (Height - Abs(FMaxY - FMinY) * FCoeff) / 2
    ) / FCoeff;
end;

function TFractalCalc.PaddLeft(Width: Word): Real;
begin
  if FMaxX * FCoeff > Width then
    Result := Width - FMaxX * FCoeff
  else if FMinX < 0 then
    Result := -FMinX
  else
    Result := 0;

  Result := Result +
    Abs(
      (Width - Abs(FMaxX - FMinX) * FCoeff) / 2
    ) / FCoeff;
end;



//-- TFractalDraw --\\
constructor TFractalRender.Create(Canvas: HDC);
begin
  inherited Create;
  FCanvas := Canvas;
  FDib := TFastDib.Create;
end;

destructor TFractalRender.Destroy;
begin
  FDib.Free;
  inherited;
end;

function TFractalRender.GetIntDC: HDC;
begin
  Result := FDib.hDC;
end;

procedure TFractalRender.DoDraw;
var
  color: DWord;
begin
  inherited;

  if FColorAsTree then begin

    Inc(FColorInfo.FMaxColor);
    if FBranches < FColorInfo.FMaxColor then begin
      color := RGB(ColorData[FBranches + 1].r, ColorData[FBranches + 1].g, ColorData[FBranches + 1].b);
    end else
      color := RGB(ColorData[FColorInfo.FMaxColor].r, ColorData[FColorInfo.FMaxColor].g, ColorData[FColorInfo.FMaxColor].b);
    Dec(FColorInfo.FMaxColor);
  end else begin
    color := RGB(Round(FColorInfo.FR), Round(FColorInfo.FG), Round(FColorInfo.FB));
    UpdateColor;
  end;

  if FUseBranchWidth then
    FDib.SetPen(0, FMaxDeep - FBranches + 1, color)
  else
    FDib.SetPen(0, 1, color);


  FDib.LineTo(Round(FX * FCoeff), Round(FY * FCoeff));


  if (FX > FMaxX) or (FMaxX = -1) then FMaxX := FX;
  if (FX < FMinX) or (FMinX = -1) then FMinX := FX;
  if (FY > FMaxY) or (FMaxY = -1) then FMaxY := FY;
  if (FY < FMinY) or (FMinY = -1) then FMinY := FY;
end;

procedure TFractalRender.DoSkip;
begin
  inherited;
  FDib.MoveTo(Round(FX * FCoeff), Round(FY * FCoeff));
end;

procedure TFractalRender.DoMove;
begin
  FDib.MoveTo(Round(FX * FCoeff), Round(FY * FCoeff));
end;

procedure TFractalRender.DoChunkUpdate;
begin
  if FAutoUpdate then begin
    if Assigned(OnDoThisUpdateAsYouWant) then begin
      FDoUpdate(FDib.hDC, Round(FMinX * FCoeff) - 1, Round(FMinY * FCoeff) - 1, Round(FMaxX * FCoeff) + 1, Round(FMaxY * FCoeff) + 1);
      FMinX := FX; FMinY := FY;
      FMaxX := FX; FMaxY := FY;
    end;
  end;
end;

procedure TFractalRender.DoBranchOpen;
begin
  Inc(FBranches);
end;

procedure TFractalRender.DoBranchClose;
begin
  if FBranches > 0 then
    Dec(FBranches);
end;

procedure TFractalRender.Render(OffX, OffY: Real; W, H: Word; LineCount: DWord);
begin
  FTerminated := False;
  FDib.SetSize(W, H, 24);
  FDib.SetPen(0, 1, 0);

  {÷вета}
  begin
    FColorInfo.FLineCount := LineCount;
    FColorInfo.FColorStep := LineCount;

    FColorInfo.FColorPos := 1;
    FColorInfo.FDeltaEach := FColorInfo.FColorStep / FColorInfo.FMaxColor;
    FColorInfo.FC := 0;
    ChangeColor;
  end;

  FMaxX := -1; FMaxY := -1; FMinX := -1; FMinY := -1;
  FBranches := 0;

  FX := OffX; FY := OffY;
  FOffX := OffX; FOffY := OffY;

  FDib.MoveTo(Round(FX * FCoeff), Round(FY * FCoeff));
  FDib.Clear(tfWhite);
  if FAutoUpdate then begin
    if Assigned(OnDoThisUpdateAsYouWant) then
      FDoUpdate(FDib.hDC, 0, 0, W, H);
  end;

  inherited Build;

  //—гладить кра€
  EmbossEdges(FDib, 1);
  if Assigned(OnDoThisUpdateAsYouWant) then
    FDoUpdate(FDib.hDC, 0, 0, W, H);
end;

procedure TFractalRender.ChangeColor;
begin
  with FColorInfo do begin
    FCr := (ColorData[FColorPos+1].r - ColorData[FColorPos].r) / FDeltaEach;
    FCg := (ColorData[FColorPos+1].g - ColorData[FColorPos].g) / FDeltaEach;
    FCb := (ColorData[FColorPos+1].b - ColorData[FColorPos].b) / FDeltaEach;

    FR := ColorData[FColorPos].r;
    FG := ColorData[FColorPos].g;
    FB := ColorData[FColorPos].b;
  end;
end;

procedure TFractalRender.UpdateColor;
begin
  with FColorInfo do begin
    FR := FR + FCr;
    FG := FG + FCg;
    FB := FB + FCb;

    FC := FC + 1;
    if FC >= FDeltaEach then begin
      FC := FC - FDeltaEach;
      Inc(FColorPos);
      ChangeColor;
    end;
  end;
end;

procedure TFractalRender.SetMaxColors(Value: Integer);
begin
  FColorInfo.FMaxColor := Value;
end;


end.
