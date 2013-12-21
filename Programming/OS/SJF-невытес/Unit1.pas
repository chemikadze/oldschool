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

procedure TForm1.FormCreate(Sender: TObject);
var i: Integer;
begin
  N := UpDown1.Position;
  // ��������� �������������� ���������
  StringGrid1.Cells[0, 0] := '�����';
  StringGrid1.Cells[1, 0] := 'CPU Burst';
  StringGrid1.Cells[2, 0] := '����� ���������';
  StringGrid1.Cells[3, 0] := '���������';
  // ��������� ������������ ���������
  for i:=1 to N do
    StringGrid1.Cells[0, i] := IntToStr(i);
end;

procedure TForm1.Button1Click(Sender: TObject);
var i, t: integer; // ������� � ������� ������
    a: array[1..100] of integer; // ��������
    aC: integer; // ���-�� ��������

    // ��� ������ ���������, CPUburst � ���������
    p: array[1..100, 1..3] of integer;

    left: integer; // �������� ��������� ���������
    active: integer; // ������ ��������� � A

    eT: real;   // ����� ����������
    wT: real;   // ����� ��������
begin
  // ������ ������
  for i:=1 to N do
  begin
    try
      p[i,1] := StrToInt(StringGrid1.Cells[1, i]);
      p[i,2] := StrToInt(StringGrid1.Cells[2, i]); 
      p[i,3] := StrToInt(StringGrid1.Cells[3, i]);
    except
      ShowMessage('������������ ������!');
      exit;
    end;
  end;

  t:=0;
  aC := 0;
  left := N;
  active := -1;
  eT := 0;
  wT := 0;
  while (left > 0) do
  begin
    // ��������� ����� ��������
    for i:=1 to N do
      if (p[i, 2]=t) then
      begin
        inc(aC);
        a[aC]:=i;
      end;
    // ������������
    //  ���� �������� ��� �� ����������� ��� ������� ���������� � ��� ���� ����
    //  ���� �������� ��������
    if (((active = -1) or (p[a[active],1] = 0)) and (aC>0)) then
    begin
      // ���� ������� ����������
      // ������� ���, ��� ��������
      if (active <> -1) then
      begin
        for i:=active to aC-1 do
          a[i] := a[i+1];
        dec(aC);
        dec(left);
      end;
      // ������� ���������� ��������� �� ��������, ���������� ��� ��� �������������
      active := 1;
      for i:=2 to aC do
        if (p[a[active],3] > p[a[i],3]) then
          active:=i;
    end;
    // ������� ������� �������
    for i:=1 to N do
      StringGrid2.Cells[t+1, i] := '';
    for i:=1 to aC do
    begin
      eT := eT+1;
      // ���� ��� ������������� �������
      if (i=active) then
      begin
        StringGrid2.Cells[t+1, a[i]] := '�';
        dec(p[a[active],1]); // �������� ����������, ��������� CPUburst
      end
      else // ����� ������� �������
      begin
        StringGrid2.Cells[t+1, a[i]] := '�';
        wT := wT+1;
      end;
      StringGrid2.Cells[t+1, 0] := IntToStr(t); // ����� �������
    end;
    inc(t); // ��������� �����
  end;
  StringGrid2.ColCount := t;
  Label2.Caption := '������� ����� ����������: ' + FloatToStr(eT/N) + #10#13 +
                    '������� ����� ��������: ' + FloatToStr(wT/N);
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

end.
