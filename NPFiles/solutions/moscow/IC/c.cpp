//---------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
//#define FILES

//---------------------------------------------------------------------------

long double X;
long double Y;
int N;

int main(int argc, char* argv[])
{
  int v,s;
  int i,j;
  long double x,y;
  const long double m=1/sqrtl(2);
#ifdef FILES
  freopen(stdin,"c.in","r");
  freopen(stdout,"c.out","w");
#endif
  scanf("%d",&N);
  for (i=0;i<N;i++)
  {
    scanf("%d %d",&v,&s);
    x=y=0;
    switch (v)
    {
      case 1: y=s;break;
      case 2: x=y=s*m;break;
      case 3: x=s;break;
      case 4: x=-(y=-s*m);break;
      case 5: y=-s;break;
      case 6: x=y=-s*m;break;
      case 7: x=-s;break;
      case 8: x=-(y=s*m);break;
    }
    X+=x;
    Y+=y;
  }
  printf("%.3Lf %.3Lf",X,Y);
#ifndef FILES
  scanf("%*s");
#endif
  return 0;
}
//---------------------------------------------------------------------------
 