unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, Grids, DBGrids, DB, DBTables;

type
  TForm1 = class(TForm)
    TStud: TTable;
    DSStud: TDataSource;
    DBGStud: TDBGrid;
    RGSort: TRadioGroup;
    RGFiltr: TRadioGroup;
    Edit1: TEdit;
    Button1: TButton;
    Button2: TButton;
    procedure RGSortClick(Sender: TObject);
    procedure RGFiltrClick(Sender: TObject);
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

{
  � ���� ������������ ��� ������ Delphi
  ����� ����� ������� ���� -> Borland Delphi -> BDE ADministrator
  ������ � ���� Object->New
  ������� STANDARD � ������ OK
  ������ ��� �������� STUDENTS (�������� �������)
  � ���� PATH ������ .\Data
}

procedure TForm1.RGSortClick(Sender: TObject);
begin
  TStud.Filtered := false;
  Case RGSort.ItemIndex of
    0 : TStud.IndexName := 'Index_Name';	//������ �� �����
    1 : TStud.IndexName := 'Index_Sex_Name';	//������ �� ���� 
    2 : TStud.IndexName := 'Index_Group_Name'; 	//������ �� ������ 
  end;
  DBGStud.SetFocus;
{������� �������� ������� DBGStud}
end;

procedure TForm1.RGFiltrClick(Sender: TObject);
begin
  TStud.Filtered := false;
	Case RGFiltr.ItemIndex of
	0 : 	TStud.CancelRange;	//�������� ������
   	1 : 	begin
 			TStud.CancelRange;	//�������� ������
			TStud.IndexName := 'Index_Sex_Name';	//������ �� ����
			TStud.SetRange(['�������'],['�������']);	//���������� ������
			{�������� ������ ������}
		end;
  	2 : 	begin
 	    		TStud.CancelRange;	//�������� ������
	    		TStud.IndexName := 'Index_Sex_Name';	//������ �� ����
	    		TStud.SetRange(['�������'],['�������']);	//���������� ������
			{�������� ������ ������}
	  	end;	
	end;
DBGStud.SetFocus;
	{������� �������� ��������� ������� DBGStud}
end;

procedure TForm1.Button1Click(Sender: TObject);
var s: string;
begin
  // ������ ������ �������
  s := Edit1.Text;
  TStud.CancelRange;	//�������� ������
  TStud.IndexName := 'Index_Name_Money';
// ��������� ������ � ��������� ���
  TStud.Filter := '(Name = ''' + s + '*'') and (Money > 0)';
  TStud.Filtered := true;
  //TStud.SetRange([s, 1],[s, 3000]);	//���������� ������
  DBGStud.SetFocus;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  TStud.CancelRange;	//�������� ������
  TStud.IndexName := 'Index_Name';
  TStud.Filter := '';
  TStud.Filtered := false;
end;

end.
