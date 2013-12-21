program eee;
type ts=array [1..100, 1..100] of real;
var s:ts;
    t:array [1..100] of real;
    n:integer;
    i, j: integer;
    mi, mj: integer;

procedure ind(const a: ts; var x, y: integer);
begin
  x:=1;
  y:=1;
  for i:=1 to n do
    for j:=1 to n do
      if (a[x, y]>a[i, j]) then
      begin
        x:=i;
        y:=j;
      end;
end;

begin
  write('Enter size of the matrix: ');
  read(n);
  for i:=1 to n do
    for j:=1 to n do
      read(s[i, j]);
  ind(s, mi, mj);
  for i:=1 to n do
    t[i]:=s[mi, i]+s[i, mj];
  writeln('array T: ');
  for i:=1 to n do
    write(t[i]:5:3, ' ');
  readln;
end.
