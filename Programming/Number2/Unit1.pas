 unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Spin, Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    SpinEdit1: TSpinEdit;
    SpinEdit2: TSpinEdit;
    Button1: TButton;
    Label1: TLabel;
    Label2: TLabel;
    procedure SpinEdit1Change(Sender: TObject);
    procedure SpinEdit2Change(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

  A: array[0..100, 0..100] of Real;
  B: array[0..100, 0..100] of Integer;

implementation

{$R *.dfm}

procedure TForm1.SpinEdit1Change(Sender: TObject);
begin
  if SpinEdit1.Text='' then
    exit;
  StringGrid1.RowCount:=SpinEdit1.Value;
  StringGrid2.RowCount:=SpinEdit1.Value;
end;

procedure TForm1.SpinEdit2Change(Sender: TObject);
begin
  if SpinEdit1.Text='' then
    exit;
  StringGrid1.ColCount:=SpinEdit2.Value;
  StringGrid2.ColCount:=SpinEdit2.Value;
end;

procedure TForm1.Button1Click(Sender: TObject);
var i, j: integer;
begin
  for i:=0 to SpinEdit1.Value-1 do
    for j:=0 to SpinEdit2.Value-1 do
    begin
      B[i, j]:=1;                                   // первоначально все элементы первые
      A[i, j]:=StrToFloat(StringGrid1.Cells[j, i]); // читаем
    end;
  for i:=1 to SpinEdit1.Value*SpinEdit2.Value-1 do           // для всех элементов матрицы, начиная с 1
    for j:=0 to i-1 do                                       // сравниваем все элементы перед ним
      if A[i div SpinEdit2.Value, i mod SpinEdit2.Value]<A[j div SpinEdit2.Value, j mod SpinEdit2.Value] then
        inc(B[j div SpinEdit2.Value, j mod SpinEdit2.Value]) // увеличиваем для большего
      else
        inc(B[i div SpinEdit2.Value, i mod SpinEdit2.Value]);
  for i:=0 to SpinEdit1.Value-1 do                           // полученный массив и есть ответ
    for j:=0 to SpinEdit2.Value-1 do
      StringGrid2.Cells[j, i]:=IntToStr(B[i, j]);
end;

end.
