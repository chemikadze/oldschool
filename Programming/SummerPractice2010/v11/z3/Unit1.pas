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
	If OpenDialog1.Execute then 	//���� � ������� ������ ����
  begin
    Label1.Visible := false;
    Memo1.Clear;	//�������� ���� ������
    AssignFile(F,OpenDialog1.FileName);	//������� ���� � F
    {$I-}				//��������� ��������
    reset(F);			//������� ����
    {$I+}				//�������� ��������
    If IOResult = 0 then	//���� ������ ������
    begin
      Form1.Caption := OpenDialog1.FileName;
			{� ��������� ���� ���������� ��� ��������� �����}
			W := 0;		//������� �����
			If CheckBox1.Checked then 	//���� ������������ ����
			begin
				while Not EOF(F) do	//���� �� ����� �����
				begin
          Memo1.Lines.Add('');	//�������� ������ ������
          While Not EOLn(F) do	//���� �� ����� ������
          begin
            read(F,C);           	//������� ��������� ������
            Memo1.Lines[W]:=Memo1.Lines[W]+C;
            {�������� � ������ ������ ��������� ������}
          end;
          Inc(W);	//��������� ������� �����
          readln(F);
					{������� � ���������� ����� ������}
        end;
 			end
			else  			//���� ����������� �����
			begin
				Memo1.Lines.LoadFromFile(OpenDialog1.FileName);
				{������� ����}
			end;
			CloseFile(F);	//������� ����
      Label1.Caption := '���� �������';
    end
		else				//���� �� �������
      ShowMessage('������ �������� ����� '+OpenDialog1.FileName);
			{������ ��������� �� ������}
  	end;					//����� ������ � ������
end;

procedure TForm1.N2Click(Sender: TObject);
var f: textfile;
    res:integer;
begin
  If SaveDialog1.Execute then
  begin
    AssignFile(F,SaveDialog1.FileName);	//������� ���� � F
    {$I-}				//��������� ��������
    reset(F);			//������� ����
    res := IOResult;
    {$I+}				//�������� ��������
    If (res <> 0)                 //���� �� ������ (�� ����������)
      or ((res = 0) and (MessageDlg('���� ��� ����������. ������������?', mtWarning, [mbYes, mbCancel], -1) = mrYes))
    then	//��� ���� ������������ �������� ������������
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

procedure TForm1.Button1Click(Sender: TObject);
var i, j: integer;
    wn: integer;   // ����� �����
    line: string;
begin
  for i:=0 to Memo1.Lines.Count do
  begin
    wn := 1;
    j:=1;
    while (j <= length(Memo1.Lines[i])) do // ������������ ������
    begin
      if ((Memo1.Lines[i][j] <> ' '))  // ������� ��� ����� - ��� ��� ��� �� ������
      then
      begin
        if (wn mod 2 = 1) then     // ���� �������� �����
        begin
          while (j <= length(Memo1.Lines[i])) and (Memo1.Lines[i][j] <> ' ') do // ���� ��� �����
          begin
            line := line + Memo1.Lines[i][j]; // ��������� � ���������� ������ ������
            inc(j);
          end;
        end
        else
        begin // ������ ����������
          while (j <= length(Memo1.Lines[i])) and (Memo1.Lines[i][j] <> ' ') do
            inc(j);
        end;
        inc(wn);
      end
      else
      begin
        line := line + Memo1.Lines[i][j]; // ��������� ������
        inc(j);
      end;
    end;
    Memo1.Lines[i] := line;  // �������� ������ ����������
  end;
end;

end.
