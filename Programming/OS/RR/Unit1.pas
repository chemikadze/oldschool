unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    Button1: TButton;
    Edit1: TEdit;
    UpDown1: TUpDown;
    Label1: TLabel;
    StringGrid2: TStringGrid;
    Label2: TLabel;
    Edit2: TEdit;
    Label3: TLabel;
    UpDown2: TUpDown;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  N: integer;

implementation

{$R *.dfm}


function min(x, y: integer):integer;
begin
  if (x > y) then
    min := y
  else
    min := x;
end;

procedure TForm1.Button1Click(Sender: TObject);
var i, time: integer; // счетчик циклов и текущее времмя
    active: array[1..100] of boolean; // активность
    active_count: integer; // кол-во активных
    aktivny: integer;      // номер исполняющегося процесса (активный процесс)
    kvant, kvant_size: integer;  // квант

    // все данные процессов, CPUburst и появление
    process: array[1..100, 1..2] of integer;

    ostalos: integer; // осталось выполнить процессов

    vipoln: integer;   // время выполнения
    ozhid: integer;   // время ожидания
begin
  // читаем данные
  for i:=1 to N do
  begin
    process[i,1] := StrToInt(StringGrid1.Cells[1, i]);
    process[i,2] := StrToInt(StringGrid1.Cells[2, i]);
    active[i] := false;
  end;
  kvant_size := UpDown2.position;

  time:=0;
  active_count := 0;
  ostalos := N;
  vipoln := 0;
  ozhid := 0;
  aktivny := 0;
  kvant := 0;
  while (ostalos > 0) do
  begin
    // очищаем текущий столбец
    for i:=1 to N do
      StringGrid2.Cells[time+1, i] := '';

    // проверяем и помечаем активными новые процессы
    for i:=1 to N do
      if (process[i, 2]=time) then
      begin
        inc(active_count);
        active[i]:=true;
      end;

    // если есть активные процессы
    if (active_count > 0) then
    begin
      if (kvant = 0) then
      begin
        // если процесс выполнялся и выполнился
        if (aktivny > 0) and (process[aktivny, 1] = 0) then
        begin
          // снимаем отметку активности
          active[aktivny] := false;
          dec(active_count);
          // уменьшаем счетчик оставшихся процессов
          dec(ostalos);
        end;
        // если больше активных нет
        if (active_count = 0) then
            // значение 0 - значит нет активного процесса
            aktivny := 0
        else
        begin
          // переходим к следующему
          repeat
            // mod - остаток деления нацело
            // фактически ищем "по кругу" следующий активный процесс
            aktivny := aktivny mod N + 1;
          // условин  прерывания цикла
          until (active[aktivny]);
          // если CPU Burst меньше длины кванта, то
          // промежуток активности будет равен CPU Burst
          kvant := min(kvant_size, process[aktivny, 1]);
        end;
      end;
    end;

    // обрабатываем выполняющийся процесс
    if (aktivny > 0) then
    begin
      // увеличиваем счетчик времени выполнения
      inc(vipoln);
      // уменьшаем CPU Burst и квант
      dec(process[aktivny,1]);
      dec(kvant);
      // пишем в таблицу исполняющийся процесс
      StringGrid2.Cells[time+1, aktivny] := 'И';
    end;

    // обрабатываем процессы в состоянии ожидания
    for i:=1 to N do
      // если процесс в состоянии ожидания
      if (active[i]) and (aktivny <> i) then
      begin
        // увеличиваем счетчик времени выполнения
        inc(vipoln);
        // пишем в таблицу
        StringGrid2.Cells[time+1, i] := 'Г';
        // увеличиваем время ожидания
        inc(ozhid);
      end;
    // пишем заголовок таблицы
    StringGrid2.Cells[time+1, 0] := IntToStr(time); // номер столбца
    inc(time); // увеличить время
  end;
  StringGrid2.ColCount := time;
  Label2.Caption := 'Среднее время выполнения: ' + FloatToStr(vipoln/N) + #10#13 +
                    ' среднее время ожидания: ' + FloatToStr(ozhid/N);
end;

procedure TForm1.Edit1Change(Sender: TObject);
var i: integer;
begin
  // изменить размер таблиц
  N := UpDown1.Position;
  StringGrid1.RowCount := N + 1;
  StringGrid2.RowCount := N + 1;
  // заполнить вертикальный заголовок таблиц
  for i:=1 to N do
  begin
    StringGrid1.Cells[0, i] := IntToStr(i);
    StringGrid2.Cells[0, i] := StringGrid1.Cells[0, i];
  end;
end;


procedure TForm1.FormCreate(Sender: TObject);
var i: Integer;
begin
  N := UpDown1.Position;
  // заполняем горизонтальный заголовок
  StringGrid1.Cells[0, 0] := '№';
  StringGrid1.Cells[1, 0] := 'CPU Burst';
  StringGrid1.Cells[2, 0] := 'Появится';
  // заполняем вертикальный заголовок
  for i:=1 to N do
    StringGrid1.Cells[0, i] := IntToStr(i);
end;

end.
