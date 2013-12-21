unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    Button1: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    UpDown1: TUpDown;
    Edit2: TEdit;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    procedure UpDown1ChangingEx(Sender: TObject; var AllowChange: Boolean;
      NewValue: Smallint; Direction: TUpDownDirection);
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

procedure TForm1.UpDown1ChangingEx(Sender: TObject;
  var AllowChange: Boolean; NewValue: Smallint;
  Direction: TUpDownDirection);
begin
  StringGrid1.ColCount := NewValue;
  StringGrid2.ColCount := NewValue;
end;

procedure TForm1.Button1Click(Sender: TObject);
var i: integer;   // �������
    time, dt: integer; // ����� ������, ����� ������������ ����� ���������
    position, next: integer; // ���. �������, ���������
    count: integer;  // ���-�� ��������
begin
  dt := StrToInt(Edit2.Text); // ������ �
  time := 0;                  // ��������� ����������
  count := UpDown1.Position;
  position := StrToInt(StringGrid1.Cells[0, 0]);
  StringGrid2.Cells[0,0] := IntToStr(position); // ���������� ���. ������� � �����
  for i:=1 to count-1 do  // ��������������� ��������� �� ���� ��������
  begin
    next := StrToInt(StringGrid1.Cells[i, 0]); // ������ ������
    time := time + abs(position-next); // ����������� ������� �������
    position := next;  // ���������
    StringGrid2.Cells[i, 0] := IntToStr(position); // ���������� � �����
  end;
  time := time * dt; // ��������� �� ����� �������� ����� ���������
  Label4.Caption := '����� ����������� ������� �������� �����: ' + IntToStr(time) + ' ��.';
end;

end.
