{$r+,q+,o-}
{$apptype console}
type
    int = longint;

const
    N = 250000;
    K = 250000;

var
    i: int;

begin
    randseed := 23932432;
    writeln(N);
    writeln('a');
    for i := 2 to N do begin
        writeln(chr(random(26) + ord('a')));
    end;
    //writeln('aa');

    writeln(K);
    for i := 1 to K do begin
        if (i = K div 2) then begin
            write(1);
        end else if (i = K div 2 + 1) then begin
            write(N);
        end else begin
            write(random(N) + 1);
        end;

        if (i <> K) then
            write(' ');
    end;
    writeln;
end.
