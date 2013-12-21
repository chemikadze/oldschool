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
    EFind: TEdit;
    BFind: TButton;
    Label1: TLabel;
    Button1: TButton;
    procedure RGSortClick(Sender: TObject);
    procedure RGFiltrClick(Sender: TObject);
    procedure BFindClick(Sender: TObject);
    procedure Button1Click(Sender: TObject);
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
    ВНИМАНИЕ! Чтобы работало, надо открыть BDE Administrator,
    выбрать в меню Object->New, нажать Ok, указать название STUDENTS
    и указать Path как .\Data (см. методичку)
}

procedure TForm1.RGSortClick(Sender: TObject);
begin
  Case RGSort.ItemIndex of
    0 : TStud.IndexName := 'Index_Name';	//Индекс по имени
    1 : TStud.IndexName := 'Index_Sex_Name';	//Индекс по полу 
    2 : TStud.IndexName := 'Index_Group_Name'; 	//Индекс по группе 
  end;
  DBGStud.SetFocus;
{Сделать активным таблицу DBGStud}
end;

procedure TForm1.RGFiltrClick(Sender: TObject);
begin
	Case RGFiltr.ItemIndex of
	0 : 	TStud.CancelRange;	//Отменить фильтр
   	1 : 	begin
 			TStud.CancelRange;	//Отменить фильтр 
			TStud.IndexName := 'Index_Sex_Name';	//Индекс по полу
			TStud.SetRange(['Мужской'],['Мужской']);	//Установить фильтр
			{Показать только мужчин}
		end;
  	2 : 	begin
 	    		TStud.CancelRange;	//Отменить фильтр
	    		TStud.IndexName := 'Index_Sex_Name';	//Индекс по полу
	    		TStud.SetRange(['Женский'],['Женский']);	//Установить фильтр
			{Показать только женщин}
	  	end;	
	end;
DBGStud.SetFocus;
	{Сделать активным элементом таблицу DBGStud}
end;

procedure TForm1.BFindClick(Sender: TObject);
var year: integer;
begin
  TStud.Filter := 'Mark = 5 and Group = ' + EFind.Text;
  TStud.Filtered := true;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  TStud.Filtered := false;
end;

end.
