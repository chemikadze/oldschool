{ Повторяющиеся простые числа   }
{ Взятие части слоя             }

{$q+,r+}
var
    z: array [1..16] of longint = (2,2,2,3,3,3,5,5,7,7,11,13,17,19,23,29);

    maxint64: int64;
    u: array [0..65535] of boolean;
    n, m: longint;

function value(v: longint): int64;
var
    i: longint;
begin
    result := 1;
    for i := 0 to n - 1 do begin
        if ((v shr i) and 1) = 1 then begin
            result := result * z[i + 1];
        end;
    end;
end;
function count(v: longint): longint;
var
    i: longint;
begin
    result := 0;
    for i := 0 to n - 1 do begin
        if ((v shr i) and 1) = 1 then begin
            inc(result);
        end;
    end;
end;

function valid(v: longint): boolean;
var
    i: longint;
begin
    result := true;
    for i := 0 to n - 2 do begin
        if (z[i + 1] = z[i + 2]) and (((v shr i) and 3) = 2) then begin
            result := false;
        end;
    end;
end;
var
    q: int64;
    i, j: longint;
    t: longint;
    c: longint;
    w: longint;
begin
    reset(input, 'house.in'); reset(input);
    rewrite(output, 'house.out');

    n := 16;
    m := 6;

    maxint64 := 1;
    maxint64 := ((maxint64 shl 62) - 1) * 2 + 1;

    read(w);

    q := 1;
    t := 1;
    for i := 1 to n do begin
        q := q * z[i];
        t := t * 2;
    end;

    fillchar(u, sizeof(u), 0);
    for i := 0 to t - 1 do begin
        u[i] := (maxint64 / q >= value(i)) and (count(i) = m) and valid(i);
    end;

    c := 0;
    for i := t - 1 downto 0 do begin        
        if u[i] then begin
            for j := 0 to t - 1 do begin
                if (i <> j) and (i and j = i) then begin
                    if u[j] then begin
                        u[i] := false;
                        break;
                    end;
                end;
            end;
        end;
        if u[i] then begin
            writeln(q * value(i));
            inc(c);
            if (c = w) then break;
        end;
    end;
end.
