program ddd;
type ta=array[1..100, 1..100] of integer;
     tb=array[1..100] of integer;
var a: ta;
    ans: tb;
    n: integer;
    i, j: integer;

procedure sum(const ar: ta; var s: tb);
var i, j, k: integer;
begin
  for i:=1 to n do
  begin
    s[i]:=0;
    for j:=1 to n-i+1 do
      s[i]:=s[i]+ar[j+i-1, j];
  end;
end;

begin
  write('Enter size of the matrix: ');
  read(n);
  writeln('Enter matrix:');
  for i:=1 to n do
    for j:=1 to n do
      read(a[i, j]);
  sum(a, ans);
  writeln('Sums are: ');
  for i:=1 to n do
    write(ans[i], ' ');
  writeln;
  readln;
end.
