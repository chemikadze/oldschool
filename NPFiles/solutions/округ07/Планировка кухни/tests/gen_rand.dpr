{
 Usage: genrand a b n l h r
 a is the first side of rectangle
 a is the second side of rectangle
 n is the number of cabinets
 l is the lower bound for cabinet width
 h is the upper bound for cabinet width
 r is the random seed
}
Program GenTests;

uses SysUtils;

const MaxW = 300; MaxN = 100;

var i, k, l, h: Integer;
 w: array [1..MaxN] of Integer;
 a, b, n: Integer;

procedure out;
var i: Integer;
begin
 writeln (a, ' ', b, ' ', n);
 for i := 1 to n do
  writeln (w[i]);
end;

BEGIN
 a := StrToInt (ParamStr (1));
 b := StrToInt (ParamStr (2));
 n := StrToInt (ParamStr (3));
 l := StrToInt (ParamStr (4));
 h := StrToInt (ParamStr (5));
 randseed := StrToInt (ParamStr (6));
 assert ((a >= 1) AND (a <= MaxW));
 assert ((b >= 1) AND (b <= MaxW));
 assert ((1 <= l) AND (l <= h) AND (h <= MaxW));
 assert ((n >= 1) AND (n <= MaxN));
 for i := 1 to n do
  w[i] := l + random (h - l + 1);
 for i := 1 to n do
  assert ((w[i] >= 1) AND (w[i] <= MaxW));
 out;
END.
