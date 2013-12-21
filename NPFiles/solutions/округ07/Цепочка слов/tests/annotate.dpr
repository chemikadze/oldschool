uses
    sysutils;
var
    i, n, m: longint;
    l: longint;
    s: string;
begin
    readln(n);
    l := 0;
    for i := 1 to n do begin
        readln(s);
        if l < length(s) then begin
            l := length(s);
        end;        
    end;
    readln(m);
    writeln(format('M=%d, N=%d, Максимальная длина слова=%d', [n, m, l]));
end.