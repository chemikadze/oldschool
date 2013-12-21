unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    Edit1: TEdit;
    Edit2: TEdit;
    UpDown1: TUpDown;
    UpDown2: TUpDown;
    Label1: TLabel;
    Label2: TLabel;
    Edit3: TEdit;
    Label3: TLabel;
    UpDown3: TUpDown;
    Button1: TButton;
    StringGrid2: TStringGrid;
    Label4: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Edit2Change(Sender: TObject);
    procedure Edit3Change(Sender: TObject);
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

procedure TForm1.FormCreate(Sender: TObject);
var i: integer;
begin
  for i:=1 to UpDown2.Position do
  begin
    StringGrid1.Cells[i-1, 0] := IntToStr(i);
  end;
end;

procedure TForm1.Edit2Change(Sender: TObject);
var i: integer;
begin
  StringGrid1.ColCount := UpDown2.Position;
  StringGrid2.ColCount := UpDown2.Position;
  for i:=1 to UpDown2.Position do
  begin
    StringGrid1.Cells[i-1, 0] := IntToStr(i);
  end;
end;

procedure TForm1.Edit3Change(Sender: TObject);
begin
  StringGrid2.RowCount := UpDown3.Position + 2;
end;

procedure TForm1.Button1Click(Sender: TObject);
var queryN: integer;  // кол-во запросов
    query: integer;   // текущий запрос
    pagesN: integer;  // кол-во страниц
    activeN: integer; // макс. кол-во активных страниц (к-рые в памяти)
    active: array [0..100] of integer; // номера активных страниц
    pages: array [0..100] of integer;  // кол-во обращений к страницам
    i, j: integer;
    inMemory: boolean; // хз
    nru: integer;      // страница, к-рая меньше всего использовалась
    pf: integer;       // кол-во PF
begin
  pf := 0;
  queryN := UpDown2.Position;
  pagesN := UpDown1.Position;
  activeN := UpDown3.Position;

  // сначала обращений 0
  for i:=0 to pagesN-1 do
    pages[i] := 0;

  // активных нет
  for i:=0 to activeN-1 do
    active[i] := -1;

  // обслуживаем все запросы
  for i:=0 to queryN-1 do
  begin
    // читаем запрос; если в клетке хрень - ловим экзепшон и показываем ошибку
    // защиты от дурака нет, если номера страниц меньше 0 - я ничего не гарантирую =)
    try
      query := StrToInt(StringGrid1.Cells[i, 1]);
    except
      ShowMessage('Неправильный ввод');
      exit;
    end;

    // ищем номер NRU страницы в очереди активных страниц
    inMemory := false;
    nru := 0;
    for j:=0 to activeN-1 do
    begin
      // если то, что нам нужно - уже в памяти
      if (active[j]=query) then
      begin
        // больше не ищем
        inMemory := true;
        break;
      end;

      // очередь активных до полного заполнения имеет вид -1 -1 -1 -1...
      // после 1 итерации X -1 -1 -1 ...
      // после 2-х итераций X Y -1 -1 -1..

      // если это номер страницы (-1 - признак пустоты)
      if (active[j]>=0) then
      begin
        // если эта страница меньше использовалась, чем наименьшая на тек. момент
        // <= стоит вместо < чтобы найти  NRU страницу, использованную позже всех
        if (pages[active[j]]<=pages[active[nru]]) then
          nru := j;
      end
      else
      begin
        // если тут пустота, то можно записать в это место
        nru := j;
        break;
      end;
    end;

    // если страница не в памяти
    if (not inMemory) then
    begin
      // удаляем nru их очереди: сдвигаем и ...
      for j:=nru downto 1 do
        active[j] := active[j-1];
      // добавляем в начало очереди новую страницу
      active[0] := query;
      // увеличиваем счетчик PF
      inc(pf);
      // пишем в таблицу о PF
      StringGrid2.Cells[i, activeN+1] := 'p';
    end
    else
      // пишем в таблицу что PF не было
      StringGrid2.Cells[i, activeN+1] := '';
    inc(pages[query]);

    // выводим состояние очереди активных страниц в столбец
    StringGrid2.Cells[i,  0] := StringGrid1.Cells[i,  1];
    for j:=0 to activeN-1 do
      if (active[j]>=0) then
        StringGrid2.Cells[i,  j+1] := IntToStr(active[j])
      else
        StringGrid2.Cells[i,  j+1] := '';
  end;
  // выводим PF
  Label4.Caption := 'Page faults:' + IntToStr(pf);

end;

end.
