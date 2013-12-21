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

procedure TForm1.Button1Click(Sender: TObject);
var i, vremya: integer; // счетчик и текущее времм€
    act: array[1..100] of integer; // активные
    actCnt: integer; // кол-во активных

    // все данные процессов: CPUburst, по€вление, приоритет
    processes: array[1..100, 1..3] of integer;  // ** заменить 1..3 на 1..2 **

    ostalos: integer; // осталось выполнить процессов
    active: integer; // индекс активного в act

    exectime: integer;   // врем€ выполнени€
    wait: integer;   // врем€ ожидани€
begin
  // читаем данные
  for i:=1 to N do
  begin
    processes[i,1] := StrToInt(StringGrid1.Cells[1, i]);
    processes[i,2] := StrToInt(StringGrid1.Cells[2, i]);
    processes[i,3] := StrToInt(StringGrid1.Cells[3, i]); //  ** убрать ** 
  end;

  vremya:=0;
  actCnt := 0;
  ostalos := N;
  active := -1;
  exectime := 0;
  wait := 0;
  while (ostalos > 0) do
  begin
    // провер€ем новые процессы
    for i:=1 to N do
      if (processes[i, 2]=vremya) then
      begin
        inc(actCnt);
        act[actCnt]:=i;
      end;
    // переключение
    //  если есть активные процессы
    if (actCnt>0) then
    begin
      // если процесс выполнилс€
      // удал€ем тот, что кончилс€
      if ((active <> -1) and (processes[act[active], 1]=0)) then
      begin
        for i:=active to actCnt-1 do
          act[i] := act[i+1];
        dec(actCnt);
        dec(ostalos);
      end;
      // находим наименьший из активных, запоминаем его как выполн€ющийс€
      active := 1;
      for i:=2 to actCnt do
        if (processes[act[active],3] > processes[act[i],3]) then // ** заменить 3 на 1 ** 
          active:=i;
    end;
    // очищаем текущий столбец
    for i:=1 to N do
      StringGrid2.Cells[vremya+1, i] := '';
    for i:=1 to actCnt do
    begin
      exectime := exectime+1;
      // если это выполн€ющийс€ процесс
      if (i=active) then
      begin
        StringGrid2.Cells[vremya+1, act[i]] := '»';
        dec(processes[act[active],1]); // активный выполнилс€, уменьшаем CPUburst
      end
      else // иначе готовый процесс
      begin
        StringGrid2.Cells[vremya+1, act[i]] := '√';
        wait := wait+1;
      end;
    end; 
    StringGrid2.Cells[vremya+1, 0] := IntToStr(vremya); // номер столбца
    inc(vremya); // увеличить врем€
  end;
  StringGrid2.ColCount := vremya;
  Label2.Caption := '—реднее врем€ выполнени€: ' + FloatToStr(exectime/N) + #10#13 +
                    'среднее врем€ ожидани€: ' + FloatToStr(wait/N);
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
  // заполн€ем горизонтальный заголовок
  StringGrid1.Cells[0, 0] := 'Ќомер';
  StringGrid1.Cells[1, 0] := 'CPU Burst';
  StringGrid1.Cells[2, 0] := '¬рем€ по€влени€';   
  StringGrid1.Cells[3, 0] := 'ѕриоритет'; // ** убрать **
  // заполн€ем вертикальный заголовок
  for i:=1 to N do
    StringGrid1.Cells[0, i] := IntToStr(i);
end;

end.
