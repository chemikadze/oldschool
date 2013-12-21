{$o-}
const
    max_m = 50;

function paint(l, r, k: int64; var z: int64): int64;
var
    n: int64;
begin
    if (r - l <= z) then begin
        paint := 0;
        z := z - (r - l);
        exit;
    end;
    r := r - z;

    n := (r - l + k - 1) div k;
    z := n * k - (r - l);
    paint := n * (r - 1) - k * n * (n - 1) div 2;
end;

var
    i, j, n, m, k, t: longint;
    l, r: array [1..max_m] of longint;
    z, ans: int64;
begin
    reset(input, 'fence.in');
    rewrite(output, 'fence.out');

    read(n, k, m);

    for i := 1 to m do begin
        read(l[i], r[i]);
    end;

    for i := 1 to m do begin
        for j := i + 1 to m do begin
            if l[i] < l[j] then begin
                t := l[i]; l[i] := l[j]; l[j] := t;
                t := r[i]; r[i] := r[j]; r[j] := t;
            end;
        end;
    end;

    z := 0;
    ans := 0;
    for i := 1 to m do begin
        ans := ans + paint(l[i], r[i] + 1, k, z);
    end;
    writeln(ans * 2);
end.