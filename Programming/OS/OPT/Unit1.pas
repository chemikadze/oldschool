unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Grids, ComCtrls;

type
  TForm1 = class(TForm)
    UpDown1: TUpDown;
    Edit1: TEdit;
    Memo1: TMemo;
    StringGrid1: TStringGrid;
    Button1: TButton;
    Label1: TLabel;
    procedure UpDown1ChangingEx(Sender: TObject; var AllowChange: Boolean;
      NewValue: Smallint; Direction: TUpDownDirection);
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

procedure TForm1.UpDown1ChangingEx(Sender: TObject;
  var AllowChange: Boolean; NewValue: Smallint;
  Direction: TUpDownDirection);
begin
  StringGrid1.RowCount := NewValue + 2;
end;

procedure TForm1.Button1Click(Sender: TObject);
var pages : array [1..100] of integer;  // страницы, находящиеся в памяти
    query : array [1..100] of integer;  // запросы
    pageCount, queryCount : integer; // кол-во страниц, могущих находится  в памяти и запросов
    i, j, k : integer; // счетчики
    inMemory: boolean; // находится ли в памяти запрашиваемая страница
    farestPage: integer; // страница, к которой не будут обращаться дольше всего
    farestPageDist: integer; // сколько времени к ней не будут обращатся
    pf: integer; // Page Fault
begin
  pf := 0;
  pageCount := UpDown1.Position; // кол-во страниц
  for i:=1 to pageCount do // сначала помечаем страницы как пустые
    pages[i] := -1;
  queryCount := Memo1.Lines.Count; // кол-во запросов
  StringGrid1.ColCount := queryCount; // выставляем кол-во колонок в таблице
  for i:= 1 to queryCount do      // читаем запросы из Memo
    query[i] := StrToInt(Memo1.Lines[i-1]);

  for i:= 1 to queryCount do // выполняем запросы
  begin
    inMemory := false;     // инициализируем переменную
    for j:=1 to pageCount do  // ищем нужную страницу в памяти
    begin
      if (pages[j] = query[i]) then // если она в памяти
      begin
        inMemory := true;           // помечаем это в переменной
        break;                      // перестаем искать
      end
    end;
    if (not inMemory) then  // если страницу не нашли
    begin
      farestPageDist:= 0;   // инициализируем переменную
      for j:=1 to pageCount do  // ищем страницу которую будем дольше всего не использовать
        if pages[j] = -1 then // если есть пустое место - дальше не ищем
        begin
          farestPage := j;   // запоминаем куда можно записать
          break;             // прекращаем поиск
        end
        else
        begin
         for k:=i+1 to queryCount+1 do // ищем когда будем использовать страницу. +1 надо для определения неиспользуемых страниц
          begin  // если страница будет позже использоваться чем ранее найденная или страница вообще не будет использоваться
            if (k-i > farestPageDist) and ((k = queryCount+1) or (query[k] = pages[j])) then
            begin
              farestPageDist := k - i; // запоминаем, как долго страница не будет использоваться
              farestPage := j;  // запоминаем позицию, в которую запишем новую страницу
              break;   // прекращаем поиски
            end
            else
              if (query[k] = pages[j]) then // если странница используется (но не позже всех)
                break; // прекращаем искать
         end;
        end;
      inc(pf);    // увеличиваем PF
      pages[farestPage] := query[i]; // записываем страницу по найденной позиции
    end;
    for j:=1 to pageCount do // выводим столбец
      if (pages[j]>=0) then
        StringGrid1.Cells[i-1, j] := IntToStr(pages[j])
      else
        StringGrid1.Cells[i-1, j] := '';
    // выводим, был ли PF
    if (not inMemory) then
      StringGrid1.Cells[i-1, pageCount+1] := 'pf'
    else
      StringGrid1.Cells[i-1, pageCount+1] := '';
    // выводим запрос
    StringGrid1.Cells[i-1, 0] := IntToStr(query[i]);
  end;
  // выводим PF
  Label1.Caption := 'Page Faults: ' + IntToStr(pf);
end;

end.
