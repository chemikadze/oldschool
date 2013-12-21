program bbb;
var x, y : array [1..100] of real;
    my : real;
    i, N, k, m: integer;
begin
  m:=0;
  k:=0;
  my:=0;
  write('Enter count of the points: ');
  readln(N);
  write('Enter abscisses of the points: ');
  for i:=1 to N do
    read(x[i]);
  write('Enter ordinates of the points: ');
  for i:=1 to N do
    read(y[i]);
  for i:=1 to N do
    if ( (x[i] > 0) and (y[i] > 0) ) then
      k:=k+1
    else
    begin
      m:=m+1;
      my:=my+y[i];
    end;
  writeln('Count of points: ', k);
  if (m<>0) then
    writeln('Medium ordinat is: ', my/m:10:5)   {вывод в поле 10 символов, 5 знаков после запятой}
  else
    writeln('There is no such points');
  readln;
end.
