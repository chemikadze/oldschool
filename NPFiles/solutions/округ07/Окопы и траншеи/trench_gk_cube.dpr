uses
    sysutils, math;
const
    max_n = 1000;
    max_c = (max_n + 2) * 4;
var
    i, j, k, n: longint;
    x1, y1, x2, y2: array [1..max_c] of longint;
    c: longint;

procedure add(tx1, ty1, tx2, ty2: longint);
begin
    inc(c);
    x1[c] := min(tx1, tx2);
    y1[c] := min(ty1, ty2);
    x2[c] := max(tx1, tx2);
    y2[c] := max(ty1, ty2);
end;

procedure addAll(tx1, ty1, tx2, ty2: longint);
begin
    add(tx1, ty1, tx1, ty2);
    add(tx1, ty1, tx2, ty1);
    add(tx2, ty1, tx2, ty2);
    add(tx1, ty2, tx2, ty2);
end;

function dist(i, j: longint): double;
var
    ix, iy: longint;
begin
    ix := max(x1[i], x1[j]) - min(x2[i], x2[j]);
    iy := max(y1[i], y1[j]) - min(y2[i], y2[j]);

    if (ix > 0) and (iy > 0) then begin
        dist := hypot(ix, iy);
    end else begin
        dist := max(max(ix, 0), max(iy, 0));
    end;
end;

var
    a: array [1..max_n + 2, 1..max_n + 2] of double;
    tx1, ty1, tx2, ty2: longint;
    b, e: longint;
begin
    reset(input, 'trench.in');
    rewrite(output, 'trench.out');

    c := 0;

    read(n);
    for i := 1 to n do begin
        read(tx1, ty1, tx2, ty2);
        addAll(tx1, ty1, tx2, ty2);
    end;

    read(tx1, ty1, tx2, ty2);
    addAll(tx1, ty1, tx1, ty1);
    b := c div 4;
    addAll(tx2, ty2, tx2, ty2);
    e := c div 4;

    for i := 1 to e do begin
        for j := 1 to e do begin
            a[i][j] := 1e100;
        end;
    end;

    for i := 1 to c do begin
        for j := 1 to c do begin
            if a[(i + 3) div 4][(j + 3) div 4] > dist(i, j) then begin
                a[(i + 3) div 4][(j + 3) div 4] := dist(i, j);
            end;
        end;
    end;

    for i := 1 to e do begin
        for j := 1 to e do begin
            for k := 1 to e do begin
                if a[j][k] > a[j][i] + a[i][k] then begin
                    a[j][k] := a[j][i] + a[i][k];
                end;
            end;
        end;
    end;
    writeln(a[b][e]:0:10);
end.
