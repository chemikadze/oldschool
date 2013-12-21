program ccc;
type tA=array [1..4, 1..5] of integer;
var d, e: tA;
    i, j: integer;

function maxArray(const a: tA; f, t: integer):integer;
var mv, i, j: integer;
begin
  mv:=a[f, 1];
  for i:=f to t do
    for j:=1 to 5 do
      if (a[i, j] > mv) then
        mv:=a[i, j];
  maxArray:=mv;
end;

begin
  writeln('Enter matrix D (4x5): ');
  for i:=1 to 4 do
    for j:=1 to 5 do
      read(d[i, j]);
  writeln('Enter matrix E (3x5): ');
  for i:=1 to 3 do
    for j:=1 to 5 do
      read(e[i, j]);
  writeln('Max for D (from 1 to 3): ', maxArray(d, 1, 3));
  writeln('Max for E (from 2 to 3): ', maxArray(e, 2, 3));
  readln;
end.