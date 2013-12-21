{$r+,q+,o-}
{$apptype console}
type
    int = longint;

const
    MAXS = 250000;
    N = 10;
    PREFIX = 20000;
    SUFFIX = 20000;
    BOTVA_WORDS = 6000;
    K = 15000;

var
    pref : string;
    i, j, r : int;
    suff : string;
    str: array [1..MAXS] of string;
    p, pp: array [1..MAXS] of int;

procedure shuffle(n: int);
var
    i: int;

begin
    for i := 1 to n do begin
        j := random(i) + 1;
        p[i] := p[j];
        p[j] := i;
    end;
    for i := 1 to n do begin
        pp[p[i]] := i;
    end;
end;

begin
    randseed := 35331242;
    for i := 1 to PREFIX do begin
        pref := pref + chr(ord('a') + random(26));
    end;
    for i := 1 to SUFFIX do begin
        suff := suff + chr(ord('a') + random(26));
    end;

    writeln(N + BOTVA_WORDS);
    for i := 1 to N do begin
        str[i] := pref;
        r := ((1 * i) mod SUFFIX) + 1;
        for j := 1 to r do begin
            str[i] := str[i] + suff[j];
        end;
    end;

    for i := 1 to BOTVA_WORDS do begin
        str[N + i] := '';
        for j := 1 to 3 do
            str[N + i] := str[N + i] + chr(ord('a') + random(26));
    end;

    shuffle(N + BOTVA_WORDS);
    for i := 1 to N + BOTVA_WORDS do begin
        writeln(str[p[i]]);
    end;

    writeln(K);
    for i := 1 to K do begin
        if (random(BOTVA_WORDS) = 0) then begin
            write(pp[N + random(BOTVA_WORDS) + 1]);
        end else begin
            write(pp[i mod N + 1]);
        end;

        if (i <> K) then
            write(' ');
    end;
    writeln;
end.
