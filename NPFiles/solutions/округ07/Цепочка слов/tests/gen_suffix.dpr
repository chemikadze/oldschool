{$r+,q+,o-}
{$apptype console}
uses
    SysUtils;

type
    int = longint;

const
    N = 700;
    K = 250000;

var
    mult, i, j: int;
    suff: string;

begin
    mult := strtoint(paramstr(1));

    randseed := 65461243;
    for i := 1 to N do begin
        suff := suff + chr(ord('a') + random(26));
    end;

    writeln(N);
    for i := 1 to N do begin
        for j := 1 to i do begin
            write(suff[j]);
        end;
        writeln;
    end;

    writeln(K);
    for i := 1 to K do begin
        write((mult * i) mod N + 1);
        if (i <> K) then
            write(' ');
    end;
    writeln;
end.
