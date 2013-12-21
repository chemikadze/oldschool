const MAX_N = 1000;
var
  i: integer;
begin
  writeln(MAX_N);
  for i := 1 to MAX_N do begin
    writeln(i - 1, ' ', i - 1, ' ', i, ' ', i);
  end;
  writeln('1 1');
  writeln(MAX_N, ' ', MAX_N);
end.