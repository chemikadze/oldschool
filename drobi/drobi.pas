program n10;
uses crt;
var i,j, dl, a , z, osn: integer;
    chis, k, sum, q: real;
    S: string;
begin
	sum:=0;
	Writeln('Введите основание системы счисления');
	readln(osn);
	Writeln('Введите дробь в десятичном формате');
	readln(s);
	{str(chis,s); }
		dl:= length(s);
	{for i := 1 to dl-2 do begin
		if (ord(s[i+2])-87)>=osn
		then begin
			writeln('Введенная дробь не принадлежит заданной системе счисления. Дробь может содержать только цифры 0...',char(55+osn-1));
			halt;
		end
		else if (ord(s[i+2])-55)>=osn then begin
			writeln('Введенная дробь не принадлежит заданной системе счисления. Дробь может содержать только цифры 0...',char(55+osn-1));
			halt;
		end
		else if (ord(s[i+2])-ord('0')) >= osn then begin
			writeln('Введенная дробь не принадлежит заданной системе счисления. Дробь может содержать только цифры 0...',osn-1);
			halt;
		end;
	end;}
	for i := 1 to dl-2 do begin
		if ord(s[i+2]) > 64 then {если заглавные}
			Z:= ord(s[i+2])-55
		else
		if ord(s[i+2]) > 96 then{если строчные}
			Z:= ord(s[i+2])-87
		else
			z:=ord(s[i+2])-ord('0');{если просто цифры}
		q:=1;
		for j:= 1 to i do begin
			if (i = 1) then q:=1/osn
			else
			q:= q/osn;
		end;
	k:= z*q;
	sum:=sum+k;
	end;
	writeln(sum);
	readkey;
end.
