unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Spin, XPMan, Menus, About;

type
  TMainForm = class(TForm)
    EAdres: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    EText: TEdit;
    BSend: TButton;
    ECount: TSpinEdit;
    EDelay: TSpinEdit;
    Label3: TLabel;
    Label4: TLabel;
    XPManifest1: TXPManifest;
    MainMenu1: TMainMenu;
    N1: TMenuItem;
    N2: TMenuItem;
    procedure BSendClick(Sender: TObject);
    procedure N1Click(Sender: TObject);
    procedure N2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  MainForm: TMainForm;

implementation

const sSend='Послать';
const sSending='Идет отсылка...';

{$R *.dfm}

procedure TMainForm.BSendClick(Sender: TObject);
var a,t:String;
    i:Integer;
begin
  BSend.Enabled:=false;
  BSend.Caption:=sSending;
  a:=EAdres.Text;
  t:=EText.Text;
  for i:=1 to ECount.Value do
    begin
      WinExec(PChar('NET SEND '+a+' '+t),0);
      if (ECount.Value>1) then Sleep(EDelay.Value);
    end;
  BSend.Enabled:=true;
  BSend.Caption:=sSend;
end;

procedure TMainForm.N1Click(Sender: TObject);
begin
  About.AboutBox.Show;
end;

procedure TMainForm.N2Click(Sender: TObject);
begin
  MainForm.Close;
end;

end.
