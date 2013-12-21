unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls;

type
  TForm1 = class(TForm)
    Memo1: TMemo;
    Button1: TButton;
    Image1: TImage;
    procedure Button1Click(Sender: TObject);
  private
    data: array [0..255] of integer;  
    max, noZeroCount: integer;

    procedure clearImage();
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.clearImage;
var i, j: integer; 
    colStep, colWidth: integer;
    pieceHeight: integer;
begin
  Image1.Canvas.Brush.Color := clWhite;
  Image1.Canvas.FillRect(Image1.Canvas.ClipRect);
  Image1.Canvas.Brush.Color := clRed;
  colStep := (Image1.Width - 15) div (noZeroCount + 1);
  colWidth := 2*colStep div 3;
  if (noZeroCount > 0) then
    pieceHeight := (Image1.Height-30) div max
  else
    pieceHeight := 0;
  Image1.Canvas.Brush.Color:=clWhite;
  for i:=0 to max do
    Image1.Canvas.TextOut(10, Image1.Height-15-pieceHeight*i, inttostr(i));
  j:=1;
  for i:=0 to 255 do
    if data[i] <> 0 then
    begin
      Image1.Canvas.Brush.Color := clRed;
      Image1.Canvas.Rectangle( 10+colStep*j - colWidth, Image1.Height-15, 10+colStep*j, Image1.Height-(15+pieceHeight*data[i]) );
      Image1.Canvas.Brush.Color := clWhite;
      Image1.Canvas.TextOut(10+colStep*j - colWidth, Image1.Height-15, char(i));
      inc(j);
    end;
  Image1.Canvas.Pen.Color := clBlack;
  Image1.Canvas.MoveTo(10, Image1.Height-15);   Image1.Canvas.LineTo(Image1.Width, Image1.Height-15); // X axis
  Image1.Canvas.MoveTo(10, Image1.Height-15);   Image1.Canvas.LineTo(10, 0); // Y axis
end;

procedure TForm1.Button1Click(Sender: TObject);
var i, j: integer;
begin
  max:=0;
  noZeroCount := 0;
  for i:=0 to 255 do
    data[i]:=0;
  for i:=1 to Length(Memo1.Text) do
  begin
    if data[ ord( Memo1.Text[i] ) ] = 0 then
      inc(noZeroCount);
    inc(data[ ord( Memo1.Text[i] ) ]);
    if (data[ord( Memo1.Text[i] )] > max)  then
      max := data[ord( Memo1.Text[i] )];
  end;
  clearImage();
end;

end.
