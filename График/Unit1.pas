unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, Spin, Math;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Button1: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Edit3: TEdit;
    Label4: TLabel;
    Button2: TButton;
    Edit4: TEdit;
    Edit5: TEdit;
    SpinEdit1: TSpinEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var A,B, x,y,x1,x2,m,x0,k:real; N, dx:integer;
begin
  k:=1;
  A:=strtofloat(Edit1.Text);
  B:=strtofloat(Edit2.text);
  x1:=strtofloat(edit4.Text);
  x2:=strtofloat(edit5.Text);
  m:=spinedit1.Value;
  dx:=image1.Width div 2;
  with Image1.Canvas do
    begin
      fillRect(image1.ClientRect);
      x:=x1;
      while x<x2 do
      begin
        x:=x+0.001;
        if ( (2*A-x > 0) and (power(x, 3)/(2*A-x) > 0) ) then
          y:=Sqrt(power(x, 3)/(2*A-x))-B
        else
          y:=0;
        Pixels[Round(m*x)+dx,image1.Height div 2-Round(m/K*y)]:=clBlack;
      end;
      MoveTo(0,image1.Height div 2);
      LineTo(image1.Width,image1.Height div 2);
      MoveTo(dx,0);
      LineTo(dx,image1.Width);
      for N:=round(x1) to round(x2) do
      begin
        MoveTo(dx+round(N*M), image1.Height div 2+3);
        LineTo(dx+round(N*M), image1.Height div 2-3);
        TextOut(dx+round(N*M), image1.Height div 2+3, floatToStr(N));
      end;
      for N:=-round((K*image1.Height)/M/2) to round((K*image1.Height)/M/2) do
      begin
        MoveTo(dx-3, image1.Height div 2+round(N*M/K));
        LineTo(dx+3, image1.Height div 2+round(N*M/K));
        TextOut(dx+3, image1.Height div 2+round(N*M/K), floatToStr(-N));
      end;
    end;

end;

procedure TForm1.Button2Click(Sender: TObject);
var A,B,C,eps,r,x1,x2:real;
    Function f(x:real):real;
    begin f:=Sqrt(power(x, 3)/(2*A-x))-B;
    end;
begin
A:=strtofloat(Edit1.Text);
B:=strtofloat(Edit2.text);
eps:=strtofloat(Edit3.text);
x1:=strtofloat(Edit6.Text);
x2:=strtofloat(Edit7.text);
  repeat
  c:=(x1+x2)/2;
  if f(x1)*f(C)<0 then
  x2:=C else x1:=C;
  until ((x2-x1)/2<eps)or (f(C)=0);
  if f(C)=0 then r:=C else r:=(x1+x2)/2;
  Label1.Caption:=floattostr(r);
end;

end.
