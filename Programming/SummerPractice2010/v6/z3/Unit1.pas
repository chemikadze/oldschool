unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Menus;

type
  TForm1 = class(TForm)
    MainMenu1: TMainMenu;
    F1: TMenuItem;
    N1: TMenuItem;
    N2: TMenuItem;
    N3: TMenuItem;
    OpenDialog1: TOpenDialog;
    SaveDialog1: TSaveDialog;
    Memo1: TMemo;
    Button1: TButton;
    CheckBox1: TCheckBox;
    Label1: TLabel;
    procedure N3Click(Sender: TObject);
    procedure N1Click(Sender: TObject);
    procedure N2Click(Sender: TObject);
    procedure Memo1KeyPress(Sender: TObject; var Key: Char);
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.N3Click(Sender: TObject);
begin
  Close;
end;

procedure TForm1.N1Click(Sender: TObject);
var f: textfile;
    w: integer;
    c: char;
begin
	If OpenDialog1.Execute then 	//Если в диалоге выбран файл
  begin
    Label1.Visible := false;
    Memo1.Clear;	//Очистить поле вывода
    AssignFile(F,OpenDialog1.FileName);	//Связать файл с F
    {$I-}				//Отключить проверку
    reset(F);			//Открыть файл
    {$I+}				//Включить проверку
    If IOResult = 0 then	//Файл открыт удачно
    begin
      Form1.Caption := OpenDialog1.FileName;
			{В заголовке окна отобразить имя открытого файла}
			W := 0;		//Счетчик строк
			If CheckBox1.Checked then 	//Если посимвольный ввод
			begin
				while Not EOF(F) do	//Пока не конец файла
				begin
          Memo1.Lines.Add('');	//Добавить пустую строку
          While Not EOLn(F) do	//Пока не конец строки
          begin
            read(F,C);           	//Считать очередной символ
            Memo1.Lines[W]:=Memo1.Lines[W]+C;
            {Добавить к пустой строке считанный символ}
          end;
          Inc(W);	//Увеличить счетчик строк
          readln(F);
					{Перейти к считыванию новой строки}
        end;
 			end
			else  			//Файл считывается сразу
			begin
				Memo1.Lines.LoadFromFile(OpenDialog1.FileName);
				{Считать файл}
			end;
			CloseFile(F);	//Закрыть файл
      Label1.Caption := 'Текс изменен';
    end
		else				//Файл не открыть
      ShowMessage('Ошибка открытия файла '+OpenDialog1.FileName);
			{Выдать сообщение об ошибке}
  	end;					//Конец работы с файлом
end;

procedure TForm1.N2Click(Sender: TObject);
var f: textfile;
    res:integer;
begin
  If SaveDialog1.Execute then
  begin
    AssignFile(F,SaveDialog1.FileName);	//Связать файл с F
    {$I-}				//Отключить проверку
    reset(F);			//Открыть файл
    res := IOResult;
    {$I+}				//Включить проверку
    If (res <> 0)                 //Файл не открыт (не существует)
      or ((res = 0) and (MessageDlg('Файл уже существует. Перезаписать?', mtWarning, [mbYes, mbCancel], -1) = mrYes))
    then	//или если пользователь согласен перезаписать
    begin
      if (res = 0) then
        CloseFile(F);
      Memo1.Lines.SaveToFile(SaveDialog1.FileName);
      Form1.Caption := SaveDialog1.FileName;
      Label1.Visible := false;
    end;
  end;
end;

procedure TForm1.Memo1KeyPress(Sender: TObject; var Key: Char);
begin
  Label1.Visible := true;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  Label1.Visible := false;
end;

// функция для поиска буквы в строке
function findLetters(c: char; const a: string): integer;
var i: integer;
begin
  for i:=1 to length(a) do
    if (a[i] = c) then
    begin
      findLetters := 1;
      exit;
    end;
  findLetters := 0;
end;

// ищет в русских словах
procedure TForm1.Button1Click(Sender: TObject);
const glas = 'аеёиоуыэюя';
      soglas = 'бвгджзйклмнпрстфхцчшщ'; // Ъ и Ь за согласные не считаем
var i, j: integer; // счетчики циклов
    g, s: integer; // счетчик гласных и согласных в слове
    d, md: real;   // соотнощения для текущего слова и для самого большого
    word, mword: string;
begin
  md := 0;
  for i:=0 to Memo1.Lines.Count-1 do
  begin
    j:=1;
    while (j<length(Memo1.Lines[i])) do
    begin
      if ((Memo1.Lines[i][j]>='А') and (Memo1.Lines[i][j]<='Я')) or
         ((Memo1.Lines[i][j]>='а') and (Memo1.Lines[i][j]<='я'))
      then
      begin
        s:=0; g:=0;
        word:='';
        while (Memo1.Lines[i][j] <> ' ') and (j <= length(Memo1.Lines[i])) do
        begin
          word := word + Memo1.Lines[i][j];
          g := g + findLetters(Memo1.Lines[i][j], glas);
          s := s + findLetters(Memo1.Lines[i][j], soglas);
          inc(j);
        end;
        if (g <> 0) then // нет деления на 0
        begin
          d := s/g;
          if (d>md) then
          begin
            md:=d;
            mword:=word;
          end;
        end;
      end;
      inc(j);
    end;
  end;
  ShowMessage('Слово с макс. соотношением согласные/гласные '+FloatToStr(md)+
              ': ' + mword);
end;

end.
