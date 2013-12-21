unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    Button1: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    UpDown1: TUpDown;
    Edit2: TEdit;
    Label2: TLabel;
    Edit4: TEdit;
    Edit5: TEdit;
    Label4: TLabel;
    UpDown2: TUpDown;
    UpDown3: TUpDown;
    Label5: TLabel;
    Button2: TButton;
    Label6: TLabel;
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
  StringGrid1.ColCount := NewValue;
  StringGrid2.ColCount := NewValue;
end;


procedure TForm1.Button1Click(Sender: TObject);
var query: array [1..100] of integer; // дорожки которые нужно прочитать
    position, startI: integer; // позиция головки и номер в списке запросов с к-рого начнем
    i, j, b: integer; // счетчики и буфер для обмена переменных
    time, timeMove: integer; // время (ответ), время для перемещения на 1
    cylCount: integer; // кол-во дорожек(цилиндров)
    queryCount: integer; // кол-во запросов
    outPos: integer;  // позиция в выводе
begin
  outPos := 0;  // инициализация переменных
  time := 0;
  position := UpDown2.Position;
  cylCount := UpDown3.Position;
  queryCount := UpDown1.Position;
  timeMove := StrToInt(Edit2.Text);
  for i:=1 to queryCount do    // чтение запросов
    query[i] := StrToInt(StringGrid1.Cells[i-1, 0]);
  if (Sender = Button1) then   // если нажали на кнопку "уменьш"
  begin
   // <-
    for i:=queryCount downto 2 do  // сортировка пузырьком по убыванию
      for j:=1 to i-1 do
        if query[j]<query[j+1] then
        begin
          b := query[j];
          query[j] := query[j+1];
          query[j+1] := b;
        end;
    startI := queryCount;         // находим начальную позицию в списке
    for i:=1 to queryCount do
      if query[i]<=position then
      begin
        startI := i;
        break;
      end;
    end
  else
  begin // ->                // иначе нажали на кнопку "увелич"
    for i:=queryCount downto 2 do  // соритировка пузырькм по возрастанию
      for j:=1 to i-1 do
        if query[j]>query[j+1] then
        begin
          b := query[j];
          query[j] := query[j+1];
          query[j+1] := b;
        end; 
    startI := queryCount;       // находим начальную позицию в списке
    for i:=1 to queryCount do
      if query[i]>=position then
      begin
        startI := i;
        break;
      end;
  end;

  // выводим начальную позицию головки
  StringGrid2.Cells[outPos, 0] := IntToStr(position);
  inc(outPos);

  // проходим по "попутным" дорожкам
  for i:=startI to queryCount do
  begin
    time := time + timeMove*abs(position-query[i]);
    position := query[i];
    StringGrid2.Cells[outPos, 0] := IntToStr(position);
    inc(outPos);
  end;

  // если есть дорожки не "по пути", т.е. нужно выполнить разворот
  if (startI <> 1) then
  begin
    // если двигались в сторону уменьшения
    if (sender = Button1) then
    begin
      // доходим до левого края
      time := time + timeMove*position;
      position := 0;
      // записываем перемещение
      StringGrid2.Cells[outPos, 0] := IntToStr(position);
      inc(outPos);
      // переходим на правый
      time := time + cylCount-1;
      position := cylCount-1;
    end
    else // иначе
    begin
      // доходим до правого края
      time := time + timeMove*abs(cylCount-position-1);
      position := CylCount-1;   
      // записываем перемещение
      StringGrid2.Cells[outPos, 0] := IntToStr(position);
      inc(outPos);
      // переходим на левый
      time := time + timeMove*abs(position);
      position := 0;
    end;
    // записываем перемещение
    StringGrid2.Cells[outPos, 0] := IntToStr(position);
    inc(outPos);
  end;

  // перескочили, продолжаем
  for i:=1 to StartI-1 do
  begin
    time := time + timeMove*abs(position-query[i]);
    position := query[i];
    StringGrid2.Cells[outPos, 0] := IntToStr(position);
    inc(outPos);
  end;
  // выводим время перемещения
  Label6.Caption := 'Время перемещения: '+IntToStr(time) + ' мс';
  StringGrid2.ColCount := outPos;
end;

end.
