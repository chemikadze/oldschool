unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, Grids, DBGrids, DB, DBTables, Spin;

type
  TForm1 = class(TForm)
    TStud: TTable;
    DSStud: TDataSource;
    DBGStud: TDBGrid;
    RGSort: TRadioGroup;
    RGFiltr: TRadioGroup;
    BFind: TButton;
    SpinEdit1: TSpinEdit;
    procedure RGSortClick(Sender: TObject);
    procedure RGFiltrClick(Sender: TObject);
    procedure BFindClick(Sender: TObject);
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
  В силу особенностей баз данных Delphi
  нужно будет открыть Пуск -> Borland Delphi -> BDE ADministrator
  Нажать в меню Object->New
  выбрать STANDARD и нажать OK
  ввести имя элемента STUDENTS (большими буквами)
  в поле PATH ввести .\Data
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
  TStud.Filter := '';
  TStud.Filtered := false;
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
begin
  TStud.CancelRange;	//Отменить фильтр
  TStud.IndexName := 'Index_Name';	//Индекс по имени
  TStud.Filter := 'Money > ' + SpinEdit1.Text; // условие фильтра
  TStud.Filtered := true; // фильтруем
  DBGStud.SetFocus;{Сделать активным элементом таблицу DBGStud}
end;

end.
