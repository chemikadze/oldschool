uses
  SysUtils, TestLib;

var
  ja, ca: string;

begin
  ja := ans.readword(BLANKS, BLANKS);
  ca := ouf.readword(BLANKS, BLANKS);

  if (ja <> ca) then
    quit(_wa, format('Правильный ответ %s, получено %s', [ja, ca]))
  else
    quit(_ok, format('Количество планировок равно %s', [ca]));
end.
