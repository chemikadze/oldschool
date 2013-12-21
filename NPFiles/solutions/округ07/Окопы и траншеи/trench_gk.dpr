uses
    math;
const
    max_n = 1000;
    max_c = max_n * 4 + 2;
var
    i, j, n: longint;
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
    a: array [1..max_c, 1..max_c] of double;
    tx1, ty1, tx2, ty2: longint;
    b, e: longint;
    d: array [0..max_c] of double;
    u: array [1..max_c] of boolean;
    minj: longint;
begin
    reset(input, 'trench.in');
    rewrite(output, 'trench.out');

    while not seekeof do begin

    c := 0;

    read(n);
    for i := 1 to n do begin
        read(tx1, ty1, tx2, ty2);
        add(tx1, ty1, tx1, ty2);
        add(tx1, ty1, tx2, ty1);
        add(tx2, ty1, tx2, ty2);
        add(tx1, ty2, tx2, ty2);
    end;

    read(tx1, ty1, tx2, ty2);
    add(tx1, ty1, tx1, ty1);
    b := c;
    add(tx2, ty2, tx2, ty2);
    e := c;

    for i := 1 to c do begin
        for j := 1 to c do begin
            a[i][j] := dist(i, j);
        end;
    end;

    for i := 0 to c do begin
        d[i] := 1e100;
        u[i] := false;
    end;
    
    d[b] := 0;
    for i := 1 to c do begin
        minj := 0;
        for j := 1 to c do begin
            if (not u[j]) and (d[minj] > d[j]) then begin
                minj := j;
            end;
        end;
        if minj = e then break;
        u[minj] := true;
        for j := 1 to c do begin
            if (not u[j]) and (d[j] > d[minj] + a[minj][j]) then begin
                d[j] := d[minj] + a[minj][j];
            end;
        end;
    end;

    writeln(d[e]:0:10);
    end;
end.
