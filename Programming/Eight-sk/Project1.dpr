program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  B: text;
  _i, k: integer;
  hor: string;
  ChessDesk: array [1..8, 1..8] of integer;
  jt: array[1..8] of integer;

function ControlFields(i, j: integer): boolean;
var n, m: integer;
begin
  for n:=1 to 8 do
    if (n <> j) and (ChessDesk[i, n] = 8) then
    begin
      ControlFields := false;
      exit;
    end;

  for n:=1 to 8 do
    if (n <> i) and (ChessDesk[n, j] = 8) then
    begin
      ControlFields := false;
      exit;
    end;

  n := i;
  m := j;
  while (n < 8) and (m > 1) do
  begin
    inc(n);
    dec(m);
    if (ChessDesk[n, m] = 8) then
    begin
      ControlFields := false;
      exit;
    end;
  end;

  n := i;
  m := j;
  while (n < 8) and (m < 8) do
  begin
    inc(n);
    inc(m);
    if (ChessDesk[n, m] = 8) then
    begin
      ControlFields := false;
      exit;
    end;
  end;

  n := i;
  m := j;
  while (n > 1) and (m < 8) do
  begin
    dec(n);
    inc(m);
    if (ChessDesk[n, m] = 8) then
    begin
      ControlFields := false;
      exit;
    end;
  end;

  n := i;
  m := j;
  while (n >1) and (m > 1) do
  begin
    dec(n);
    dec(m);
    if (ChessDesk[n, m] = 8) then
    begin
      ControlFields := false;
      exit;
    end;
  end;

  ControlFields := true;
end;


function ControlPosition: boolean;
var i, j: integer;
begin
  for i:=1 to 8 do
    for j:=1 to 8 do
    begin
      if (ChessDesk[i, j] <> 8) then
        continue;
      if (not ControlFields(i, j)) then
      begin
        ControlPosition := false;
        exit;
      end;
    end;
  ControlPosition := true;
end;

procedure DefineColumn(j: integer);
var i, n: integer;
begin
  for i:=1 to 8 do
  begin
    ChessDesk[i, j] := 8;
    jt[j] := i;
    if (j < 8) then
      DefineColumn(j+1)
    else
      if (ControlPosition()) then
      begin
        inc(k);
        write(B, k);
        for n := 1 to 8 do
          write(B, '  ', hor[n], jt[n]);
        writeln(B);
      end;
    ChessDesk[i, j] := 0;
  end;
end;

begin
  assign(B, 'result.txt');
  rewrite(B);
  for _i:=1 to 8 do
    jt[_i] := 0;
  k := 0;
  hor := 'abcdefgh';
  writeln('Начинаем расчет...');
  DefineColumn(1);
  writeln('Расчет закончен.');
  close(B);
end.
