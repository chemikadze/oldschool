//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N;
int n[10001];
int c=1;

int main(int argc, char* argv[])
{
  int i,j;
  int max=0;

  #ifndef DEBUG
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  scanf("%d",&N);

  n[1]=c++;
  for (i=2;i<=N;i++)
  {
    if (!n[i])
      n[i]=c;
    if (n[i]>max)
      max=n[i];  
    for (j=i+1;j<=N;j++)
    {
      if ( (!n[j]) && j%i )
        n[j]=c;
      if ( !(j%i) )
        n[j]=n[i]+1;
      if (n[j]>max)
        max=n[j];
    }
    c++;
  }

  printf("%d\n",max);
  for (i=1;i<=N;i++)
  {
    printf("%d ",n[i]);
  }
  #ifdef _DEBUG
  scanf("%*s");
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 