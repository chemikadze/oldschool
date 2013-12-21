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
    ��������! ����� ��������, ���� ������� BDE Administrator,
    ������� � ���� Object->New, ������ Ok, ������� �������� STUDENTS
    � ������� Path ��� .\Data (��. ���������)
}

procedure TForm1.RGSortClick(Sender: TObject);
begin
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
begin
  TStud.Filter := 'Mark > 4 and SessionMark > 4';  // � ������� ������ 4
  TStud.Filtered := true;  // ���������
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  TStud.Filter := '';
  TStud.Filtered := false;
end;

end.
