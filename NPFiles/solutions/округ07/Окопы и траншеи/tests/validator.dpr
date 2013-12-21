{$r+,q+,o-}
{$apptype console}
uses
    SysUtils;

type
    int = longint;

const
    MAXS = 500;

procedure quit(s: string);
begin
    writeln(s);
    halt(239);
end;

var
    n, i, j, x, y: int;
    x1, y1, x2, y2: array [1..MAXS] of int;
    s: string;

begin
    reset(input, 'trench.in');
    readln(n);
    if ((n < 1) or (n > MAXS)) then
        quit('Invalid ''n''');

    for i := 1 to n do
    begin
      readln(x1[i], y1[i], x2[i], y2[i]);
      if (x1[i] >= x2[i]) or (y1[i] >= y2[i]) then
          quit('Singular or incorrect trench #' + IntToStr(i));
      if (x1[i] < -10000) or (y1[i] < -10000) or (x2[i] > 10000) or (y2[i] > 10000) then
          quit('Trench is out of bound #' + IntToStr(i));
    end;

    for i := 1 to n do
      for j := i + 1 to n do
      begin
        if (x1[i] < x2[j]) and (x1[j] < x2[i]) and
          ((y1[i] = y1[j]) or (y1[i] = y2[j]) or (y2[i] = y1[j]) or (y2[i] = y2[j])) then
          quit('Intersection with non-zero length between #' + IntToStr(i) + ' and #' + IntToStr(j));
        if (y1[i] < y2[j]) and (y1[j] < y2[i]) and
          ((x1[i] = x1[j]) or (x1[i] = x2[j]) or (x2[i] = x1[j]) or (x2[i] = x2[j])) then
          quit('Intersection with non-zero length between #' + IntToStr(i) + ' and #' + IntToStr(j));
      end;

    readln(x, y);
    for i := 1 to n + 1 do
    begin
      if i = n + 1 then
        quit('Point A is not in trench');
      if (x1[i] <= x) and (x2[i] >= x) and (y1[i] <= y) and (y2[i] >= y) and
        ((x1[i] = x) or (x2[i] = x) or (y1[i] = y) or (y2[i] = y)) then
        break;
    end;    

    readln(x, y);
    for i := 1 to n + 1 do
    begin
      if i = n + 1 then
        quit('Point B is not in trench');
      if (x1[i] <= x) and (x2[i] >= x) and (y1[i] <= y) and (y2[i] >= y) and
        ((x1[i] = x) or (x2[i] = x) or (y1[i] = y) or (y2[i] = y)) then
        break;
    end;

    writeln('OK');
end.
