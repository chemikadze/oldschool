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

procedure TForm1.FormCreate(Sender: TObject);
var i: Integer;
begin
  N := UpDown1.Position;
  // заполняем горизонтальный заголовок
  StringGrid1.Cells[0, 0] := 'Номер';
  StringGrid1.Cells[1, 0] := 'CPU Burst';
  StringGrid1.Cells[2, 0] := 'Время появления';
  StringGrid1.Cells[3, 0] := 'Приоритет';
  // заполняем вертикальный заголовок
  for i:=1 to N do
    StringGrid1.Cells[0, i] := IntToStr(i);
end;

procedure TForm1.Button1Click(Sender: TObject);
var i, t: integer; // счетчик и текущее времмя
    a: array[1..100] of integer; // активные
    aC: integer; // кол-во активных

    // все данные процессов, CPUburst и появление
    p: array[1..100, 1..3] of integer;

    left: integer; // осталось выполнить процессов
    active: integer; // индекс активного в A

    eT: real;   // время выполнения
    wT: real;   // время ожидания
begin
  // читаем данные
  for i:=1 to N do
  begin
    try
      p[i,1] := StrToInt(StringGrid1.Cells[1, i]);
      p[i,2] := StrToInt(StringGrid1.Cells[2, i]); 
      p[i,3] := StrToInt(StringGrid1.Cells[3, i]);
    except
      ShowMessage('Неправильные данные!');
      exit;
    end;
  end;

  t:=0;
  aC := 0;
  left := N;
  active := -1;
  eT := 0;
  wT := 0;
  while (left > 0) do
  begin
    // проверяем новые процессы
    for i:=1 to N do
      if (p[i, 2]=t) then
      begin
        inc(aC);
        a[aC]:=i;
      end;
    // переключение
    //  если процессы еще не выполнялись или процесс выполнился и при этом всем
    //  есть активные процессы
    if (((active = -1) or (p[a[active],1] = 0)) and (aC>0)) then
    begin
      // если процесс выполнился
      // удаляем тот, что кончился
      if (active <> -1) then
      begin
        for i:=active to aC-1 do
          a[i] := a[i+1];
        dec(aC);
        dec(left);
      end;
      // находим наименьший приоритет из активных, запоминаем его как выполняющийся
      active := 1;
      for i:=2 to aC do
        if (p[a[active],3] > p[a[i],3]) then
          active:=i;
    end;
    // очищаем текущий столбец
    for i:=1 to N do
      StringGrid2.Cells[t+1, i] := '';
    for i:=1 to aC do
    begin
      eT := eT+1;
      // если это выполняющийся процесс
      if (i=active) then
      begin
        StringGrid2.Cells[t+1, a[i]] := 'И';
        dec(p[a[active],1]); // активный выполнился, уменьшаем CPUburst
      end
      else // иначе готовый процесс
      begin
        StringGrid2.Cells[t+1, a[i]] := 'Г';
        wT := wT+1;
      end;
      StringGrid2.Cells[t+1, 0] := IntToStr(t); // номер столбца
    end;
    inc(t); // увеличить время
  end;
  StringGrid2.ColCount := t;
  Label2.Caption := 'Среднее время выполнения: ' + FloatToStr(eT/N) + #10#13 +
                    'среднее время ожидания: ' + FloatToStr(wT/N);
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

end.
