#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double gcd(long double a,long double b)
{if (b!=0) return gcd(b,fmodl(a,b));
 else return a;
}

int __do(char* fin,char* fout)
{long double a,b,c;
 FILE* in;
 FILE* out;
 in=fopen(fin,"r");
 out=fopen(fout,"w");

 fscanf(in,"%Lf %Lf",&a,&b);
 c=gcd(a,b);
 fprintf(out,"%.0Lf",c);

 fclose(in);
 fclose(out);
 return 0;
}

int main()
{__do("gcd.01","ansgcd.01");
 __do("gcd.02","ansgcd.02");
 __do("gcd.03","ansgcd.03");
 __do("gcd.04","ansgcd.04");
 __do("gcd.05","ansgcd.05");
 __do("gcd.06","ansgcd.06");
 __do("gcd.07","ansgcd.07");
 __do("gcd.08","ansgcd.08");
 __do("gcd.09","ansgcd.09");
 return 0;
}