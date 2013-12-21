uses
  SysUtils, testlib;

const
  MAX = 1500;
  LIMIT = '9223372036854775807';

type
  int = longint;

function less(a, b: string): boolean;
begin
  result := (length(a) < length(b)) or ((length(a) = length(b)) and (a < b));
end;

function square(a: string): string;
var
  i, j, k, add, dig: int;
begin
  result := '';
  for i := 1 to 2 * length(a) do
    result := result + '0';
  for i := 1 to length(a) do for j := 1 to length(a) do
  begin
    k := i + j;
    add := (ord(a[i]) - ord('0')) * (ord(a[j]) - ord('0'));
    while (add > 0) do
    begin
      dig := ord(result[k]) - ord('0') + add;
      add := dig div 10;
      result[k] := chr(ord('0') + dig mod 10);
      dec(k);
    end;
  end;
  while (length(result) > 1) and (result[1] = '0') do
    result := copy(result, 2, length(result) - 1);
end;

function subtract(a, b: string): string;
var
  i, p, dig: int;
begin
  result := '';
  while (length(b) < length(a)) do
    b := '0' + b;
  while (length(result) < length(a)) do
    result := '0' + result;
  p := 0;
  for i := length(a) downto 1 do
  begin
    dig := ord(a[i]) - ord(b[i]) - p;
    p := 0;
    if (dig < 0) then
    begin
      inc(dig, 10);
      p := 1;
    end;
    result[i] := chr(ord('0') + dig);
  end;
  while (length(result) > 1) and (result[1] = '0') do
    result := copy(result, 2, length(result) - 1);
end;

function divides(a, b: string): boolean;
var
  c: string;
begin
  if less(a, b) then
  begin
    result := false;
    exit;
  end;
  c := b;
  repeat
    while (not less(a, c)) do
      c := c + '0';
    c := copy(c, 1, length(c) - 1);
    if (length(c) < length(b)) then
    begin
      result := false;
      exit;
    end;
    while (not less(a, c)) do
    begin
      if (c = a) then
      begin
        result := true;
        exit;
      end;
      a := subtract(a, c);
    end;
  until false;
end;

var
  n, i, j: int;
  a, b: array[1..MAX] of string;

begin
  n := inf.readlongint;

  for i := 1 to n do
  begin
    a[i] := ouf.readword(BLANKS, BLANKS);
    for j := 1 to length(a[i]) do
    begin
      if (a[i][j] < '0') or (a[i][j] > '9') then
        quit(_PE, format('"' + a[i] + '" не является натуральным числом (строка номер %d)', [i]));
    end;
    if (a[i] = '') then
      quit(_PE, format('Обнаружена пустая строка (строка номер %d)', [i]));
    if (a[i] = '0') then
      quit(_PE, format('Ноль не является натуральным числом (строка номер %d)', [i]));
    if (a[i][1] = '0') then
      quit(_PE, format('В строке "' + a[i] + '" есть ведущие нули (строка номер %d)', [i]));
  end;
  ouf.skip(BLANKS);
  if not ouf.eof then
    quit(_PE, 'Количество чисел в выходном файле больше N');

  for i := 1 to n do
  begin
    if less(LIMIT, a[i]) then
      quit(_WA, format('Число номер %d больше 2^63-1 (%s)', [i, a[i]]));
    b[i] := square(a[i]);
  end;

  for i := 1 to n do
  begin
    writeln(i);
    for j := 1 to n do
    begin
      if (i = j) then
        continue;
      if (a[i] = a[j]) then
        quit(_WA, format('Число %s встречается два раза (строки номер %d и %d)', [a[i], i, j]));
      if (divides(a[i], a[j])) then
        quit(_WA, format('Число %s (строка номер %d) делится на %s (строка номер %d)', [a[i], i, a[j], j]));
      if (not divides(b[i], a[j])) then
        quit(_WA, format('Число %s (строка номер %d) в квадрате не делится на %s (строка номер %d)', [a[i], i, a[j], j]));
    end;
  end;

  quit(_OK, format('%d чисел', [n]));
end.