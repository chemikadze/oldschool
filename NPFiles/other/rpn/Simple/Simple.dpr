program Simple;

uses
  Forms,
  Solver in '..\RPN\Solver.pas',
  Main in 'Main.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
