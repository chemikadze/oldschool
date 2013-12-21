uses
  SysUtils, testlib;

const
  MAXM = 250000;
  MAXLEN = 250000;
  MAXK = 250000;

type
  int = longint;

var
  m, k, i, j: int;
  s: array[1..MAXM] of string;
  x: array[1..MAXK] of int;
  a, b: string;
  cl, cr, cn, jl, jr, jn: int;

begin
  m := inf.readlongint;
  for i := 1 to m do
  begin
    s[i] := inf.readword(BLANKS, BLANKS);
  end;
  k := inf.readlongint;
  for i := 1 to k do
  begin
    x[i] := inf.readlongint;
  end;

  cl := ouf.readlongint;
  cr := ouf.readlongint;
  if (cl < 1) or (cl > k) then
    quit(_wa, format('Число l вне интервала 1..k: %d', [cl]));
  if (cr < 1) or (cr > k) then
    quit(_wa, format('Число r вне интервала 1..k: %d', [cr]));
  if (cl > cr) then
    quit(_wa, format('Неправильные границы отрезка: l = %d, r = %d', [cl, cr]));

  for i := cl to cr - 1 do
  begin
    a := s[x[i]];
    b := s[x[i + 1]];
    if (length(a) >= length(b)) then
      quit(_wa, format('Слово номер x[%d]=%d не является собственным префиксом слова номер x[%d]=%d: первое не короче второго', [i, x[i], i + 1, x[i + 1]]));
    for j := 1 to length(a) do
      if (a[j] <> b[j]) then
        quit(_wa, format('Слово номер x[%d]=%d не является собственным префиксом слова номер x[%d]=%d: различие в %d-м символе', [i, x[i], i + 1, x[i + 1], j]));
  end;

  jl := ans.readlongint;
  jr := ans.readlongint;

  cn := cr - cl + 1;
  jn := jr - jl + 1;
  if (cn < jn) then
    quit(_wa, format('Количество слов в цепочке не максимально (%d, когда можно %d)', [cn, jn]));
  if (cn > jn) then
    quit(_fail, format('Лучше, чем у жюри! (%d вместо %d)', [cn, jn]));
  jn := jn mod 100;
  if (jn mod 10 = 1) and (jn <> 11) then
    quit(_ok, format('Цепочка из %d слова', [cn]));
  quit(_ok, format('Цепочка из %d слов', [cn]));
end.