program aaa;
var a, b: array[1..100, 1..100] of integer;
    N, M: integer;       { N - strok, M - stolbcov }
    i, j: integer;
begin
  write('Enter size of matrix (N and M): ');
  read(N, M);
  writeln('Enter matrix:');
  for i:=1 to N do
    for j:=1 to M do
      read(a[i, j]);

  for i:=1 to N do
    for j:=1 to M do
      if (a[i, j] < 0) then
        if (j > 1) then
          b[i, j]:=a[i, j-1]+a[i, j]
        else
          b[i, 1]:=a[i, 1]+a[i, M]
      else
          b[i, j]:=a[i, j];
  writeln;
  for i:=1 to N do
  begin
    for j:=1 to M do
      write(b[i, j], ' ');
    writeln;
  end;
  readln;
end.
