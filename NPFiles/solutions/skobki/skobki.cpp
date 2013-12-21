//---------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#ifdef _DEBUG
#include <conio.h>
#endif

//---------------------------------------------------------------------------

int N;
char s[81];
long a[81][81];  //count of len[] with startpos[]
long ans;

int main(int argc, char* argv[])
{
  int i, j, l, pos;
  scanf("%s", &s);
  N=strlen(s);
  if (N%2)
  {
    a[N/2][0]=0;
    goto END;
  }
  for (i=0; i<=N; i++)
    a[0][i]=1;
  for (l=2; l<=N; l+=2)
  {
    for (pos=0; pos<=N-l; pos++)
      if (s[pos]!=')')
        for (i=0; i<=l-2; i+=2)
        {
          a[l][pos]+=a[i][pos+1]*a[l-i-2][pos+2+i]*(s[pos+i+1]!='(');
        }
  }
  END:
  printf("%d", a[N][0]);
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
