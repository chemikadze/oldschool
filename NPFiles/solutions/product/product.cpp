//---------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>

//---------------------------------------------------------------------------

long long N;
char w[100];
char s[100];
int len;

int main(int argc, char* argv[])
{
  int i, j;

  freopen("product.in", "r", stdin);
  freopen("product.out", "w", stdout);

  scanf("%Ld", &N);
  for (len=0; N>=pow(4, len); len++)
    N-=pow(4, len);

  for (i=len; i>0; i--)
  {
    w[i]=floor(N/pow(4,i-1));
    N-=pow(4,i-1)*floor(N/pow(4,i-1));
  }

  for (i=0; i<len; i++)
  {
    s[i]=(int)pow(2, w[len-i])+'0';
  }
  s[i]=0;
  printf(s);

  return 0;
}
//---------------------------------------------------------------------------
