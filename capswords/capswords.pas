procedure { чотатам.клик }
var
	s, sw: string;
	caps: boolean;
	i, j: integer;

	{ ввод строки S }

	for i:=1 to length(s)
	begin
		j:=0;
		caps:=false;
		while (s[i]=' ')
			inc(i);
		while ((s[i]<>' ') and (i<length(s)))
		begin
			sw:=sw+s[i];
			caps:=caps or ((s[i]>='A') and (s[i]<='Z')) or ((s[i]>='А') and (s[i]<='Я'));
			inc(i);
		end;
		if (caps) then
			{ строка sw -- слово с большой буквой }
	end;
end;
