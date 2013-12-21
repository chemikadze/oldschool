unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, ExtCtrls;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Edit1: TEdit;
    Edit2: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    UpDown1: TUpDown;
    UpDown2: TUpDown;
    Button1: TButton;
    Label3: TLabel;
    procedure UpDown1ChangingEx(Sender: TObject; var AllowChange: Boolean;
      NewValue: Smallint; Direction: TUpDownDirection);
    procedure UpDown2ChangingEx(Sender: TObject; var AllowChange: Boolean;
      NewValue: Smallint; Direction: TUpDownDirection);
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Edit1KeyPress(Sender: TObject; var Key: Char);
    procedure Edit2KeyPress(Sender: TObject; var Key: Char);
  private
    { Private declarations }
  public
    x, y: Real;
    procedure repaintImage;
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
  if (NewValue >= UpDown1.Min) and (NewValue <= UpDown1.Max) then
  begin
    Edit1.Text := FloatToStr(NewValue / 10);
  end;
  
  x := NewValue / 10;

  repaintImage;
end;

procedure TForm1.UpDown2ChangingEx(Sender: TObject;
  var AllowChange: Boolean; NewValue: Smallint;
  Direction: TUpDownDirection);
begin
  if (NewValue >= UpDown2.Min) and (NewValue <= UpDown2.Max) then
  begin
    Edit2.Text := FloatToStr(NewValue / 10);
  end;
  
  y := NewValue / 10;

  repaintImage;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  Close;
end;

procedure TForm1.repaintImage;
var i, j: integer;
begin
  Image1.Canvas.Pen.Color := clBlack;
  Image1.Canvas.Brush.Color := clWhite;
  Image1.Canvas.FillRect(Image1.Canvas.ClipRect);

  // рисуем фигуру
  Image1.Canvas.Pen.Color := clGreen;
  Image1.Canvas.Brush.Color := clGreen;
  Image1.Canvas.MoveTo(Round((Image1.Width-20)/8 * 0 +10), Image1.Height - Round((Image1.Height-20)/8 * 0 ) - 10);
  Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * 8 +10), Image1.Height - Round((Image1.Height-20)/8 * 0 ) - 10);
  Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * 4 +10), Image1.Height - Round((Image1.Height-20)/8 * 8 ) - 10);
  Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * 0 +10), Image1.Height - Round((Image1.Height-20)/8 * 0 ) - 10);
  Image1.Canvas.MoveTo(Round((Image1.Width-20)/8 * 2 +10), Image1.Height - Round((Image1.Height-20)/8 * 0 ) - 10);
  Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * 6 +10), Image1.Height - Round((Image1.Height-20)/8 * 0 ) - 10);
  Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * 6 +10), Image1.Height - Round((Image1.Height-20)/8 * 2 ) - 10);
  Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * 2 +10), Image1.Height - Round((Image1.Height-20)/8 * 2 ) - 10);
  Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * 2 +10), Image1.Height - Round((Image1.Height-20)/8 * 0 ) - 10);
  // заливаем
  Image1.Canvas.FloodFill(Round((Image1.Width-20)/8 * 1 +10), Image1.Height - Round((Image1.Height-20)/8 * 1 ) - 10,
                          clWhite, fsSurface);
  //рисуем оси
  Image1.Canvas.Pen.Color := clBlack;
  Image1.Canvas.Brush.Color := clWhite;
  Image1.Canvas.MoveTo(0, Image1.Height - 10);
  Image1.Canvas.LineTo(Image1.Width, Image1.Height - 10);
  Image1.Canvas.MoveTo(10, 0);
  Image1.Canvas.LineTo(10, Image1.Height);
  // делаем циферки и насечки
  for i:=1 to 8 do
  begin
    Image1.Canvas.MoveTo(Round((Image1.Width-20)/8 * i)+10, Image1.Height - 15);
    Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * i)+10, Image1.Height - 5);
    Image1.Canvas.TextOut(Round((Image1.Width-20)/8 * i)+10, Image1.Height - 25, IntToStr(i));

    Image1.Canvas.MoveTo(5, Image1.Height - Round((Image1.Height-20)/8 * i)-10);
    Image1.Canvas.LineTo(15, Image1.Height - Round((Image1.Height-20)/8 * i)-10);
    Image1.Canvas.TextOut(15, Image1.Height - Round((Image1.Height-20)/8 * i)-10, IntToStr(i));  
  end;
  Image1.Canvas.Pen.Color := clRed;
  Image1.Canvas.Brush.Color := clRed;
  Image1.Canvas.Ellipse(Trunc((Image1.Width-20)/8 * x+8),
                        Trunc(Image1.Height - (Image1.Height-20)/8 * y - 12),
                        Trunc((Image1.Width-20)/8 * x+12),
                        Trunc(Image1.Height - (Image1.Height-20)/8 * y - 8));

  if (
    (x>=0) and (x<=8) and (y>=0) and
    (y <= 2*x) and (y<=16-2*x) and
    not ((x>2) and (x<6) and (y>=0) and (y<2))
  )
  then
    Label3.Caption := 'Попал'
  else
    Label3.Caption := 'Не попал';
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  x := 4;
  y := 4;
  repaintImage;
end;

procedure TForm1.Edit1KeyPress(Sender: TObject; var Key: Char);
var i: integer;
begin
  if (Key = #13) then
  begin
    i := Trunc(StrToFloat(Edit1.Text)*10);
    if (i>=UpDown1.Min) and (i<=UpDown1.Max) then
     UpDown1.Position := i;
    repaintImage;
  end;
end;

procedure TForm1.Edit2KeyPress(Sender: TObject; var Key: Char);
var i: integer;
begin
  if (Key = #13) then
  begin
    i := Trunc(StrToFloat(Edit2.Text)*10);
    if (i>=UpDown2.Min) and (i<=UpDown2.Max) then
     UpDown2.Position := i;
    repaintImage;
  end;
end;

end.


