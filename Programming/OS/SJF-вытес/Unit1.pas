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
var i, vremya: integer; // ������� � ������� ������
    act: array[1..100] of integer; // ��������
    actCnt: integer; // ���-�� ��������

    // ��� ������ ���������: CPUburst, ���������, ���������
    processes: array[1..100, 1..3] of integer;  // ** �������� 1..3 �� 1..2 **

    ostalos: integer; // �������� ��������� ���������
    active: integer; // ������ ��������� � act

    exectime: integer;   // ����� ����������
    wait: integer;   // ����� ��������
begin
  // ������ ������
  for i:=1 to N do
  begin
    processes[i,1] := StrToInt(StringGrid1.Cells[1, i]);
    processes[i,2] := StrToInt(StringGrid1.Cells[2, i]);
    processes[i,3] := StrToInt(StringGrid1.Cells[3, i]); //  ** ������ ** 
  end;

  vremya:=0;
  actCnt := 0;
  ostalos := N;
  active := -1;
  exectime := 0;
  wait := 0;
  while (ostalos > 0) do
  begin
    // ��������� ����� ��������
    for i:=1 to N do
      if (processes[i, 2]=vremya) then
      begin
        inc(actCnt);
        act[actCnt]:=i;
      end;
    // ������������
    //  ���� ���� �������� ��������
    if (actCnt>0) then
    begin
      // ���� ������� ����������
      // ������� ���, ��� ��������
      if ((active <> -1) and (processes[act[active], 1]=0)) then
      begin
        for i:=active to actCnt-1 do
          act[i] := act[i+1];
        dec(actCnt);
        dec(ostalos);
      end;
      // ������� ���������� �� ��������, ���������� ��� ��� �������������
      active := 1;
      for i:=2 to actCnt do
        if (processes[act[active],3] > processes[act[i],3]) then // ** �������� 3 �� 1 ** 
          active:=i;
    end;
    // ������� ������� �������
    for i:=1 to N do
      StringGrid2.Cells[vremya+1, i] := '';
    for i:=1 to actCnt do
    begin
      exectime := exectime+1;
      // ���� ��� ������������� �������
      if (i=active) then
      begin
        StringGrid2.Cells[vremya+1, act[i]] := '�';
        dec(processes[act[active],1]); // �������� ����������, ��������� CPUburst
      end
      else // ����� ������� �������
      begin
        StringGrid2.Cells[vremya+1, act[i]] := '�';
        wait := wait+1;
      end;
    end; 
    StringGrid2.Cells[vremya+1, 0] := IntToStr(vremya); // ����� �������
    inc(vremya); // ��������� �����
  end;
  StringGrid2.ColCount := vremya;
  Label2.Caption := '������� ����� ����������: ' + FloatToStr(exectime/N) + #10#13 +
                    '������� ����� ��������: ' + FloatToStr(wait/N);
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
  StringGrid1.Cells[3, 0] := '���������'; // ** ������ **
  // ��������� ������������ ���������
  for i:=1 to N do
    StringGrid1.Cells[0, i] := IntToStr(i);
end;

end.
