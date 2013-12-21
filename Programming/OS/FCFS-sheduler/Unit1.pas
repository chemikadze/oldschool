unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    Button1: TButton;
    Edit1: TEdit;
    UpDown1: TUpDown;
    Label1: TLabel;
    StringGrid2: TStringGrid;
    Label2: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  N: integer;

implementation

{$R *.dfm}


procedure TForm1.Button1Click(Sender: TObject);
var i, time: integer; // ������� � ������� ������
    active: array[1..100] of integer; // ��������
    active_count: integer; // ���-�� ��������

    // ��� ������ ���������, CPUburst � ���������
    process: array[1..100, 1..2] of integer;

    ostalos: integer; // �������� ��������� ���������

    vipoln: integer;   // ����� ����������
    ozhid: integer;   // ����� ��������
begin
  // ������ ������
  for i:=1 to N do
  begin
    process[i,1] := StrToInt(StringGrid1.Cells[1, i]);
    process[i,2] := StrToInt(StringGrid1.Cells[2, i]);
  end;

  time:=0;
  active_count := 0;
  ostalos := N;
  vipoln := 0;
  ozhid := 0;
  while (ostalos > 0) do
  begin
    // ������� ������� �������
    for i:=1 to N do
      StringGrid2.Cells[time+1, i] := '';

    // ��������� � ��������� ����� ��������
    for i:=1 to N do
      if (process[i, 2]=time) then
      begin
        inc(active_count);
        active[active_count]:=i;
      end;

    // ���� ���� �������� ��������
    if (active_count > 0) then
    begin
      // ���� ������� ������� ����������
      if (process[active[1], 1] = 0) then
      begin
        // ������� ���
        for i:=1 to active_count-1 do
          active[i] := active[i+1];
        dec(active_count);
        // ��������� ������� ���������� ���������
        dec(ostalos);
      end;
      // ������������ ������������� �������
      if (active_count > 0) then
      begin
        dec(process[active[1],1]);
        StringGrid2.Cells[time+1, active[1]] := '�';
      end;
    end;

    // ����������� ������� ������� ���������� �� ���-�� ���� ���������
    inc(vipoln, active_count);

    // ������������ �������� � ��������� ��������
    for i:=2 to active_count do
    begin
      StringGrid2.Cells[time+1, active[i]] := '�';
      inc(ozhid);
    end;
    StringGrid2.Cells[time+1, 0] := IntToStr(time); // ����� �������
    inc(time); // ��������� �����
  end;
  StringGrid2.ColCount := time;
  Label2.Caption := '������� ����� ����������: ' + FloatToStr(vipoln/N) +
                    ' ������� ����� ��������: ' + FloatToStr(ozhid/N);
end;

procedure TForm1.Edit1Change(Sender: TObject);
var i: integer;
begin
  // �������� ������ ������
  N := UpDown1.Position;
  StringGrid1.RowCount := N + 1;
  StringGrid2.RowCount := N + 1;
  // ��������� ������������ ��������� ������
  for i:=1 to N do
  begin
    StringGrid1.Cells[0, i] := IntToStr(i);
    StringGrid2.Cells[0, i] := StringGrid1.Cells[0, i];
  end;
end;


procedure TForm1.FormCreate(Sender: TObject);
var i: Integer;
begin
  N := UpDown1.Position;
  // ��������� �������������� ���������
  StringGrid1.Cells[0, 0] := '�����';
  StringGrid1.Cells[1, 0] := 'CPU Burst';
  StringGrid1.Cells[2, 0] := '����� ���������';
  // ��������� ������������ ���������
  for i:=1 to N do
    StringGrid1.Cells[0, i] := IntToStr(i);
end;

end.
