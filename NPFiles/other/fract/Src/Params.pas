unit Params;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Main, Spin, ComCtrls, IniFiles, ExtCtrls, Menus, Lang,
  ShellAPI;

type
  TParamsForm = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    GroupBox1: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Label14: TLabel;
    ViewButton: TButton;
    MinusButton: TButton;
    PlusButton: TButton;
    NameEdit: TEdit;
    AxiomEdit: TEdit;
    NewFEdit: TEdit;
    GroupBox2: TGroupBox;
    StepsEdit: TSpinEdit;
    Angle1Edit: TEdit;
    Angle2Edit: TEdit;
    NewXEdit: TEdit;
    NewYEdit: TEdit;
    NewBEdit: TEdit;
    TabSheet2: TTabSheet;
    StartAngle1Edit: TEdit;
    StartAngle2Edit: TEdit;
    ReadyCombo: TComboBox;
    Label4: TLabel;
    NewZEdit: TEdit;
    Label15: TLabel;
    GroupBox3: TGroupBox;
    Label16: TLabel;
    GroupBox4: TGroupBox;
    DynamicWidthChk: TCheckBox;
    DoUpdateChk: TCheckBox;
    SpinEdit1: TSpinEdit;
    ColorAsTreeChk: TCheckBox;
    ColorDialog1: TColorDialog;
    MainMenu1: TMainMenu;
    N1: TMenuItem;
    N3: TMenuItem;
    CloseItem: TMenuItem;
    SaveJpgItem: TMenuItem;
    SaveBmpItem: TMenuItem;
    SaveIntItem: TMenuItem;
    LoadItem: TMenuItem;
    AboutItem: TMenuItem;
    N8: TMenuItem;
    N2: TMenuItem;
    RussianItem: TMenuItem;
    EnglishItem: TMenuItem;
    procedure ViewButtonClick(Sender: TObject);
    procedure MinusButtonClick(Sender: TObject);
    procedure PlusButtonClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure ReadyComboChange(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure SpinEdit1Change(Sender: TObject);
    procedure SaveBmpItemClick(Sender: TObject);
    procedure SaveJpgItemClick(Sender: TObject);
    procedure SaveIntItemClick(Sender: TObject);
    procedure LoadItemClick(Sender: TObject);
    procedure CloseItemClick(Sender: TObject);
    procedure RussianItemClick(Sender: TObject);
    procedure EnglishItemClick(Sender: TObject);
    procedure HelpItemClick(Sender: TObject);
    procedure AboutItemClick(Sender: TObject);
  private
    EdTop: Integer;
    EdLeft: Integer;
    procedure AddEntry(const Name,
      F, NewF, NewX, NewY, NewZ, NewB: String;
      Steps: Byte;
      Angle1, Angle2,
      StartAngle1, StartAngle2: Integer; DynamicWidth, DynamicColors: Boolean; const Colors: array of TColor);
    procedure ProcessEntry(i: Integer);
    procedure AddColorEdit(Color: TColor = clBlack);
    procedure FreeColorEdits;
    procedure OnImageClick(Sender: TObject);
  public
    FColorList: TList;
    procedure SaveToFile(const FileName: String);
    procedure LoadFromFile(const FileName: String);
    procedure ForceBuild;
  end;

var
  ParamsForm: TParamsForm;
  FList: TList;

type
  PCustomItem = ^TCustomItem;
  TCustomItem = record
    Name,
    F, NewF, NewX, NewY, NewZ, NewB: String;
    Steps: Byte;
    Angle1, Angle2,
    StartAngle1, StartAngle2: Integer;
    DynamicWidth,
    DynamicColors: Boolean;
    ColorCount: Integer;
    Colors: array[0..30] of TColor;
  end;

const
  EdWidth = 40;
  EdHeight = 20;
  EdDefTop = 60;
  EdDefLeft = 5;

implementation

{$R *.dfm}

procedure TParamsForm.SaveToFile(const FileName: String);
var
  ini: TIniFile;
  i: Integer;
begin
  try
    ini := TIniFile.Create(FileName);
    ini.EraseSection('Src');
    ini.WriteString('Src', 'Name', NameEdit.Text);
    ini.WriteString('Src', 'Axiom', AxiomEdit.Text);
    ini.WriteString('Src', 'NewF', NewFEdit.Text);
    ini.WriteString('Src', 'NewX', NewXEdit.Text);
    ini.WriteString('Src', 'NewY', NewYEdit.Text);
    ini.WriteString('Src', 'NewZ', NewZEdit.Text);
    ini.WriteString('Src', 'NewB', NewBEdit.Text);
    ini.WriteInteger('Src', 'Steps', StepsEdit.Value);
    ini.WriteString('Src', 'Angle1', Angle1Edit.Text);
    ini.WriteString('Src', 'Angle2', Angle2Edit.Text);
    ini.WriteString('Src', 'StartAngle1', StartAngle1Edit.Text);
    ini.WriteString('Src', 'StartAngle2', StartAngle2Edit.Text);
    ini.WriteBool('Src', 'DynamicWidth', DynamicWidthChk.Checked);
    ini.WriteBool('Src', 'DynamicColors', ColorAsTreeChk.Checked);
    ini.WriteInteger('Src', 'ColorCount', FColorList.Count);
    for i := 0 to FColorList.Count - 1 do
      ini.WriteInteger('Src', 'Color' + IntToStr(i), TImage(FColorList.Items[i]).Canvas.Pixels[5, 5]);
    ini.UpdateFile;
    ini.Free;
  except
  end;
end;

procedure TParamsForm.LoadFromFile(const FileName: String);
var
  ini: TIniFile;
  c, i: Integer;
begin
  try
    ini := TIniFile.Create(FileName);
    NameEdit.Text := ini.ReadString('Src', 'Name', '');
    AxiomEdit.Text := ini.ReadString('Src', 'Axiom', '');
    NewFEdit.Text := ini.ReadString('Src', 'NewF', '');
    NewXEdit.Text := ini.ReadString('Src', 'NewX', '');
    NewZEdit.Text := ini.ReadString('Src', 'NewZ', '');
    NewYEdit.Text := ini.ReadString('Src', 'NewY', '');
    NewBEdit.Text := ini.ReadString('Src', 'NewB', '');
    StepsEdit.Value := ini.ReadInteger('Src', 'Steps', 0);
    Angle1Edit.Text := ini.ReadString('Src', 'Angle1', '');
    Angle2Edit.Text := ini.ReadString('Src', 'Angle2', '');
    StartAngle1Edit.Text := ini.ReadString('Src', 'StartAngle1', '');
    StartAngle2Edit.Text := ini.ReadString('Src', 'StartAngle2', '');
    DynamicWidthChk.Checked := ini.ReadBool('Src', 'DynamicWidth', False);
    ColorAsTreeChk.Checked := ini.ReadBool('Src', 'DynamicColors', False);
    c := ini.ReadInteger('Src', 'ColorCount', 0);
    FreeColorEdits;
    if c < 1 then
      AddColorEdit
    else for i := 0 to c - 1 do
      AddColorEdit(ini.ReadInteger('Src', 'Color' + IntToStr(i), 0));
    ini.Free;
  except
  end;
end;

procedure TParamsForm.ViewButtonClick(Sender: TObject);
begin
  try
    if ViewButton.Caption = LangArray[0, CurLang] then begin
      StopFractalThreaded;
      Exit;
    end;

    if StepsEdit.Value < 0 then
      StepsEdit.Value := 0;

    MainForm.BuildFractal(AxiomEdit.Text, NewFEdit.Text, NewXEdit.Text, NewYEdit.Text,
      NewZEdit.Text,
      NewBEdit.Text, PI * StrToInt(Angle1Edit.Text) / StrToInt(Angle2Edit.Text),
      PI * StrToInt(StartAngle1Edit.Text) / StrToInt(StartAngle2Edit.Text),
      StepsEdit.Value
    );
  except
    MessageBox(Handle, PChar(LangArray[6, CurLang]), PChar(LangArray[5, CurLang]), MB_ICONERROR);
  end;
end;

procedure TParamsForm.ForceBuild;
begin
  try
    StopFractalThreaded;

    if StepsEdit.Value < 0 then
      StepsEdit.Value := 0;

    MainForm.BuildFractal(AxiomEdit.Text, NewFEdit.Text, NewXEdit.Text, NewYEdit.Text,
      NewZEdit.Text,
      NewBEdit.Text, PI * StrToInt(Angle1Edit.Text) / StrToInt(Angle2Edit.Text),
      PI * StrToInt(StartAngle1Edit.Text) / StrToInt(StartAngle2Edit.Text),
      StepsEdit.Value
    );
  except
    MessageBox(Handle, PChar(LangArray[6, CurLang]), PChar(LangArray[5, CurLang]), MB_ICONERROR);
  end;
end;

procedure TParamsForm.MinusButtonClick(Sender: TObject);
begin
  StopFractalThreaded;
  StepsEdit.Value := StepsEdit.Value + 1;
  ForceBuild;
end;

procedure TParamsForm.PlusButtonClick(Sender: TObject);
begin
  StopFractalThreaded;
  if StepsEdit.Value > 0 then
    StepsEdit.Value := StepsEdit.Value - 1;
  ForceBuild;
end;

procedure TParamsForm.AddEntry(const Name,
      F, NewF, NewX, NewY, NewZ, NewB: String;
      Steps: Byte;
      Angle1, Angle2,
      StartAngle1, StartAngle2: Integer; DynamicWidth, DynamicColors: Boolean; const Colors: array of TColor);
var
  p: PCustomItem;
begin
  New(p);
  p.Name := Name;
  p.F := F;
  p.NewF := NewF;
  p.NewX := NewX;
  p.NewY := NewY;
  p.NewZ := NewZ;
  p.NewB := NewB;
  p.Steps := Steps;
  p.Angle1 := Angle1;
  p.Angle2 := Angle2;
  p.StartAngle1 := StartAngle1;
  p.StartAngle2 := StartAngle2;
  p.DynamicWidth := DynamicWidth;
  p.DynamicColors := DynamicColors;
  p.ColorCount := High(Colors) + 1;
  Move(Colors, p.Colors, p.ColorCount * 4);
  FList.Add(p);
  ReadyCombo.Items.Add(Name);
end;

procedure TParamsForm.ProcessEntry(i: Integer);
var
  p: PCustomItem;
  x: Integer;
begin
  p := FList.Items[i];
  NameEdit.Text := p.Name;
  AxiomEdit.Text := p.F;
  NewFEdit.Text := p.NewF;
  NewXEdit.Text := p.NewX;
  NewZEdit.Text := p.NewZ;
  NewYEdit.Text := p.NewY;
  NewBEdit.Text := p.NewB;
  StepsEdit.Value := p.Steps;
  Angle1Edit.Text := IntToStr(p.Angle1);
  Angle2Edit.Text := IntToStr(p.Angle2);
  StartAngle1Edit.Text := IntToStr(p.StartAngle1);
  StartAngle2Edit.Text := IntToStr(p.StartAngle2);
  DynamicWidthChk.Checked := p.DynamicWidth;
  ColorAsTreeChk.Checked := p.DynamicColors;
  FreeColorEdits;
  if p.ColorCount < 1 then
    AddColorEdit
  else
    for x := 0 to p.ColorCount - 1 do
      AddColorEdit(p.Colors[x]);
  SpinEdit1.Value := FColorList.Count;
end;

const
  Key = 'SOFTWARE\Coban\Fract';

function OpenKey(SubKey: String; var Handle: HKEY): Boolean;
begin
  Result := RegCreateKey(HKEY_CURRENT_USER, PChar(Key + SubKey), Handle) = ERROR_SUCCESS;
end;

function CloseKey(var Handle: HKey): Boolean;
begin
  Result := RegCloseKey(Handle) = ERROR_SUCCESS;
end;

function WriteOption(const Option: String; Value: Integer): Boolean;
var
  Handle: HKey;
begin
  Result := False;
  if not OpenKey('', Handle) then Exit;
  Result := (RegSetValueEx(Handle, PChar(Option), 0, REG_DWORD, @Value, SizeOf(Value)) = ERROR_SUCCESS);
  CloseKey(Handle);
end;

function ReadOption(const Option: String; var Res: Integer): Boolean;
var
  IntBuffer: Integer;
  DataType, BufSize: Integer;
  Handle: HKey;
begin
  Result := False;
  if not OpenKey('', Handle) then Exit;
  IntBuffer := 0;
  BufSize := SizeOf(IntBuffer);
  Result := (RegQueryValueEx(Handle, PChar(Option), nil, @DataType, @IntBuffer, @BufSize) = ERROR_SUCCESS);
  CloseKey(Handle);
  Res := IntBuffer;
end;


procedure TParamsForm.FormCreate(Sender: TObject);
var
  b: Integer;
begin
  if ReadOption('Lang', b) then CurLang := b else CurLang := 1;
  if CurLang > 1 then CurLang := 0;
  case CurLang of
    0: RussianItem.Click;
    1: EnglishItem.Click;
  end;

  EdTop := EdDefTop;
  EdLeft := EdDefLeft;

  FColorList := TList.Create;
  FList := TList.Create;
  AddColorEdit;

  AddEntry(LangArray[7, CurLang], 'F-F++F-F', 'F-F++F-F', '', '', '', '', 3, 1, 3, 0, 1, False, False, []);
  AddEntry(LangArray[8, CurLang], 'F-F++F-F', 'F-F++F-F', '', '', '', '', 3, 1, 3, 0, 1, False, False, [RGB(255, 85, 85), RGB(255, 128, 0), RGB(215, 215, 0), RGB(0, 240, 60), RGB(0, 170, 255), RGB(0, 115, 230), RGB(128, 128, 255)]);
  AddEntry(LangArray[9, CurLang], 'F++F++F', 'F-F++F-F', '', '', '', '', 2, 1, 3, 0, 1, False, False, [RGB(0, 115, 230)]);
  AddEntry(LangArray[10, CurLang], 'FX', 'F', 'X+YF+', '-FX-Y', '', '', 19, 1, 2, 0, 1, False, False, [RGB(255, 85, 85), RGB(255, 128, 0), RGB(215, 215, 0), RGB(0, 240, 60), RGB(0, 170, 255), RGB(0, 115, 230), RGB(128, 128, 255)]);
  AddEntry(LangArray[11, CurLang], 'XF', 'F', 'X+YF++YF-FX--FXFX-YF+', '-FX+YFYF++YF+FX--FX-Y', '', '', 4, 1, 3, -27, 24, False, False, [RGB(255, 255, 255), RGB(50, 50, 50)]);
  AddEntry(LangArray[12, CurLang], 'FXF--FF--FF', 'FF', '--FXF++FXF++FXF--', '-FX-Y', '', '', 6, 1, 3, 0, 1, False, False, [RGB(255, 85, 85), RGB(255, 128, 0), RGB(215, 215, 0), RGB(0, 240, 60), RGB(0, 170, 255), RGB(0, 115, 230), RGB(128, 128, 255)]);
  AddEntry(LangArray[13, CurLang], 'X', 'F', 'XFYFX+F+YFXFY-F-XFYFX', ' YFXFY-F-XFYFX+F+YFXFY', '', '', 4, 1, 2, 0, 1, False, False, [RGB(104, 95, 55), RGB(154, 95, 55), RGB(116, 50, 68)]);
  AddEntry(LangArray[14, CurLang], 'F+F+F+F', 'F+B-F-FFF+F+B-F', '', '', '', 'BBB', 3, 1, 2, 0, 1, False, False, []);
  AddEntry(LangArray[15, CurLang], 'F-F-F-F', 'FF-F-F-F-F-F+F', '', '', '', '', 5, 1, 2, 0, 1, False, False, [4300531, 4671486]);
  AddEntry(LangArray[16, CurLang], 'F-F-F-F', 'F[F]-F+F[--F]+F-F', '', '', '', '', 4, 1, 2, 0, 1, False, False, []);
  AddEntry(LangArray[17, CurLang], 'F', 'FF[-FF+F+FF+F][+FF+F+F+]', '', '', '', '', 4, 1, 8, -1, 3, True, True, [4290630, 5480306, 7060619, 2008587]);
  AddEntry(LangArray[18, CurLang], 'F', '-F[-F+F-F]+[+F-F-F]', '', '', '', '', 4, 1, 9, -1, 8, True, True, [16512, 24251, 30444, 2384091]);
  AddEntry(LangArray[19, CurLang], 'Z', 'F', 'XFF', 'Z', 'XF[--Y]F+Z', '', 16, 1, 16, -1, 2, False, False, [4227072, 3251496]);
  AddEntry(LangArray[20, CurLang], 'X', 'FF', 'F-[[X]+X]+F[+FX]-X', '', '', '', 7, 1, 11, -1, 2, False, True, [32768, 4227072, 113283, 3577902]);
  AddEntry(LangArray[21, CurLang], 'Y', '', 'X[-FFF][+FFF]FX', 'YFX[+Y][-Y]', '', '', 8, 1, 7, -5, 9, False, True, [16512, 32876, 4359168, 6010624, 6211207, 15428669, 9720548]);
  AddEntry(LangArray[22, CurLang], 'F', 'F[+F]F[-F][+F]', '', '', '', '', 7, 1, 9, -5, 9, False, True, [16512, 32876, 4359168, 6010624, 6211207, 6341320, 6542274]);

  ReadyCombo.ItemIndex := 0;
  ProcessEntry(0);

  ViewButton.Click;
end;

procedure TParamsForm.FormDestroy(Sender: TObject);
var
  i: Integer;
begin
  for i := 0 to FList.Count - 1 do
    Dispose(FList.Items[i]);
  FList.Free;
  FreeColorEdits;
  FColorList.Free;
end;

procedure TParamsForm.ReadyComboChange(Sender: TObject);
begin
  if ReadyCombo.ItemIndex >= 0 then
    ProcessEntry(ReadyCombo.ItemIndex);
end;

procedure TParamsForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  MainForm.Close;
end;

procedure TParamsForm.AddColorEdit;
var
  Image: TImage;
begin
  Image := TImage.Create(nil);
  Image.Visible := False;
  Image.Parent := GroupBox3;
  Image.Top := EdTop;
  Image.Left := EdLeft;
  Image.Width := EdWidth;
  Image.Height := EdHeight;
  Image.Visible := True;
  Image.Canvas.Brush.Color := Color;
  Image.Canvas.Rectangle(0, 0, 40, 20);
  Image.OnClick := OnImageClick;

  FColorList.Add(Image);

  Inc(EdLeft, EdWidth + 10);
  if EdLeft >= GroupBox3.Width - 10 then begin
    EdLeft := EdDefLeft;
    EdTop := EdTop + 30;
  end;
end;

procedure TParamsForm.FreeColorEdits;
var
  i: Integer;
begin
  EdTop := EdDefTop;
  EdLeft := EdDefLeft;
  for i := 0 to FColorList.Count - 1 do
    TObject(FColorList.Items[i]).Free;
  FColorList.Clear;
end;

function HexToInt(Value: String): LongWord;
const
  HexStr: String = '0123456789abcdef';
var
  i: Word;
begin
  Result := 0;
  if Value = '' then Exit;
  for i := 1 to Length(Value) do
    Inc(Result, (Pos(Value[i], HexStr) - 1) shl ((Length(Value) - i) shl 2));
end;

procedure TParamsForm.OnImageClick(Sender: TObject);
var
  Image: TImage;
begin
  Image := TImage(Sender);
  ColorDialog1.Color := Image.Canvas.Pixels[5, 5];
  if ColorDialog1.Execute then begin
    Image.Canvas.Brush.Color := ColorDialog1.Color;
    Image.Canvas.Rectangle(0, 0, 40, 20);
  end;
end;


procedure TParamsForm.SpinEdit1Change(Sender: TObject);
begin
  try
    if SpinEdit1.Text <> '' then begin
      if SpinEdit1.Value < 1 then
        SpinEdit1.Value := 1;
      if SpinEdit1.Value = 0 then
        FreeColorEdits;
      if SpinEdit1.Value > SpinEdit1.MaxValue then
        SpinEdit1.Value := SpinEdit1.MaxValue;
      while SpinEdit1.Value > FColorList.Count do
        AddColorEdit;
      while SpinEdit1.Value < FColorList.Count do begin
        TObject(FColorList.Items[FColorList.Count - 1]).Free;
        FColorList.Delete(FColorList.Count - 1);
        Dec(EdLeft, EdWidth + 10);
        if EdLeft < EdWidth + 10 then begin
          Dec(EdTop, 30);
          EdLeft := TEdit(FColorList.Items[FColorList.Count - 1]).Left + 10 + EdWidth;
        end;
      end;
    end;
  except
    FreeColorEdits;
  end;
end;

procedure TParamsForm.SaveBmpItemClick(Sender: TObject);
begin
  MainForm.bmp1.Click;
end;

procedure TParamsForm.SaveJpgItemClick(Sender: TObject);
begin
  MainForm.jpeg1.Click;
end;

procedure TParamsForm.SaveIntItemClick(Sender: TObject);
begin
  MainForm.int1.Click;
end;

procedure TParamsForm.LoadItemClick(Sender: TObject);
begin
  MainForm.LoadItem.Click;
end;

procedure TParamsForm.CloseItemClick(Sender: TObject);
begin
  Close;
end;

procedure TParamsForm.RussianItemClick(Sender: TObject);
var
  i, p: Integer;
begin
  CurLang := 0;
  WriteOption('Lang', CurLang);
  Label1.Caption := 'Название фрактала:';
  Label2.Caption := 'F (аксиома):';
  Label4.Caption := 'Готовые фракталы:';
  Label8.Caption := 'Кол-во шагов:';
  Label9.Caption := 'Угол:';
  Label12.Caption := 'Нач. угол:';
  ViewButton.Caption := LangArray[1, CurLang];
  PageControl1.Pages[0].Caption := 'Данные';
  PageControl1.Pages[1].Caption := 'Дополнительно';
  GroupBox3.Caption := 'Цвета';
  Label16.Caption := 'Количество цветов:';
  ColorAsTreeChk.Caption := 'Красить отдельно каждую ветвь';
  GroupBox4.Caption := 'Другое';
  DynamicWidthChk.Caption := 'Изменять толщину ствола';
  DoUpdateChk.Caption := 'Обновлять рисунок при построении';
  ParamsForm.Caption := 'Параметры';
  N1.Caption := 'Файл';
  N2.Caption := 'Язык';
  N3.Caption := 'Помощь';
  SaveBmpItem.Caption := 'Сохранить как .bmp';
  SaveJpgItem.Caption := 'Сохранить как .jpg';
  SaveIntItem.Caption := 'Сохранить во внутреннем формате';
  LoadItem.Caption := 'Загрузить фрактал из файла';
  CloseItem.Caption := 'Выход';
  MainForm.Caption := 'Изображение фрактала (C) Alex Demchenko';
  MainForm.BuildItem.Caption := 'Построить фрактал';
  MainForm.bmp1.Caption := SaveBmpItem.Caption;
  MainForm.jpeg1.Caption := SaveJpgItem.Caption;
  MainForm.int1.Caption := SaveIntItem.Caption;
  MainForm.LoadItem.Caption := LoadItem.Caption;
  MainForm.N1.Caption := 'На весь экран';
  RussianItem.Caption := 'Русский';
  EnglishItem.Caption := 'Английский';
  AboutItem.Caption := 'О программе';
  p := ReadyCombo.ItemIndex;
  for i := 0 to ReadyCombo.Items.Count - 1 do
    ReadyCombo.Items[i] := LangArray[i+7, CurLang];
  ReadyCombo.ItemIndex := p;
  MainForm.Region.Hint := 'Кликните два раза, чтобы вернуться обратно';
  NameEdit.Hint := 'Введите название фрактала';
  AxiomEdit.Hint := 'Исходная функция (аксиома)';
  NewFEdit.Hint := 'Параметр F';
  NewXEdit.Hint := 'Параметр X';
  NewYEdit.Hint := 'Параметр Y';
  NewZEdit.Hint := 'Параметр Z';
  NewBEdit.Hint := 'Параметр B';
  StepsEdit.Hint := 'Количество шагов/итераций';
  ReadyCombo.Hint := 'Посмотреть готовый фрактал';
  PlusButton.Hint := 'Уменьшить количество шагов';
  MinusButton.Hint := 'Увеличить количество шагов';
  ViewButton.Hint := 'Построить фрактал';
  ColorAsTreeChk.Hint := 'Применимо только для фракталов содержащих [, ] операторы';
  DynamicWidthChk.Hint := ColorAsTreeChk.Hint;
  DoUpdateChk.Hint := 'Замедляет работу';
end;

procedure TParamsForm.EnglishItemClick(Sender: TObject);
var
  i, p: Integer;
begin
  CurLang := 1;
  WriteOption('Lang', CurLang);
  Label1.Caption := 'Fractal name:';
  Label2.Caption := 'F (axiom):';
  Label4.Caption := 'Complete fractals:';
  Label8.Caption := 'Number of steps:';
  Label9.Caption := 'Angle:';
  Label12.Caption := 'Def. angle:';
  ViewButton.Caption := LangArray[1, CurLang];
  PageControl1.Pages[0].Caption := 'Data';
  PageControl1.Pages[1].Caption := 'Additional';
  GroupBox3.Caption := 'Colors';
  Label16.Caption := 'Number of colors:';
  ColorAsTreeChk.Caption := 'Color each branch separately';
  GroupBox4.Caption := 'Other';
  DynamicWidthChk.Caption := 'Dynamic line width';
  DoUpdateChk.Caption := 'Update picture while drawing';
  ParamsForm.Caption := 'Params';
  N1.Caption := 'File';
  N2.Caption := 'Language';
  N3.Caption := 'Help';
  SaveBmpItem.Caption := 'Save as .bmp';
  SaveJpgItem.Caption := 'Save as .jpg';
  SaveIntItem.Caption := 'Save in internal format';
  LoadItem.Caption := 'Load fractal from file';
  CloseItem.Caption := 'Exit';
  MainForm.Caption := 'Image of actual fractal (C) Alex Demchenko';
  MainForm.BuildItem.Caption := 'Build fractal';
  MainForm.bmp1.Caption := SaveBmpItem.Caption;
  MainForm.jpeg1.Caption := SaveJpgItem.Caption;
  MainForm.int1.Caption := SaveIntItem.Caption;
  MainForm.LoadItem.Caption := LoadItem.Caption;
  MainForm.N1.Caption := 'Full screen';
  RussianItem.Caption := 'Russian';
  EnglishItem.Caption := 'English';
  AboutItem.Caption := 'About';
  p := ReadyCombo.ItemIndex;
  for i := 0 to ReadyCombo.Items.Count - 1 do
    ReadyCombo.Items[i] := LangArray[i+7, CurLang];
  ReadyCombo.ItemIndex := p;
  MainForm.Region.Hint := 'Double-click to return';
  NameEdit.Hint := 'Enter the name';
  AxiomEdit.Hint := 'Source function (axiom)';
  NewFEdit.Hint := 'Parameter F';
  NewXEdit.Hint := 'Parameter X';
  NewYEdit.Hint := 'Parameter Y';
  NewZEdit.Hint := 'Parameter Z';
  NewBEdit.Hint := 'Parameter B';
  StepsEdit.Hint := 'Number of steps/iterations';
  ReadyCombo.Hint := 'View complete fractal';
  PlusButton.Hint := 'Decrease number of steps';
  MinusButton.Hint := 'Increase number of steps';
  ViewButton.Hint := 'Build fractal';
  ColorAsTreeChk.Hint := 'Works with fractals which contain [,] operators only';
  DynamicWidthChk.Hint := ColorAsTreeChk.Hint;
  DoUpdateChk.Hint := 'Slows down the execution';
end;

procedure TParamsForm.HelpItemClick(Sender: TObject);
begin
  ShellExecute(0, 'open', 'help.chm', nil, nil, SW_SHOW);
end;

procedure TParamsForm.AboutItemClick(Sender: TObject);
begin
  MessageBox(0, 'Fractal Generator'#13#10'----------------------------'#13#10'(c)coban2k'#13#10'http://www.cobans.net'#0, 'About', 0);
end;

end.
