unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Spin, StdCtrls, ExtCtrls, Math;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    Edit1: TEdit;
    Label3: TLabel;
    Edit2: TEdit;
    Label4: TLabel;
    Edit3: TEdit;
    Label6: TLabel;
    Edit7: TEdit;
    Label7: TLabel;
    Edit8: TEdit;
    Label8: TLabel;
    Button1: TButton;
    SpinEdit1: TSpinEdit;
    Image1: TImage;
    Image2: TImage;
    Label5: TLabel;
    SpinEdit2: TSpinEdit;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure SpinEdit2Change(Sender: TObject);
    procedure SpinEdit1Change(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    A, B: extended;
    cnt, M: integer;
    function bar(n:integer):extended;
    function trap(n:integer):extended;
    function sympson(n:integer):extended;
    procedure clearGraph;
    procedure clearDelta;
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

function f(x:extended):extended;  // сама функция
begin
  if Abs(x)<0.001 then            // в точке 0 не существует, предел равен бесконечности
    f:=10000000
  else
    f:=sqr(tan(x))+sqr(1/tan(x));
end;

function pF(x:extended):extended;  // первообразная
begin
  pF:=tan(x)-1/tan(x)-2*x-tan(pi/6)+1/tan(pi/6)+pi/3;
end;

function TForm1.bar(n:integer):extended;  // методом прямоугольников для N разбиений
var x, h, int: extended;
    i:integer;
begin
  int:=0;
  x:=A;
  h:=(B-A)/N;
  for i:=0 to N-1 do
  begin
    int:=int+f(x);
    x:=x+h;
  end;
  int:=int*h;
  bar:=int;
end;

function TForm1.trap(n:integer):extended;  // метедом трапеций для N разбиений
var x, h, int: extended;
    i:integer;
begin
  h:=(B-A)/N;
  int:=(f(A)+f(B))/2;
  x:=A+h;
  for i:=1 to N-1 do
  begin
    int:=int+f(x);
    x:=x+h;
  end;
  trap:=int*h;
end;

function TForm1.sympson(n:integer):extended; // методом Симпсона (метод парабол) для N разбиений
var x, h, int, pint: extended;
    i:integer;
begin
  h:=(B-A)/N*2;
  int:=f(A)+f(B);
  x:=A+h/2;
  pint:=0;
  i:=1;
  while i<=N-1 do // не for т.к. шаг 2
  begin
    pint:=pint+f(x);
    x:=x+h;
    inc(i, 2);
  end;
  int:=int+pint*4;
  x:=a+h;
  pint:=0;
  i:=2;
  while i<=N-2 do // не for т.к. шаг 2
  begin
    pint:=pint+f(x);
    x:=x+h;
    inc(i, 2);
  end;
  int:=int+pint*2;
  sympson:=int*(B-A)/(3*N);
end;

procedure TForm1.Button1Click(Sender: TObject);
var x,ans: extended;
    i: integer;
begin
  A:=StrToFloat(Edit7.Text);   // читаем верхний
  B:=StrToFloat(Edit8.Text);   // и нижний пределы
  cnt:=SpinEdit1.Value;        // кол-во точек
                              
  ans:=pF(B)-pF(A);             // решаем через первообразную
  clearGraph;                   // очищаем первый
  clearDelta;                   // и второй графики
  x:=-Image1.Width div (2*M)-1;
  Image1.Canvas.Pen.Color:=clRed;      // строим график
  Image1.Canvas.MoveTo(0, round(-f(x)*M+Image1.Height div 2));
  repeat
    Image1.Canvas.LineTo(round(x*M+Image1.Width div 2), round(-f(x)*M+Image1.Height div 2));
    x:=x+0.5/M;
  until x>Image1.Width div (2*M)+1;

  // строим график вероятностей для метода прямоугольников (красным)
  Image2.Canvas.Pen.Color:=clRed;     
  x:=bar(1);
  Image2.Canvas.MoveTo(10+((Image2.Width-10) div cnt)*1, Image2.Height-10-round((Image2.Height-20)*(Abs(x-ans)/ans)));
  for i:=2 to cnt do
  begin
    x:=bar(i);
    Image2.Canvas.LineTo(10+((Image2.Width-10) div cnt)*i, Image2.Height-10-round((Image2.Height-20)*(Abs((x-ans)/ans))));
  end;

  // строим график вероятностей для метода парабол  (синим) -- заметить что у них отклонения одинаковы (графики совпадают)
  Image2.Canvas.Pen.Color:=clBlue;     
  x:=trap(1);
  Image2.Canvas.MoveTo(10+((Image2.Width-10) div cnt)*1, Image2.Height-10-round((Image2.Height-20)*(Abs((x-ans)/ans))));
  for i:=2 to cnt do
  begin
    x:=trap(i);
    Image2.Canvas.LineTo(10+((Image2.Width-10) div cnt)*i, Image2.Height-10-round((Image2.Height-20)*(Abs((x-ans)/ans))));
  end;

  // строим график для метода парабол (зеленым). сказать сычу что офигенно точно строит, если число разбиений четно то ахрененная точность
  // при нечетном числе разбиений получается фигота. если начнет спрашивать, почему формула не совсем та - делал по википедии
  Image2.Canvas.Pen.Color:=clGreen;
  x:=sympson(1);
  Image2.Canvas.MoveTo(10+((Image2.Width-10) div cnt)*1, Image2.Height-10-round((Image2.Height-20)*(Abs((x-ans)/ans))));
  for i:=2 to cnt do
  begin
    x:=sympson(i);
    Image2.Canvas.LineTo(10+((Image2.Width-10) div cnt)*i, Image2.Height-10-round((Image2.Height-20)*(Abs((x-ans)/ans))));
  end;
  // выводим интегралы
  Edit1.Text:=FloatToStr(bar(cnt));
  Edit2.Text:=FloatToStr(trap(cnt));
  Edit3.Text:=FloatToStr(sympson(cnt));
end;

procedure TForm1.clearGraph;
var i: integer;
begin
  Image1.Canvas.Pen.Color:=clBlack;
  Image1.Canvas.Refresh;
  Image1.Canvas.FillRect(Image1.Canvas.ClipRect);
  Image1.Canvas.MoveTo(0, Image1.Height div 2);
  Image1.Canvas.LineTo(Image1.Width, Image1.Height div 2);
  Image1.Canvas.MoveTo(Image1.Width div 2, 0);
  Image1.Canvas.LineTo(Image1.Width div 2, Image1.Height);
  for i:=1 to Image1.Height div (2*M) do
  begin
    Image1.Canvas.MoveTo(Image1.Width div 2-5, Image1.Height div 2+m*i);
    Image1.Canvas.LineTo(Image1.Width div 2+5, Image1.Height div 2+m*i);
    Image1.Canvas.TextOut(Image1.Width div 2+5,  Image1.Height div 2+m*i, IntToStr(i));
    Image1.Canvas.MoveTo(Image1.Width div 2-5, Image1.Height div 2-m*i);
    Image1.Canvas.LineTo(Image1.Width div 2+5, Image1.Height div 2-m*i);
    Image1.Canvas.TextOut(Image1.Width div 2+5,  Image1.Height div 2-m*i, IntToStr(-i));
  end;
  for i:=1 to Image1.Width div (2*M) do
  begin
    Image1.Canvas.MoveTo(Image1.Width div 2+m*i, Image1.Height div 2-5);
    Image1.Canvas.LineTo(Image1.Width div 2+m*i, Image1.Height div 2+5);
    Image1.Canvas.TextOut(Image1.Width div 2+m*i,  Image1.Height div 2+5, IntToStr(i));
    Image1.Canvas.MoveTo(Image1.Width div 2-m*i, Image1.Height div 2-5);
    Image1.Canvas.LineTo(Image1.Width div 2-m*i, Image1.Height div 2+5);
    Image1.Canvas.TextOut(Image1.Width div 2-m*i,  Image1.Height div 2+5, IntToStr(-i));
  end;
end;

procedure TForm1.clearDelta;
var i:integer;
begin
  Image2.Canvas.Pen.Color:=clBlack;
  Image1.Canvas.Refresh;
  Image2.Canvas.FillRect(Image2.Canvas.ClipRect);
  Image2.Canvas.MoveTo(0, Image2.Height-10);
  Image2.Canvas.LineTo(Image2.Width, Image2.Height-10);
  Image2.Canvas.MoveTo(10, 0);
  Image2.Canvas.LineTo(10, Image2.Height);
  for i:=1 to 10 do
  begin
    Image2.Canvas.MoveTo(7, Image2.Height-10-((Image2.Height-20) div 10)*i);
    Image2.Canvas.LineTo(13, Image2.Height-10-((Image2.Height-20) div 10)*i);
    Image2.Canvas.TextOut(13,  Image2.Height-10-((Image2.Height-20) div 10)*i, FloatToStr(i/10.0));
  end;
  for i:=1 to cnt do
  begin
    Image2.Canvas.MoveTo(10+((Image2.Width-10) div cnt)*i, Image2.Height-13);
    Image2.Canvas.LineTo(10+((Image2.Width-10) div cnt)*i, Image2.Height-7);
    if ((Image2.Width-10) div cnt)>15 then
      Image2.Canvas.TextOut(10+((Image2.Width-10) div cnt)*i, Image2.Height-13, FloatToStr(i));
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  M:=SpinEdit2.Value;
  cnt:=SpinEdit1.Value;
  clearGraph;
  clearDelta;
end;

procedure TForm1.SpinEdit2Change(Sender: TObject);
begin
  if SpinEdit2.Text<>'' then
  begin
    M:=SpinEdit2.Value;
    clearGraph;
  end;
end;

procedure TForm1.SpinEdit1Change(Sender: TObject);
begin
  if SpinEdit1.Text<>'' then
  begin
    cnt:=SpinEdit1.Value;
    clearDelta;
  end;
end;

end.
