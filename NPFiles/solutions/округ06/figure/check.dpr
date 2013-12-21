{$I trans.inc}
program macro;
uses testlib,SysUtils;
const eps = 1e-15;
var 
  n, k: integer;
  ans,oa: extended;
  a, b: array[1..20] of extended;
  f: array[1..20] of boolean;
  jj,i,j : longint;
  min,max : extended;
begin
  DecimalSeparator := '.';
  n:= inf.getlong;
  k:= inf.getlong;
  for i:= 1 to n do
    a[i]:= inf.readreal;
  ans:= inf.readreal;

  for i:= 1 to k + 2 do
    b[i]:= ouf.readreal;

  if not ouf.seekeof then quit(_PE, 'Лишние данные в выходном файле');


  fillchar(f, sizeof(f), 0);
  for i:= 1 to k + 2 do begin
  	jj := 0;
    for j:= 1 to n do begin
     if (f[j]) then continue;
     if (abs(b[i] - a[j]) < eps) then begin
        f[j]:= true; 
        jj := 1;
        break;
     end;
    end;
    if jj = 0 then quit(_Wa,FORMAT('Оценка %.2f не существует',[b[i]]));
  end;
  min:= a[1];
  max:=min;
  for i:=2 to n do begin
  	if a[i] > max then max:=a[i];
	if a[i] < min then min:=a[i];
  end;
  jj:=0;
  for i:=1 to n do begin
  	if (a[i] = min)  and (f[i]) and (jj and 1 = 0) then jj:= jj or 1 else
  	if (a[i] = max)  and (f[i]) and (jj and 2 = 0) then jj:= jj or 2;
  end;
  if jj <> 3 then  quit(_Wa,'Не удалена макс. или мин. оценка');

  oa := 0 ;

  for i := 1 to n do begin
  	if f[i] then continue;
  	oa := oa + a[i];
  end; 

  oa := oa  / (n - k - 2);
  if abs (oa - ans)>0.006  then quit(_Wa,format(' Ожидалось - %.2f, получено - %.2f',[ans,oa]));

  Quit(_Ok,'');

end.