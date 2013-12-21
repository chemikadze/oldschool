unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Grids, ComCtrls;

type
  TForm1 = class(TForm)
    UpDown1: TUpDown;
    Edit1: TEdit;
    Memo1: TMemo;
    StringGrid1: TStringGrid;
    Button1: TButton;
    Label1: TLabel;
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
  StringGrid1.RowCount := NewValue + 2;
end;

procedure TForm1.Button1Click(Sender: TObject);
var pages : array [1..100] of integer;  // ��������, ����������� � ������
    query : array [1..100] of integer;  // �������
    pageCount, queryCount : integer; // ���-�� �������, ������� ���������  � ������ � ��������
    i, j, k : integer; // ��������
    inMemory: boolean; // ��������� �� � ������ ������������� ��������
    farestPage: integer; // ��������, � ������� �� ����� ���������� ������ �����
    farestPageDist: integer; // ������� ������� � ��� �� ����� ���������
    pf: integer; // Page Fault
begin
  pf := 0;
  pageCount := UpDown1.Position; // ���-�� �������
  for i:=1 to pageCount do // ������� �������� �������� ��� ������
    pages[i] := -1;
  queryCount := Memo1.Lines.Count; // ���-�� ��������
  StringGrid1.ColCount := queryCount; // ���������� ���-�� ������� � �������
  for i:= 1 to queryCount do      // ������ ������� �� Memo
    query[i] := StrToInt(Memo1.Lines[i-1]);

  for i:= 1 to queryCount do // ��������� �������
  begin
    inMemory := false;     // �������������� ����������
    for j:=1 to pageCount do  // ���� ������ �������� � ������
    begin
      if (pages[j] = query[i]) then // ���� ��� � ������
      begin
        inMemory := true;           // �������� ��� � ����������
        break;                      // ��������� ������
      end
    end;
    if (not inMemory) then  // ���� �������� �� �����
    begin
      farestPageDist:= 0;   // �������������� ����������
      for j:=1 to pageCount do  // ���� �������� ������� ����� ������ ����� �� ������������
        if pages[j] = -1 then // ���� ���� ������ ����� - ������ �� ����
        begin
          farestPage := j;   // ���������� ���� ����� ��������
          break;             // ���������� �����
        end
        else
        begin
         for k:=i+1 to queryCount+1 do // ���� ����� ����� ������������ ��������. +1 ���� ��� ����������� �������������� �������
          begin  // ���� �������� ����� ����� �������������� ��� ����� ��������� ��� �������� ������ �� ����� ��������������
            if (k-i > farestPageDist) and ((k = queryCount+1) or (query[k] = pages[j])) then
            begin
              farestPageDist := k - i; // ����������, ��� ����� �������� �� ����� ��������������
              farestPage := j;  // ���������� �������, � ������� ������� ����� ��������
              break;   // ���������� ������
            end
            else
              if (query[k] = pages[j]) then // ���� ��������� ������������ (�� �� ����� ����)
                break; // ���������� ������
         end;
        end;
      inc(pf);    // ����������� PF
      pages[farestPage] := query[i]; // ���������� �������� �� ��������� �������
    end;
    for j:=1 to pageCount do // ������� �������
      if (pages[j]>=0) then
        StringGrid1.Cells[i-1, j] := IntToStr(pages[j])
      else
        StringGrid1.Cells[i-1, j] := '';
    // �������, ��� �� PF
    if (not inMemory) then
      StringGrid1.Cells[i-1, pageCount+1] := 'pf'
    else
      StringGrid1.Cells[i-1, pageCount+1] := '';
    // ������� ������
    StringGrid1.Cells[i-1, 0] := IntToStr(query[i]);
  end;
  // ������� PF
  Label1.Caption := 'Page Faults: ' + IntToStr(pf);
end;

end.
