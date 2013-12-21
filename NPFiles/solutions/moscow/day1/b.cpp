//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N;

char simp[10000+1];

bool simple(int n)
{
  int i;
  if (simp[n])
    return simp[n]>0;
  if (n<2)
  {
    simp[n]=-1;
    return false;
  }
  for (i=2;i<=n/2;i++)
    if (!(n%i))
    {
      simp[n]=-1;
      return false;
    }
  simp[n]=1;
  return true;
}


int main(int argc, char* argv[])
{
  int i,p=1;
  scanf("%d",&N);
  while (N>0)
  {
    for (i=(N>3? 3 : N);i>0;i--)
      if (!simple(N-i))
        break;
    N-=i;
    if (N==0)
    {
      printf("%d",p);
      break;
    }
    p=(p==1 ? 2 : 1);
  }
  #ifdef _DEBUG
  scanf("%*s");
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 