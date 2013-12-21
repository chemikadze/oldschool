unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Grids, ExtCtrls;

type
  TForm1 = class(TForm)
    Shape1: TShape;
    Shape2: TShape;
    Shape3: TShape;
    Shape4: TShape;
    Shape5: TShape;
    Shape6: TShape;
    Shape7: TShape;
    Shape8: TShape;
    Shape9: TShape;
    Shape10: TShape;
    Shape11: TShape;
    Shape12: TShape;
    Shape13: TShape;
    Shape14: TShape;
    Shape15: TShape;
    Shape16: TShape;
    Shape17: TShape;
    Shape18: TShape;
    Shape19: TShape;
    Shape20: TShape;
    Shape21: TShape;
    Shape22: TShape;
    Shape23: TShape;
    Shape24: TShape;
    Shape25: TShape;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    Button1: TButton;
    Button2: TButton;
    procedure Button2Click(Sender: TObject);
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

procedure TForm1.Button2Click(Sender: TObject);
begin
  Close;
end;

procedure TForm1.Button1Click(Sender: TObject);
var ina, outa : array[1..5, 1..5] of integer;
    i, j, b: integer;
begin
  randomize;
  for i:=1 to 5 do
    for j:=1 to 5 do
    begin
      ina[i, j] := random(9)+1;
      StringGrid1.Cells[i, j] := IntToStr(ina[i, j]);
    end;

  for i:=1 to 5 do
    for j:=1 to 5 do
    begin
      if ( (i + (5-j)) < 7 ) then
        outa[i, j] := ina[i, j]
      else
        outa[i, j] := 0;
      StringGrid2.Cells[i, j] := IntToStr(outa[i, j]);
    end;
end;

end.
