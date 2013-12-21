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
    Edit2: TEdit;
    Label3: TLabel;
    UpDown2: TUpDown;
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


function min(x, y: integer):integer;
begin
  if (x > y) then
    min := y
  else
    min := x;
end;

procedure TForm1.Button1Click(Sender: TObject);
var i, time: integer; // ������� ������ � ������� ������
    active: array[1..100] of boolean; // ����������
    active_count: integer; // ���-�� ��������
    aktivny: integer;      // ����� �������������� �������� (�������� �������)
    kvant, kvant_size: integer;  // �����

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
    active[i] := false;
  end;
  kvant_size := UpDown2.position;

  time:=0;
  active_count := 0;
  ostalos := N;
  vipoln := 0;
  ozhid := 0;
  aktivny := 0;
  kvant := 0;
  while (ostalos > 0) do
  begin
    // ������� ������� �������
    for i:=1 to N do
      StringGrid2.Cells[time+1, i] := '';

    // ��������� � �������� ��������� ����� ��������
    for i:=1 to N do
      if (process[i, 2]=time) then
      begin
        inc(active_count);
        active[i]:=true;
      end;

    // ���� ���� �������� ��������
    if (active_count > 0) then
    begin
      if (kvant = 0) then
      begin
        // ���� ������� ���������� � ����������
        if (aktivny > 0) and (process[aktivny, 1] = 0) then
        begin
          // ������� ������� ����������
          active[aktivny] := false;
          dec(active_count);
          // ��������� ������� ���������� ���������
          dec(ostalos);
        end;
        // ���� ������ �������� ���
        if (active_count = 0) then
            // �������� 0 - ������ ��� ��������� ��������
            aktivny := 0
        else
        begin
          // ��������� � ����������
          repeat
            // mod - ������� ������� ������
            // ���������� ���� "�� �����" ��������� �������� �������
            aktivny := aktivny mod N + 1;
          // �������  ���������� �����
          until (active[aktivny]);
          // ���� CPU Burst ������ ����� ������, ��
          // ���������� ���������� ����� ����� CPU Burst
          kvant := min(kvant_size, process[aktivny, 1]);
        end;
      end;
    end;

    // ������������ ������������� �������
    if (aktivny > 0) then
    begin
      // ����������� ������� ������� ����������
      inc(vipoln);
      // ��������� CPU Burst � �����
      dec(process[aktivny,1]);
      dec(kvant);
      // ����� � ������� ������������� �������
      StringGrid2.Cells[time+1, aktivny] := '�';
    end;

    // ������������ �������� � ��������� ��������
    for i:=1 to N do
      // ���� ������� � ��������� ��������
      if (active[i]) and (aktivny <> i) then
      begin
        // ����������� ������� ������� ����������
        inc(vipoln);
        // ����� � �������
        StringGrid2.Cells[time+1, i] := '�';
        // ����������� ����� ��������
        inc(ozhid);
      end;
    // ����� ��������� �������
    StringGrid2.Cells[time+1, 0] := IntToStr(time); // ����� �������
    inc(time); // ��������� �����
  end;
  StringGrid2.ColCount := time;
  Label2.Caption := '������� ����� ����������: ' + FloatToStr(vipoln/N) + #10#13 +
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
  StringGrid1.Cells[0, 0] := '�';
  StringGrid1.Cells[1, 0] := 'CPU Burst';
  StringGrid1.Cells[2, 0] := '��������';
  // ��������� ������������ ���������
  for i:=1 to N do
    StringGrid1.Cells[0, i] := IntToStr(i);
end;

end.
