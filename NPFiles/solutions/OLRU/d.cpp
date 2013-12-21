//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#pragma hdrstop
//---------------------------------------------------------------------------
#define FILES
#define flong long double
flong V;      // speed
flong W;      // maxspeed
flong A;      // max A
flong T;      // time
flong C,D;    // coords

#pragma argsused
int main(int argc, char* argv[])
{
  flong at,t;
  #ifdef FILES
  freopen("d.in","r",stdin);
  freopen("d.out","w",stdout);
  #endif
  scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&V,&W,&A,&T,&C,&D);
  at=0;t=T;

  if (D>=0)
  {
    if (V*T < C || V*T > D)
      goto END;
    else
    {
      at=min( (A==0)?(0):((W-V)/A) ,T);
      t=T-at;
      if ( D < at*(V+A*at/2)+W*t )
      {
        printf("%Lf %Lf\n",at,A);
        goto END;
      }
      else
      {
        at=min((A==0)?(0):((W+V)/A),T);
        t=T-at;
        if ( (at*(V-at*A/2)-t*W) < C )
        {
          printf("%Lf %Lf\n",at,-A);
          goto END;
        }
        else
        {
          t=-1;
          printf("-1\n");
        }
      }
    }
  }
END:
  if (t>0)
  {
    printf("%Lf 0",t);
  }
  #ifndef FILES
  scanf("%*s");
  #endif
  return 0;
}
//---------------------------------------------------------------------------
