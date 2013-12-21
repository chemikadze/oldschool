//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

//#define DEBUG

#ifndef DEBUG
#define FILES
#endif

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  int c,p;
  int s;
  int scnt;
#ifdef FILES
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
#endif
  scanf("%d %d %d",&p,&c,&s);
  scnt=(c+p)/2+(c+p)%2;
  if (s>scnt)
  {
    printf("- -\n");
    printf("- -");
    goto exit;
  }
  if (s<=p/2)
  {
    printf("P %d\n",s*2-1);
    printf("P %d",s*2);
  }
  else
  {
    if ( s>(p/2+((c%2 || p%2)?1:0)) )
    {
      printf("C %d\n", (scnt-s)*2+1);
      printf("C %d", (scnt-s)*2 );
    }
    else
    {
      if ( !((c+p)%2) )
      {
        printf("P %d\n",p);
        printf("C %d",c-1);
      }
      else
      {
        if (s==p/2+p%2)
        {
          printf("P %d\n",p);
          printf("- -");
        }
        else
        {
          printf("- -\n");
          printf("C %d",c-1);
        }
      }
    }
  }

exit:
#ifndef FILES
  scanf("%*s");
#endif
  return 0;
}
//---------------------------------------------------------------------------


