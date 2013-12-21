program Fractal;

uses
  Forms,
  Main in 'Main.pas' {MainForm},
  FastDib in 'FastDib\FastDIB.pas',
  FastFX in 'FastDib\FastFX.pas',
  FastFiles in 'FastDib\FastFiles.pas',
  FractObj in 'FractObj.pas',
  Params in 'Params.pas' {ParamsForm},
  Lang in 'Lang.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TMainForm, MainForm);
  Application.CreateForm(TParamsForm, ParamsForm);
  Application.Run;
end.
