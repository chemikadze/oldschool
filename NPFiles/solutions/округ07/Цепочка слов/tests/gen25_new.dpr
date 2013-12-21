{$O-,Q+,R+}

var s:string;
    sa:array [1..250000] of string;
    st, c, i, j, k, l:integer;



begin
  c:=0; st:=0;
  for l:=1 to 5 do begin
    setlength (S, l);
    for i:=1 to l do s[i]:='a';
    k:=0;
    repeat
      inc (c, l);
      if c>250000 then break;
      inc (st);
      sa[st]:=s;
      k:=0;
      for j:=l downto 1 do begin
        inc (s[j]);
        if s[j]>'z' then s[j]:='a' else begin k:=j; break end;
      end;
    until k=0;
    if c>250000 then break;
  end;
  writeln (st);
  for i:=1 to st do
    writeln (sa[i]);
  writeln (250000);
  for i:=1 to 250000 do begin
    write (1);
    if i<250000 then write (' ') else writeln;
  end;
end.