uses
    sysutils, math;
const
    max_n = 1000;
    max_c = (max_n + 2) * 4;
    eps = 1e-10;
var
    i, j, k, n: longint;
    x1, y1, x2, y2: array [1..max_c] of longint; 
    x1c, y1c, x2c, y2c: array [1..max_c] of longint;
    c: longint;

procedure add(tx1, ty1, tx2, ty2: longint);
begin
    inc(c);
    x1[c] := min(tx1, tx2);
    y1[c] := min(ty1, ty2);
    x2[c] := max(tx1, tx2);
    y2[c] := max(ty1, ty2);  
    x1c[c] := tx1;
    y1c[c] := ty1;
    x2c[c] := tx2;
    y2c[c] := ty2;
end;

procedure addAll(tx1, ty1, tx2, ty2: longint);
begin
    add(tx1, ty1, tx1, ty2); 
    add(tx1, ty2, tx2, ty2);  
    add(tx2, ty2, tx2, ty1);
    add(tx2, ty1, tx1, ty1);
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
    p: array [1..max_n + 2, 1..max_n + 2] of longint;
    tx1, ty1, tx2, ty2: array[1..max_n + 2] of longint;
    b, e, ax, ay, bx, by: longint;
    x, y, cur: longint;

function vMul(x1, y1, x2, y2: longint): longint;
begin
  result := x1 * y2 - x2 * y1;
end;

function sMul(x1, y1, x2, y2: longint): longint;
begin
  result := x1 * x2 + y1 * y2;
end;

procedure pushpoint(nx, ny: longint);
begin
  writeln(nx, ' ', ny);
  x := nx;
  y := ny;
end;

procedure moveto(nx, ny: longint);
var
  i, j: longint;
begin
  for i := 1 to 8 do
  begin
    j := 4 * cur - 3 + (i mod 4);
    if vMul(x2c[j] - x1c[j], y2c[j] - y1c[j], x - x1c[j], y - y1c[j]) = 0 then
    begin
      if (vMul(x2c[j] - x1c[j], y2c[j] - y1c[j], nx - x1c[j], ny - y1c[j]) = 0) and
        (sMul(x - x1c[j], y - y1c[j], nx - x, ny - y) >= 0) then
      begin
        pushpoint(nx, ny);
        break;
      end;
      pushpoint(x2c[j], y2c[j]);
    end;
  end;
end;

procedure push(b: longint);
var
  d: extended;
  i, j, i0, j0: longint;
label
  br;
begin
  d := a[cur, b];
  for i0 := 1 to 4 do
    for j0 := 1 to 4 do
    begin
      i := 4 * cur - 3 + (i0 mod 4);
      j := 4 * b - 3 + (j0 mod 4);
      if (d < eps) and (x1[i] = x2[i]) and (y1[j] = y2[j]) and
        (x1[j] <= x1[i]) and (x2[j] >= x1[i]) and
        (y1[i] <= y1[j]) and (y2[i] >= y1[j]) then
      begin
        moveto(x1[i], y1[j]);
        goto br;
      end;         
      if (d < eps) and (x1[j] = x2[j]) and (y1[i] = y2[i]) and
        (x1[i] <= x1[j]) and (x2[i] >= x1[j]) and
        (y1[j] <= y1[i]) and (y2[j] >= y1[i]) then
      begin
        moveto(x1[j], y1[i]);
        goto br;
      end;
      if (abs(hypot(x1c[i] - x1c[j], y1c[i] - y1c[j]) - d) < eps) then
      begin
        moveto(x1c[i], y1c[i]);
        pushpoint(x1c[j], y1c[j]);
        goto br;
      end;  
      if (x1[i] = x2[i]) and (y1[i] < y1c[j]) and (y2[i] > y1c[j]) and
        (abs(abs(x1[i] - x1[j]) - d) < eps) then
      begin
        moveto(x1c[i], y1c[j]);
        pushpoint(x1c[j], y1c[j]);
        goto br;
      end;   
      if (y1[i] = y2[i]) and (x1[i] < x1c[j]) and (x2[i] > x1c[j]) and
        (abs(abs(y1[i] - y1[j]) - d) < eps) then
      begin
        moveto(x1c[j], y1c[i]);
        pushpoint(x1c[j], y1c[j]);
        goto br;
      end;
      if (x1[j] = x2[j]) and (y1[j] < y1c[i]) and (y2[j] > y1c[i]) and
        (abs(abs(x1[i] - x1[j]) - d) < eps) then
      begin
        moveto(x1c[i], y1c[i]);
        pushpoint(x1c[j], y1c[i]);
        goto br;
      end;
      if (y1[j] = y2[j]) and (x1[j] < x1c[i]) and (x2[j] > x1c[i]) and
      (abs(abs(y1[i] - y1[j]) - d) < eps) then
      begin
        moveto(x1c[i], y1c[i]);
        pushpoint(x1c[i], y1c[j]);
        goto br;
      end;
    end;
br:
  cur := b;
end;

procedure buildpath(a, b: longint; na, nb: boolean);
begin
  if p[a][b] = 0 then
  begin              
    if (na) then
      push(a);
    if (nb) then
      push(b);
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
    ax := x;
    ay := y;
    for i := 1 to n do
    begin
      if (tx1[i] <= x) and (tx2[i] >= x) and (ty1[i] <= y) and (ty2[i] >= y) and
        ((tx1[i] = x) or (tx2[i] = x) or (ty1[i] = y) or (ty2[i] = y)) then
        b := i;
    end;

    read(x, y);
    bx := x;
    by := y;
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
    x := ax;
    y := ay;
    cur := b;
    writeln(x, ' ', y);
    buildpath(b, e, false, false);
    push(e);
    moveto(bx, by);
end.
