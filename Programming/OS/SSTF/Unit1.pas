unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, Grids;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Button1: TButton;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    UpDown1: TUpDown;
    Edit2: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
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
  StringGrid2.ColCount := NewValue+1;
end;

procedure TForm1.Button1Click(Sender: TObject);
var cyl: array [1..100] of integer;
    count: integer;
    i, j: integer;
    delta: integer;
    nextI: integer;
    pos: integer;
    tabpos: integer;
begin
  tabpos := 0;
  delta := 0;
  pos := StrToInt(Edit2.Text);
  count := UpDown1.Position;
  for i:=1 to count do
    cyl[i] := StrToInt(StringGrid1.Cells[i-1, 0]);
  StringGrid2.Cells[0, 0] := IntToStr(pos);
  while count > 0 do
  begin
    nextI := 1;
    for j := 1 to count do
      if (abs(cyl[nextI]-pos) > abs(cyl[j]-pos)) then
        nextI := j;
    delta := delta+abs(cyl[nextI]-pos);
    pos := cyl[nextI];
    inc(tabpos);
    StringGrid2.Cells[tabpos, 0] := IntToStr(pos);
    dec(count);
    for i:=nextI to count do
      cyl[i] := cyl[i+1];
  end;
  Label3.Caption := 'Перемещений головки жесткого диска: ' + IntToStr(delta);
end;

end.
