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
    Edit4: TEdit;
    Edit5: TEdit;
    Label4: TLabel;
    UpDown2: TUpDown;
    UpDown3: TUpDown;
    Label5: TLabel;
    Button2: TButton;
    Label6: TLabel;
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
var query: array [1..100] of integer; // ������� ������� ����� ���������
    position, startI: integer; // ������� ������� � ����� � ������ �������� � �-���� ������
    i, j, b: integer; // �������� � ����� ��� ������ ����������
    time, timeMove: integer; // ����� (�����), ����� ��� ����������� �� 1
    cylCount: integer; // ���-�� �������(���������)
    queryCount: integer; // ���-�� ��������
    outPos: integer;  // ������� � ������
begin
  outPos := 0;  // ������������� ����������
  time := 0;
  position := UpDown2.Position;
  cylCount := UpDown3.Position;
  queryCount := UpDown1.Position;
  timeMove := StrToInt(Edit2.Text);
  for i:=1 to queryCount do    // ������ ��������
    query[i] := StrToInt(StringGrid1.Cells[i-1, 0]);
  if (Sender = Button1) then   // ���� ������ �� ������ "������"
  begin
   // <-
    for i:=queryCount downto 2 do  // ���������� ��������� �� ��������
      for j:=1 to i-1 do
        if query[j]<query[j+1] then
        begin
          b := query[j];
          query[j] := query[j+1];
          query[j+1] := b;
        end;
    startI := queryCount;         // ������� ��������� ������� � ������
    for i:=1 to queryCount do
      if query[i]<=position then
      begin
        startI := i;
        break;
      end;
    end
  else
  begin // ->                // ����� ������ �� ������ "������"
    for i:=queryCount downto 2 do  // ����������� �������� �� �����������
      for j:=1 to i-1 do
        if query[j]>query[j+1] then
        begin
          b := query[j];
          query[j] := query[j+1];
          query[j+1] := b;
        end; 
    startI := queryCount;       // ������� ��������� ������� � ������
    for i:=1 to queryCount do
      if query[i]>=position then
      begin
        startI := i;
        break;
      end;
  end;

  // ������� ��������� ������� �������
  StringGrid2.Cells[outPos, 0] := IntToStr(position);
  inc(outPos);

  // �������� �� "��������" ��������
  for i:=startI to queryCount do
  begin
    time := time + timeMove*abs(position-query[i]);
    position := query[i];
    StringGrid2.Cells[outPos, 0] := IntToStr(position);
    inc(outPos);
  end;

  // ���� ���� ������� �� "�� ����", �.�. ����� ��������� ��������
  if (startI <> 1) then
  begin
    // ���� ��������� � ������� ����������
    if (sender = Button1) then
    begin
      // ������� �� ������ ����
      time := time + timeMove*position;
      position := 0;
      // ���������� �����������
      StringGrid2.Cells[outPos, 0] := IntToStr(position);
      inc(outPos);
      // ��������� �� ������
      time := time + cylCount-1;
      position := cylCount-1;
    end
    else // �����
    begin
      // ������� �� ������� ����
      time := time + timeMove*abs(cylCount-position-1);
      position := CylCount-1;   
      // ���������� �����������
      StringGrid2.Cells[outPos, 0] := IntToStr(position);
      inc(outPos);
      // ��������� �� �����
      time := time + timeMove*abs(position);
      position := 0;
    end;
    // ���������� �����������
    StringGrid2.Cells[outPos, 0] := IntToStr(position);
    inc(outPos);
  end;

  // �����������, ����������
  for i:=1 to StartI-1 do
  begin
    time := time + timeMove*abs(position-query[i]);
    position := query[i];
    StringGrid2.Cells[outPos, 0] := IntToStr(position);
    inc(outPos);
  end;
  // ������� ����� �����������
  Label6.Caption := '����� �����������: '+IntToStr(time) + ' ��';
  StringGrid2.ColCount := outPos;
end;

end.
