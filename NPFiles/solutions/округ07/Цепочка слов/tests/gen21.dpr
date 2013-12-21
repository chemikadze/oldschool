{$r+,q+,o-}
{$apptype console}
uses
  SysUtils;

type
    int = longint;

const
    MAXS = 250000;
    N = 62500;
    K = 100;

var
    i, count : int;
    str: array[1..N] of string;
    a, b, c, d: char;

begin
    count := 0;
    for a := 'a' to 'z' do
      for b := 'a' to 'z' do
        for c := 'a' to 'z' do
          for d := 'a' to 'z' do
          begin
            if (count < n) then
            begin
              count := count + 1;
              str[count] := a + b + c + d;
            end;
          end;

    writeln(N);

    str[2] := 'xyzwt';
    str[1] := 'xy';
    str[3] := 'x';

    for i := 1 to N do begin
        writeln(str[i]);
    end;

    writeln(K);
    for i := 1 to K - 3 do begin
        write(random(N) + 1);
        write(' ');
    end;
    write(3, ' ', 1, ' ', 2);
    writeln;
end.
