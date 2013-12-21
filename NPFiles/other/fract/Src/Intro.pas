unit Intro;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, ComCtrls, ShellAPI, jpeg;

type
  TIntroForm = class(TForm)
    Timer1: TTimer;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label9: TLabel;
    Label7: TLabel;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure Timer1Timer(Sender: TObject);
    procedure Label7Click(Sender: TObject);
    procedure Label6Click(Sender: TObject);
    procedure Label8Click(Sender: TObject);
  private
  public
  end;

implementation

{$R *.dfm}

procedure TIntroForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  Action := caFree;
end;

procedure TIntroForm.Timer1Timer(Sender: TObject);
begin
  Close;
end;

procedure TIntroForm.Label7Click(Sender: TObject);
begin
  Close;
end;

procedure TIntroForm.Label6Click(Sender: TObject);
begin
  ShellExecute(0, nil, 'mailto:alex@ritlabs.com?subject=Fractal', nil, nil, 0);
end;

procedure TIntroForm.Label8Click(Sender: TObject);
begin
  ShellExecute(0, nil, 'http://www.gaudeamus.md', nil, nil, 0);
end;


end.
