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
  В силу особенностей баз данных Delphi
  нужно будет открыть Пуск -> Borland Delphi -> BDE ADministrator
  Нажать в меню Object->New
  выбрать STANDARD и нажать OK
  ввести имя элемента STUDENTS (большими буквами)
  в поле PATH ввести .\Data
}

procedure TForm1.RGSortClick(Sender: TObject);
begin
  TStud.Filtered := false;
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

procedure TForm1.Button1Click(Sender: TObject);
var s: string;
begin
  // читаем строку фильтра
  s := Edit1.Text;
  TStud.CancelRange;	//Отменить фильтр
  TStud.IndexName := 'Index_Name_Money';
// формируем фильтр и применяем его
  TStud.Filter := '(Name = ''' + s + '*'') and (Money > 0)';
  TStud.Filtered := true;
  //TStud.SetRange([s, 1],[s, 3000]);	//Установить фильтр
  DBGStud.SetFocus;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  TStud.CancelRange;	//Отменить фильтр
  TStud.IndexName := 'Index_Name';
  TStud.Filter := '';
  TStud.Filtered := false;
end;

end.
