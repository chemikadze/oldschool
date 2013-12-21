//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop

//---------------------------------------------------------------------------

int N;
int n[10001];

#pragma argsused
int main(int argc, char* argv[])
{
  int i,j;
  FILE* in=fopen("output.txt","r");

  fscanf(in,"%d",&N);
  for (i=1;i<=N;i++)
    fscanf(in,"%d",&n[i]);
  for (i=1;i<=N;i++)
    for (j=1;j<=N;j++)
      if (i!=j && n[i]==n[j] &&  (!(i%j) || !(j%i)) )
      {
        printf("FUCK on %d, %d (color %d, %d)",i,j,n[i],n[j]);
        scanf("%*s");
        return 0;
      }
  printf("All OK");
  scanf("%*s");
  return 0;
}
//---------------------------------------------------------------------------
