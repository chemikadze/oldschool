unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    Edit1: TEdit;
    Edit2: TEdit;
    UpDown1: TUpDown;
    UpDown2: TUpDown;
    Label1: TLabel;
    Label2: TLabel;
    Edit3: TEdit;
    Label3: TLabel;
    UpDown3: TUpDown;
    Button1: TButton;
    StringGrid2: TStringGrid;
    Label4: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Edit2Change(Sender: TObject);
    procedure Edit3Change(Sender: TObject);
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

procedure TForm1.FormCreate(Sender: TObject);
var i: integer;
begin
  for i:=1 to UpDown2.Position do
  begin
    StringGrid1.Cells[i-1, 0] := IntToStr(i);
  end;
end;

procedure TForm1.Edit2Change(Sender: TObject);
var i: integer;
begin
  StringGrid1.ColCount := UpDown2.Position;
  StringGrid2.ColCount := UpDown2.Position;
  for i:=1 to UpDown2.Position do
  begin
    StringGrid1.Cells[i-1, 0] := IntToStr(i);
  end;
end;

procedure TForm1.Edit3Change(Sender: TObject);
begin
  StringGrid2.RowCount := UpDown3.Position + 2;
end;

procedure TForm1.Button1Click(Sender: TObject);
var queryN: integer;  // ���-�� ��������
    query: integer;   // ������� ������
    pagesN: integer;  // ���-�� �������
    activeN: integer; // ����. ���-�� �������� ������� (�-��� � ������)
    active: array [0..100] of integer; // ������ �������� �������
    pages: array [0..100] of integer;  // ���-�� ��������� � ���������
    i, j: integer;
    inMemory: boolean; // ��
    nru: integer;      // ��������, �-��� ������ ����� ��������������
    pf: integer;       // ���-�� PF
begin
  pf := 0;
  queryN := UpDown2.Position;
  pagesN := UpDown1.Position;
  activeN := UpDown3.Position;

  // ������� ��������� 0
  for i:=0 to pagesN-1 do
    pages[i] := 0;

  // �������� ���
  for i:=0 to activeN-1 do
    active[i] := -1;

  // ����������� ��� �������
  for i:=0 to queryN-1 do
  begin
    // ������ ������; ���� � ������ ����� - ����� �������� � ���������� ������
    // ������ �� ������ ���, ���� ������ ������� ������ 0 - � ������ �� ���������� =)
    try
      query := StrToInt(StringGrid1.Cells[i, 1]);
    except
      ShowMessage('������������ ����');
      exit;
    end;

    // ���� ����� NRU �������� � ������� �������� �������
    inMemory := false;
    nru := 0;
    for j:=0 to activeN-1 do
    begin
      // ���� ��, ��� ��� ����� - ��� � ������
      if (active[j]=query) then
      begin
        // ������ �� ����
        inMemory := true;
        break;
      end;

      // ������� �������� �� ������� ���������� ����� ��� -1 -1 -1 -1...
      // ����� 1 �������� X -1 -1 -1 ...
      // ����� 2-� �������� X Y -1 -1 -1..

      // ���� ��� ����� �������� (-1 - ������� �������)
      if (active[j]>=0) then
      begin
        // ���� ��� �������� ������ ��������������, ��� ���������� �� ���. ������
        // <= ����� ������ < ����� �����  NRU ��������, �������������� ����� ����
        if (pages[active[j]]<=pages[active[nru]]) then
          nru := j;
      end
      else
      begin
        // ���� ��� �������, �� ����� �������� � ��� �����
        nru := j;
        break;
      end;
    end;

    // ���� �������� �� � ������
    if (not inMemory) then
    begin
      // ������� nru �� �������: �������� � ...
      for j:=nru downto 1 do
        active[j] := active[j-1];
      // ��������� � ������ ������� ����� ��������
      active[0] := query;
      // ����������� ������� PF
      inc(pf);
      // ����� � ������� � PF
      StringGrid2.Cells[i, activeN+1] := 'p';
    end
    else
      // ����� � ������� ��� PF �� ����
      StringGrid2.Cells[i, activeN+1] := '';
    inc(pages[query]);

    // ������� ��������� ������� �������� ������� � �������
    StringGrid2.Cells[i,  0] := StringGrid1.Cells[i,  1];
    for j:=0 to activeN-1 do
      if (active[j]>=0) then
        StringGrid2.Cells[i,  j+1] := IntToStr(active[j])
      else
        StringGrid2.Cells[i,  j+1] := '';
  end;
  // ������� PF
  Label4.Caption := 'Page faults:' + IntToStr(pf);

end;

end.
