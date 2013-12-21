unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, FractObj, ExtCtrls, Menus, FastDib, FastFiles, Dialogs,
  AppEvnts, Intro, Lang;

type
  TMainForm = class(TForm)
    Region: TImage;
    PopupMenu1: TPopupMenu;
    BuildItem: TMenuItem;
    bmp1: TMenuItem;
    jpeg1: TMenuItem;
    int1: TMenuItem;
    N1: TMenuItem;
    SaveDialog: TSaveDialog;
    LoadItem: TMenuItem;
    OpenDialog: TOpenDialog;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormCanResize(Sender: TObject; var NewWidth,
      NewHeight: Integer; var Resize: Boolean);
    procedure FormKeyUp(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure BuildItemClick(Sender: TObject);
    procedure bmp1Click(Sender: TObject);
    procedure N1Click(Sender: TObject);
    procedure RegionDblClick(Sender: TObject);
    procedure jpeg1Click(Sender: TObject);
    procedure int1Click(Sender: TObject);
    procedure LoadItemClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    BeforeFullScrX,
    BeforeFullScrY,
    BeforeFullScrW,
    BeforeFullScrH: Integer;
    Fract: TFractalRender;
    Calc: TFractalCalc;
    FIsFull: Boolean;
  public
    procedure FullScreen;
    procedure NormalScreen;
    procedure BuildFractal(const _Axiom, _NewF, _NewX, _NewY, _NewZ, _NewB: String; _Angle, _StartAngle: Real; _Deep: Byte);
    procedure UpdateFractalRegion(src: HDC; x1, y1, x2, y2: Integer);
    procedure WMPaint(var Message: TMsg); message WM_PAINT;
  end;

  TMyThread = class(TThread)
  protected
    procedure Execute; override;
  end;

var
  MainForm: TMainForm;
  A: TMyThread = nil;

  _FAxiom, _FNewF, _FNewX, _FNewY, _FNewZ, _FNewB: String;
  _FAngle, _FStartAngle: Real; _FDeep: Byte;
  _ColorAsTree: Boolean;


procedure StopFractalThreaded;  


implementation
uses
  Params;

{$R *.dfm}

procedure TMyThread.Execute;
var
  Coeff: Real;
  PaddTop,
  PaddLeft: Real;

  W: Word;
  H: Word;

  _MaxColors, i: Integer;
begin
  ParamsForm.ViewButton.Caption := LangArray[0, CurLang];
  if MainForm.N1.Checked then begin
    if not MainForm.FIsFull then begin
      MainForm.BeforeFullScrX := MainForm.Left;
      MainForm.BeforeFullScrY := MainForm.Top;
      MainForm.BeforeFullScrW := MainForm.Width;
      MainForm.BeforeFullScrH := MainForm.Height;
      MainForm.FIsFull := True;
      MainForm.FullScreen;
    end
  end else
    if MainForm.FIsFull then begin
      MainForm.NormalScreen;
      MainForm.FIsFull := False;
    end;

  _MaxColors := ParamsForm.FColorList.Count;
  if _MaxColors < 1 then begin
    MainForm.Fract.ColorData[1] := FRGB(0, 0, 0);
    MainForm.Fract.ColorData[2] := MainForm.Fract.ColorData[1];
    _MaxColors := 1;
  end else
  if _MaxColors = 1 then begin
    MainForm.Fract.ColorData[1] := IntToColor(TImage(ParamsForm.FColorList[0]).Canvas.Pixels[5, 5]);
    MainForm.Fract.ColorData[2] := MainForm.Fract.ColorData[1];
    _MaxColors := 1;
  end else begin
    for i := 0 to ParamsForm.FColorList.Count - 1 do
      MainForm.Fract.ColorData[i+1] := IntToColor(TImage(ParamsForm.FColorList[i]).Canvas.Pixels[5, 5]);
    Dec(_MaxColors);
  end;

  MainForm.Region.Align := alClient;
  MainForm.Region.Align := alNone;  
  MainForm.Show;

  W := MainForm.Region.Width;
  H := MainForm.Region.Height;

  if Terminated then Exit;

  with MainForm.Calc do begin
    ClearList;
    Axiom := _FAxiom;
    NewF := _FNewF;
    NewX := _FNewX;
    NewY := _FNewY;
    NewZ := _FNewZ;
    NewB := _FNewB;
    MaxDeep := _FDeep;
    Angle := _FAngle;
    StartAngle := _FStartAngle;
    Build;
  end;

  Coeff := MainForm.Calc.Coeff(W, H);
  PaddLeft := MainForm.Calc.PaddLeft(W);
  PaddTop := MainForm.Calc.PaddTop(H);

  with MainForm.Fract do begin
    ClearList;
    Axiom := _FAxiom;
    NewF := _FNewF;
    NewX := _FNewX;
    NewY := _FNewY;
    NewZ := _FNewZ;
    NewB := _FNewB;
    Angle := _FAngle;
    StartAngle := _FStartAngle;
    MaxDeep := _FDeep;
    MaxColors := _MaxColors;
    ColorAsTree := _ColorAsTree;
  end;
  MainForm.Fract.Coeff := Coeff;
  MainForm.Fract.AutoUpdate := ParamsForm.DoUpdateChk.Checked;
  MainForm.Fract.UseBranchWidth := ParamsForm.DynamicWidthChk.Checked;

  if Terminated then Exit;

  if MainForm.Calc.Count > 0 then
    MainForm.Fract.Render(PaddLeft, PaddTop, W, H, MainForm.Calc.Count);
  ParamsForm.ViewButton.Caption := LangArray[1, CurLang];
end;

procedure StopFractalThreaded;
begin
    MainForm.Calc.Terminated := True;
    MainForm.Fract.Terminated := True;
    if A <> nil then begin
      A.Terminate;
      A.Free;
    end;
    A := nil;
    ParamsForm.ViewButton.Caption := LangArray[1, CurLang];
end;

procedure DrawFractalThreaded;
begin
  StopFractalThreaded;
  A := TMyThread.Create(False);
end;


procedure TMainForm.FullScreen;
var
  style, cx, cy: DWord;
begin
  Region.ShowHint := True;
  N1.Checked := True;
  ShowWindow(Handle, SW_MAXIMIZE);
  style := GetWindowLong(Handle, GWL_STYLE);
  style := style and not (WS_DLGFRAME or WS_THICKFRAME);
  SetWindowLong(Handle, GWL_STYLE, style);
  cx := GetSystemMetrics(SM_CXSCREEN);
  cy := GetSystemMetrics(SM_CYSCREEN);
  SetWindowPos(Handle, HWND_TOPMOST, -1, -1, cx+3, cy+3, SWP_FRAMECHANGED);
end;

procedure TMainForm.NormalScreen;
var
  style: DWord;
begin
  N1.Checked := False;
  Region.ShowHint := False;
  style := GetWindowLong(Handle, GWL_STYLE) or WS_DLGFRAME or WS_THICKFRAME;
  SetWindowLong(Handle, GWL_STYLE, style);
  SetWindowPos(Handle, HWND_NOTOPMOST, BeforeFullScrX,
    BeforeFullScrY, BeforeFullScrW, BeforeFullScrH, SWP_NOMOVE or SWP_NOSIZE);
  ShowWindow(Handle, SW_NORMAL);
end;


procedure TMainForm.BuildFractal(const _Axiom, _NewF, _NewX, _NewY, _NewZ, _NewB: String; _Angle, _StartAngle: Real; _Deep: Byte);
begin
  _FAxiom := _Axiom;
  _FNewF := _NewF;
  _FNewX := _NewX;
  _FNewY := _NewY;
  _FNewZ := _NewZ;
  _FNewB := _NewB;
  _FAngle := _Angle;
  _FStartAngle := _StartAngle;
  _FDeep := _Deep;
  _ColorAsTree := ParamsForm.ColorAsTreeChk.Checked;
  DrawFractalThreaded;
end;

procedure TMainForm.UpdateFractalRegion(src: HDC; x1, y1, x2, y2: Integer);
begin
  try
    if x1 < 0 then x1 := 0;
    if y1 < 0 then y1 := 0;
    if x2 > Region.Width then x2 := Region.Width;
    if y2 > Region.Height then y2 := Region.Height;

    {if ParamsForm.DebugChk.Checked then begin
    Rectangle(Canvas.Handle, Region.Left + x1, Region.Top + y1, Region.Left + x2, Region.Top + y2);
    MessageBox(0, '', 'Debug', 0);
    end;}
    if A <> nil then begin
      MainForm.Canvas.Lock;
      BitBlt(Canvas.Handle, Region.Left + x1, Region.Top + y1, (x2-x1), (y2-y1), src, x1, y1, SRCCOPY);
      MainForm.Canvas.UnLock;
    end;
  except
  end;
end;

procedure TMainForm.WMPaint(var Message: TMsg);
var
  lpPaint: TPaintStruct;
  OutRect: TRect;
begin
  try
    BeginPaint(Handle, lpPaint);
    if IntersectRect(OutRect, lpPaint.rcPaint, Region.BoundsRect) then begin
      MainForm.Canvas.Lock;
      BitBlt(Canvas.Handle, OutRect.Left, OutRect.Top,
        OutRect.Right - OutRect.Left, OutRect.Bottom - OutRect.Top,
        Fract.SrcDC, OutRect.Left - Region.BoundsRect.Left, OutRect.Top - Region.BoundsRect.Top, SRCCOPY
      );
      MainForm.Canvas.Unlock;
    end;
    EndPaint(Handle, lpPaint);
  except
  end;
  inherited;
end;

procedure TMainForm.FormCreate(Sender: TObject);
begin
  Calc := TFractalCalc.Create;
  FIsFull := False;
  with TIntroForm.Create(Self) do begin
    ShowModal;
  end;
end;

procedure TMainForm.FormShow(Sender: TObject);
begin
  Fract := TFractalRender.Create(Canvas.Handle);
  Fract.OnDoThisUpdateAsYouWant := UpdateFractalRegion;
end;

procedure TMainForm.FormCanResize(Sender: TObject; var NewWidth,
  NewHeight: Integer; var Resize: Boolean);
begin
  if NewWidth < 200 then NewWidth := 200;
  if NewHeight < 200 then NewHeight := 200;
end;

procedure TMainForm.FormKeyUp(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  if Key = VK_SPACE then
    ParamsForm.ForceBuild
  else if Key = 27 {Esc} then begin
    if N1.Checked then begin
      N1.Checked := False;
      ParamsForm.ForceBuild;
    end;
  end;
end;

procedure TMainForm.BuildItemClick(Sender: TObject);
begin
  ParamsForm.ForceBuild;
end;

procedure TMainForm.bmp1Click(Sender: TObject);
var
  S: String;
begin
  SaveDialog.Filter := LangArray[2, CurLang] + ' (*.bmp)|*.bmp';
  if SaveDialog.Execute then begin
    if SaveDialog.Files.Count > 0 then begin
      S := StringReplace(SaveDialog.Files[0], '.bmp', '', [rfReplaceAll]);
      FastFiles.SaveBMPFile(Fract.Dib, S + '.bmp');
    end;
  end;
end;

procedure TMainForm.jpeg1Click(Sender: TObject);
var
  S: String;
begin
  SaveDialog.Filter := LangArray[3, CurLang] + ' (*.jpg)|*.jpg';
  if SaveDialog.Execute then begin
    if SaveDialog.Files.Count > 0 then begin
      S := StringReplace(SaveDialog.Files[0], '.jpg', '', [rfReplaceAll]);
      FastFiles.SaveJpgFile(Fract.Dib, S + '.jpg', 80);
    end;
  end;
end;

procedure TMainForm.int1Click(Sender: TObject);
var
  S: String;
begin
  SaveDialog.Filter := LangArray[4, CurLang] + ' (*.l-s)|*.l-s';
  if SaveDialog.Execute then begin
    if SaveDialog.Files.Count > 0 then begin
      S := StringReplace(SaveDialog.Files[0], '.l-s', '', [rfReplaceAll]);
      ParamsForm.SaveToFile(S + '.l-s');
    end;
  end;
end;

procedure TMainForm.LoadItemClick(Sender: TObject);
begin
  OpenDialog.Filter := LangArray[4, CurLang] + ' (*.l-s)|*.l-s';
  if OpenDialog.Execute then begin
    if OpenDialog.Files.Count > 0 then begin
      ParamsForm.LoadFromFile(OpenDialog.Files[0]);
    end;
  end;
  ParamsForm.ForceBuild;
end;

procedure TMainForm.N1Click(Sender: TObject);
begin
  N1.Checked := not N1.Checked;
  ParamsForm.ForceBuild;
end;

procedure TMainForm.RegionDblClick(Sender: TObject);
begin
  N1.Checked := not N1.Checked;
  ParamsForm.ForceBuild;
end;

procedure TMainForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  StopFractalThreaded;
end;

end.
