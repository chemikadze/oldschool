uses
    sysutils;
var
    z: array [1..200] of longint;

    b: array [1..15] of longint = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47);
    bp: array [1..15] of longint = (4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    s: longint;
    maxint64: int64;
    p: array [0..1024 * 256] of longint;
    cp: longint;
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
    i, j, k: longint;
    t: longint;
    maxm, maxn, max: longint;
    maxr, maxl: longint;
    layer: boolean;
    fit: boolean;
    d: longint;
    r: longint;
    f: boolean;
    rs: longint;
    c: array [1..16] of longint;
    e: longint;
    ffit: boolean;
    bm: longint;
begin
    maxint64 := 1;
    maxint64 := ((maxint64 shl 62) - 1) * 2 + 1;

    bm := 1;
    for i := 1 to high(bp) do begin
        bm := bm * (bp[i] + 1);
    end;
    writeln(bm);
    for d := 0 to bm - 1 do begin
        if d mod 1000000 = 0 then begin
            writeln(d:8);
        end;
        rs := 0;
        r := d;
        f := true;
        for j := 1 to high(b) do begin
            c[j] := (r mod (bp[j] + 1));
            if (j >= 2) and (c[j - 1] < c[j]) then begin
                f := false;
                break;
            end;
            r := r div (bp[j] + 1);
            rs := rs + c[j];
        end;

        if f and (rs >= 15) then begin
            e := 0;
            for j := 1 to high(b) do begin
                for k := 1 to c[j] do begin
                    inc(e);
                    z[e] := b[j];
                end;
            end;
            for i := 1 to e do begin
                write(z[i], ',');
            end;
            writeln;

            for fit := false to true do begin
            //for deep := falst to true do begin
            for layer := false to true do begin
                if fit and layer then continue;
                //if deep and layer then continue;
                maxl := 0;
                max := 0;
                maxn := 0;
                maxm := 0;

                n := 1;
                while (n <= e) do begin
                    //write(n:2);
                    maxr := 0;
                    q := 1;
                    t := 1;
                    for i := 1 to n do begin
                        q := q * z[i];
                        t := t * 2;
                    end;
                    m := 1;
                    while (m <= n) do begin
                        s := 0;
                        cp := 0;
                        ffit := true;
                        for i := t - 1 downto 0 do begin
                            f := (maxint64 / q >= value(i)) and (count(i) <= m) and valid(i);
                            if layer then begin
                                f := f and (count(i) = m);
                            end;
                            ffit := ffit and ((maxint64 / q >= value(i)) or (count(i) <> m));
                            if f then begin
                                for j := 1 to cp do begin
                                    if (i and p[j] = i) then begin
                                        f := false;
                                        break;
                                    end;
                                end;
                            end;
                            if f then begin
                                inc(cp);
                                p[cp] := i;
                                inc(s);
                            end;
                        end;
                        if fit and not ffit then begin
                            s := 0;
                        end;
                        //write(s:4);

                        if (s < maxr) then break;
                        maxr := s;

                        if s > max then begin
                            max := s;
                            maxn := n;
                            maxm := m;
                        end;

                        inc(m);
                    end;
                    //writeln;
                    
                    if (maxr < maxl) then break;
                    maxl := maxr;

                    inc(n);
                end;
                if fit then begin
                    write('Full_layer___');
                end else if layer then begin
                    write('Part_of_layer');
                end else begin
                    write('Skew_________');
                end;
                writeln(' ', max, ' C(', maxn, ',', maxm, ')');
            end;
            //end;
            end;
            flush(output);
        end;
    end;
end.