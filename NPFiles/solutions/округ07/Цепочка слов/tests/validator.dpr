{$r+,q+,o-}
{$apptype console}
uses
    SysUtils;

type
    int = longint;

const
    MAXS = 250000;

procedure quit(s: string);
begin
    writeln(s);
    halt(239);
end;

var
    n, k, i, j, len: int;
    s: string;

begin
    reset(input, 'chain.in');
    readln(n);
    if ((n < 1) or (n > MAXS)) then
        quit('Invalid ''n''');

    len := 0;
    for i := 1 to n do begin
        readln(s);
        for j := 1 to length(s) do begin
            if ((s[j] < 'a') or (s[j] > 'z')) then
                quit('Word ' + inttostr(i) + ' is invalid');
        end;
        len := len + length(s);
        if (len > MAXS) then
            quit('Total length of the words is too big');
    end;
    readln(k);
    if ((k < 1) or (k > MAXS)) then
        quit('Invalid ''k''');

    for i := 1 to k do begin
        read(j);
        if (j < 1) or (j > n) then
            quit('Invalid index');
    end;
    writeln('OK');
end.
