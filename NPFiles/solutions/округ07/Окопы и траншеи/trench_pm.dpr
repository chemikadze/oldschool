{$r-,q-,o+}
uses
  sysutils, math;

const
  MAX_N = 1000;
  MAX_M = 4 * MAX_N + 2;
  INF = 1e100;

var
  n, m, i, j, k, x1, y1, x2, y2: integer;
  d: array[1..MAX_M] of double;
  z: array[1..MAX_M] of boolean;
  xx1, yy1, xx2, yy2: array[1..MAX_M] of integer;

procedure add(x1, y1, x2, y2: integer);
begin
  inc(m);
  xx1[m] := x1;
  yy1[m] := y1;
  xx2[m] := x2;
  yy2[m] := y2;
end;

function getDist(i, j: integer): double;
begin
  x1 := max(xx1[i], xx1[j]);
  x2 := min(xx2[i], xx2[j]);
  y1 := max(yy1[i], yy1[j]);
  y2 := min(yy2[i], yy2[j]);
  if (x2 >= x1) and (y2 >= y1) then begin
    result := 0;  
  end else begin
    if (x2 >= x1) then begin
      result := y1 - y2;
    end else begin
      if (y2 >= y1) then begin
        result := x1 - x2;
      end else begin
        result := hypot(y1 - y2, x1  - x2);            
      end;
    end;        
  end;
end;

begin
  reset(input, 'trench.in');
  rewrite(output, 'trench.out');

  read(n);
  m := 0;
  for i := 1 to n do begin
    read(x1, y1, x2, y2);
    add(x1, y1, x2, y1);
    add(x1, y1, x1, y2);
    add(x1, y2, x2, y2);
    add(x2, y1, x2, y2);
  end;
  read(x1, y1, x2, y2);
  add(x1, y1, x1, y1);
  add(x2, y2, x2, y2);

  for i := 1 to m do d[i] := INF;
  d[m - 1] := 0;
  for i := 1 to m do begin
    k := 0;
    for j := 1 to m do 
      if not z[j] then      
        if (k = 0) or (d[k] > d[j]) then k := j;
    z[k] := true;
    for j := 1 to m do 
      d[j] := min(d[j], d[k] + getDist(k, j));
  end;

  writeln(d[m]);

end.