unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Label1: TLabel;
    Edit1: TEdit;
    Label2: TLabel;
    Edit2: TEdit;
    Label3: TLabel;
    Edit3: TEdit;
    Label4: TLabel;
    Edit4: TEdit;
    Button1: TButton;
    Edit5: TEdit;
    Label5: TLabel;
    Label6: TLabel;
    Edit6: TEdit;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Edit2KeyPress(Sender: TObject; var Key: Char);
  private
    { Private declarations }
  public
    a, b: extended;
    fromx, tox, eps : extended;
    m: integer; // picels in 1
    { Public declarations }
    procedure redraw;
    function xToCanvas(x: extended):integer;
    function yToCanvas(y: extended):integer;
    function canvasToX(x: integer):extended;
    function canvasToY(y: integer):extended;
    function f(x: extended): extended;
    procedure reReadAB;
    procedure reReadSolving;
    procedure solve;
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

function TForm1.xToCanvas(x: extended):integer;
begin
  Result := Image1.Width div 2 + Round(x * m);
end;

function TForm1.yToCanvas(y: extended):integer;
begin
  Result := Image1.Height div 2 - Round(y * m);
end;

function TForm1.canvasToX(x: integer): extended;
begin
  Result := (x - Image1.Width div 2) / m;
end;

function TForm1.canvasToY(y: integer): extended;
begin
  Result := -(y - Image1.Height div 2) / m;
end;

procedure TForm1.redraw();
var i: integer;
begin
  Image1.Canvas.Pen.Color := clBlack;
  Image1.Canvas.FillRect(Image1.ClientRect);
  // ось Y
  Image1.Canvas.MoveTo(xToCanvas(0), 0);
  Image1.Canvas.LineTo(xToCanvas(0), Image1.Height);
  // ось X
  Image1.Canvas.MoveTo(0, yToCanvas(0));
  Image1.Canvas.LineTo(Image1.Width, yToCanvas(0));
  // засечки на оси X
  for i:=round(canvasToX(0)) to round(canvasToX(Image1.Width)) do
  begin
    Image1.Canvas.MoveTo(xToCanvas(i), yToCanvas(0)-2);
    Image1.Canvas.LineTo(xToCanvas(i), yToCanvas(0)+2);
    Image1.Canvas.TextOut(xToCanvas(i), yToCanvas(0)+4, IntToStr(i));
  end;
  // засечки на оси Y
  for i:=round(canvasToY(0)) downto round(canvasToY(Image1.Height)) do
  begin
    Image1.Canvas.MoveTo(xToCanvas(0)-2, yToCanvas(i));
    Image1.Canvas.LineTo(xToCanvas(0)+2, yToCanvas(i));
    Image1.Canvas.TextOut(xToCanvas(0)+4, yToCanvas(i), IntToStr(i));
  end;
  Image1.Canvas.Pen.Color := clRed;
  // первая точка графика
  Image1.Canvas.MoveTo(0, yToCanvas(f(canvasToX(0))));
  // попиксельный график
  for i:=1 to Image1.Width do // и пусть весь мир подождет
   Image1.Canvas.LineTo(i, yToCanvas(f(canvasToX(i))));
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  m := 25;
  reReadAB();
  redraw();
end;

function TForm1.f(x: extended): extended;
begin
  if ((x*x - a) = 0) then // деление на 0
    Result := 0
  else
    Result := x*x / (x*x-a) + b;
end;

procedure TForm1.reReadAB;
begin
  a := StrToFloat(Edit1.Text);
  b := StrToFloat(Edit2.Text);
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  reReadAB;
  redraw;
  reReadSolving;
  solve;
end;

procedure TForm1.Edit2KeyPress(Sender: TObject; var Key: Char);
begin
  if (Key = #13) then
  begin
    reReadAB;
    redraw;
  end
end;

procedure TForm1.reReadSolving;
begin
  fromx := StrToFloat(Edit3.Text);
  tox := StrToFloat(Edit4.Text);
  eps := StrToFloat(Edit5.Text);
end;


procedure TForm1.solve;
var a, b, c: extended;
begin
  a := fromx;
  b := tox;
  while ( abs(b-a) >= eps ) do
  begin
    c := (a+b)/2;
    if ((f(a)>0) and (f(c)>0)) or
       ((f(a)<0) and (f(c)<0)) then
      a:=c
    else
   // if ((f(b)>0) and (f(c)>0)) or
   //    ((f(b)<0) and (f(c)<0)) then
      b:=c;
  end;
  Edit6.Text := FloatToStr(c);
end;

end.
