unit Main;

interface

uses
  SysUtils, Classes, Controls, Forms, StdCtrls, Solver;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Button1: TButton;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
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

procedure TForm1.FormDestroy(Sender: TObject);
begin
  ASolver.Free;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  ASolver.Solve(Edit1.Text);
  if ASolver.Error <> E_NOERROR then begin
    Edit3.Text := 'Error: ' + SolverErrorToStr(ASolver);
    Edit2.Clear;
    Exit;
  end else begin
    Edit3.Text := FloatToStr(ASolver.RPNResult);
    Edit2.Text := ASolver.RPNText;
  end;
end;

end.
