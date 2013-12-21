uses
    testlib, sysutils;

const
    eps = 1.1e-6;

var
    ja, pa: extended;

begin
    ja := ans.readreal;
    pa := ouf.readreal;

    if abs(ja - pa) > eps then
        quit(_wa, 'Правильный ответ: ' + floattostr(ja) + ', ответ участника: ' + floattostr(pa));

    quit(_ok, floattostr(ja));
end.