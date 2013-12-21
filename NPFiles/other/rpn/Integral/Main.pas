unit Main;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, StdCtrls, Solver;

type
  TForm1 = class(TForm)
    Memo1: TMemo;
    Edit1: TEdit;
    Label1: TLabel;
    Edit3: TEdit;
    Label2: TLabel;
    Edit4: TEdit;
    Label3: TLabel;
    Label4: TLabel;
    Button1: TButton;
    Edit2: TEdit;
    Label5: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
  public
  end;

var
  Form1: TForm1;
  ASolver: TSolver;


implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
begin
  ASolver := TSolver.Create;
end;

function calch(a, b, n: Real): Real;
begin
  Result := abs(b-a)/n;
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  a, a2, b: Real;
  n: Real;
  S2n, Sn: Real;
  E: Real;
  h: Real;
  f: Byte;
  
label
  j;

begin
  Memo1.Clear;
  E := StrToFloat(Edit3.Text);
  a := StrToFloat(Edit1.Text);
  b := StrToFloat(Edit4.Text);
  n := 2;
  a2 := a;
  Sn := 0;
  f := 0;
  repeat
    j:
    S2n := Sn;
    a := a2;
    h := calch(a, b, n);
    Sn := 0;
    while a < b do begin
      ASolver.SolveGraph(Edit2.Text, a);
      if ASolver.Error <> E_NOERROR then begin
        Memo1.Lines.Add('Error: ' + SolverErrorToStr(ASolver));
        Exit;
      end;
      Sn := Sn + ASolver.RPNResult;
      a := a + h/2;
    end;
    Sn := Sn*h/2;
    n := n * 2;
    if f = 0 then begin
      f := 1;
      goto j;
    end;
  until (Abs(S2n-Sn)/3 <= E);
  Memo1.Lines.Add('Iterations: ' + FloatToStr(n));
  Memo1.Lines.Add('Result: ' + FloatToStr(Sn));
end;

end.
