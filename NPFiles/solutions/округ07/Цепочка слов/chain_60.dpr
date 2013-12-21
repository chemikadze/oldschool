
const
	NMAX = 250000;

function isPrefix(var s1, s2 : string) : boolean;
var
	i : longint;
begin
	if (length(s1) < length(s2)) then
	begin
		isPrefix := true;
		for i:= 1 to length(s1) do
			if (s1[i] <> s2[i]) then
			begin
				isPrefix := false;
				break;
			end;
	end else begin
		isPrefix := false;
	end;
end;

var 
	s : array [1..NMAX] of string;
	p : array [1..NMAX] of longint;
	i, l, r : longint;
	ans, al, ar : longint;
	n, m : longint;

begin
	assign(input, 'chain.in');
	assign(output, 'chain.out');
	reset(input);
	rewrite(output);
	readln(n);
	for i := 1 to n do begin
		readln(s[i]);
	end;
	read(m);
	for i := 1 to m do read(p[i]);
	ans := 1;
	al := 1;
	ar := 1;
	l := 1;
	r := 1;
	while (l <= m) do
	begin
		r := l + 1;
		while (r <= m) do
		begin
			if not isPrefix(s[p[r - 1]], s[p[r]]) then break;
			if (ans < r - l + 1) then
			begin
				ans := r - l + 1;
				al := l;
				ar := r;
			end;
			inc(r);
		end;
		l := r;
	end;
	writeln(al, ' ', ar);
end.