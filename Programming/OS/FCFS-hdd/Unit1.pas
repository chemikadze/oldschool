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
    Label3: TLabel;
    Label4: TLabel;
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
var i: integer;   // счетчик
    time, dt: integer; // время работы, время переключения между соседними
    position, next: integer; // тек. позиция, следующий
    count: integer;  // кол-во запросов
begin
  dt := StrToInt(Edit2.Text); // чтение и
  time := 0;                  // инициация переменных
  count := UpDown1.Position;
  position := StrToInt(StringGrid1.Cells[0, 0]);
  StringGrid2.Cells[0,0] := IntToStr(position); // записываем нач. позицию в вывод
  for i:=1 to count-1 do  // последовательно переходим по всем запросам
  begin
    next := StrToInt(StringGrid1.Cells[i, 0]); // читаем запрос
    time := time + abs(position-next); // увеличиваем счетчик времени
    position := next;  // переходим
    StringGrid2.Cells[i, 0] := IntToStr(position); // записываем в вывод
  end;
  time := time * dt; // домножаем на время перехода между дорожками
  Label4.Caption := 'Время перемещения головки жесткого диска: ' + IntToStr(time) + ' мс.';
end;

end.
