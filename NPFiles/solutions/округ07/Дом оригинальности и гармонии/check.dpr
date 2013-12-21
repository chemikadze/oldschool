uses
  SysUtils, testlib;

type
  int = longint;

const
  MAX = 1500;
  LIMIT = '9223372036854775807';
  PRIMES = 15;
  PRIME: array[1..PRIMES] of int = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47);
     {а еще (53, 59, 61, 67, 71, 73, 79, 83, 89, 97, ...);}

type
  bigint = record
    p: array[1..PRIMES] of int;
    r: string;
  end;

function int64tostr(v: int64): string;
begin
  result := '';
  while (v > 0) do
  begin
    result := chr(ord('0') + v mod 10) + result;
    v := v div 10;
  end;
  if (result = '') then
    result := '0';
end;

function toBigInt(a: string): bigint;
var
  ten, val: int64;
  i: int;
begin
  ten := 1;
  val := 0;
  for i := length(a) downto 1 do
  begin
    val := val + (ord(a[i]) - ord('0')) * ten;
    if (i > 1) then
      ten := 10 * ten;
  end;
  for i := 1 to PRIMES do
  begin
    result.p[i] := 0;
    while (val mod PRIME[i] = 0) do
    begin
      val := val div PRIME[i];
      inc(result.p[i]);
    end;
  end;
  result.r := int64tostr(val);
end;

function _less(a, b: string): boolean;
begin
  result := (length(a) < length(b)) or ((length(a) = length(b)) and (a < b));
end;

function _square(a: string): string;
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

function square(a: bigint): bigint;
var
  i: int;
begin
  for i := 1 to PRIMES do
  begin
    result.p[i] := 2 * a.p[i];
  end;
  result.r := _square(a.r);
end;

function _subtract(a, b: string): string;
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

function _divides(a, b: string): boolean;
var
  c: string;
begin
  if (b = '1') then
  begin
    result := true;
    exit;
  end;
  if _less(a, b) then
  begin
    result := false;
    exit;
  end;
  c := b;
  repeat
    while (not _less(a, c)) do
      c := c + '0';
    c := copy(c, 1, length(c) - 1);
    if (length(c) < length(b)) then
    begin
      result := false;
      exit;
    end;
    while (not _less(a, c)) do
    begin
      if (c = a) then
      begin
        result := true;
        exit;
      end;
      a := _subtract(a, c);
    end;
  until false;
end;

function divides(a, b: bigint): boolean;
var
  i: int;
begin
  result := false;
  for i := 1 to PRIMES do
  begin
    if (a.p[i] < b.p[i]) then
    begin
      exit;
    end;
  end;
  result := _divides(a.r, b.r);
end;

var
  n, i, j: int;
  a: array[1..MAX] of string;
  b, c: array[1..MAX] of bigint;

begin
  n := inf.readlongint;

  for i := 1 to n do
  begin
    ouf.skip(BLANKS);
    if ouf.eof then
      quit(_PE, 'Количество чисел в выходном файле меньше N');
    a[i] := ouf.readword(BLANKS, BLANKS);
    for j := 1 to length(a[i]) do
    begin
      if (a[i][j] < '0') or (a[i][j] > '9') then
        quit(_PE, format('"' + a[i] + '" не является положительным целым числом (%d-я комната)', [i]));
    end;
    if (a[i] = '0') then
      quit(_WA, format('%d-я комната имеет нулевой размер', [i]));
    if (a[i][1] = '0') then
      quit(_PE, format('В числе "' + a[i] + '" есть ведущие нули (%d-я комната)', [i]));
  end;
  ouf.skip(BLANKS);
  if not ouf.eof then
    quit(_PE, 'Количество чисел в выходном файле больше N');

  for i := 1 to n do
  begin
    if _less(LIMIT, a[i]) then
      quit(_WA, format('Число номер %d больше 2^63-1 (%s)', [i, a[i]]));
    b[i] := toBigInt(a[i]);
    c[i] := square(b[i]);
  end;

  for i := 1 to n do
  begin
    for j := 1 to n do
    begin
      if (i = j) then
        continue;
      if (a[i] = a[j]) then
        quit(_WA, format('Число %s встречается два раза (%d-я и %d-я комната)', [a[i], i, j]));
      if (divides(b[i], b[j])) then
        quit(_WA, format('Число %s (%d-я комната) делится на %s (%d-я комната)', [a[i], i, a[j], j]));
      if (not divides(c[i], b[j])) then
        quit(_WA, format('Число %s (%d-я комната) в квадрате не делится на %s (%d-я комната)', [a[i], i, a[j], j]));
    end;
  end;

  i := n mod 100;
  if (i mod 10 = 1) and (i <> 11) then
    quit(_OK, format('%d комната', [n]));
  if (i mod 10 >= 2) and (i mod 10 <= 4) and ((i < 10) or (i > 20)) then
    quit(_OK, format('%d комнаты', [n]));
  quit(_OK, format('%d комнат', [n]));
end.