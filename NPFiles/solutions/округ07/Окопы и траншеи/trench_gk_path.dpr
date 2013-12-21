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
    p: array [1..max_n + 2, 1..max_n + 2] of integer;
    tx1, ty1, tx2, ty2: array[1..max_n + 2] of longint;
    b, e, x, y: longint;

procedure buildpath(a, b: longint; na, nb: boolean);
begin
  if p[a][b] = 0 then
  begin              
    if (na) then
      write(a, ' ');
    if (nb) then
      write(b, ' ');
  end else
  begin
    buildpath(a, p[a][b], na, true);
    buildpath(p[a][b], b, false, nb);
  end;
end;

begin
    reset(input, 'trench.in');
    rewrite(output, 'trench.out');

    c := 0;

    read(n);
    for i := 1 to n do begin
        read(tx1[i], ty1[i], tx2[i], ty2[i]);
        addAll(tx1[i], ty1[i], tx2[i], ty2[i]);
    end;

    read(x, y);
    for i := 1 to n do
    begin
      if (tx1[i] <= x) and (tx2[i] >= x) and (ty1[i] <= y) and (ty2[i] >= y) and
        ((tx1[i] = x) or (tx2[i] = x) or (ty1[i] = y) or (ty2[i] = y)) then
        b := i;
    end;    

    read(x, y);
    for i := 1 to n do
    begin
      if (tx1[i] <= x) and (tx2[i] >= x) and (ty1[i] <= y) and (ty2[i] >= y) and
        ((tx1[i] = x) or (tx2[i] = x) or (ty1[i] = y) or (ty2[i] = y)) then
        e := i;
    end;

    for i := 1 to n do begin
        for j := 1 to n do begin
            a[i][j] := 1e100;
        end;
    end;

    for i := 1 to 4 * n do begin
        for j := 1 to 4 * n do begin
            if a[(i + 3) div 4][(j + 3) div 4] > dist(i, j) then begin
                a[(i + 3) div 4][(j + 3) div 4] := dist(i, j);
            end;
        end;
    end;

    for i := 1 to n do begin
        for j := 1 to n do begin
            for k := 1 to n do begin
                if a[j][k] > a[j][i] + a[i][k] then begin
                    a[j][k] := a[j][i] + a[i][k];
                    p[j][k] := i;
                end;
            end;
        end;
    end;
    writeln(a[b][e]:0:10);
    buildpath(b, e, true, b <> e);
end.
