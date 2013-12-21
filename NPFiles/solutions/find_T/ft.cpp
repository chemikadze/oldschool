//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>

//---------------------------------------------------------------------------

int N;
int a[32000];

int main(int argc, char* argv[])
{
  int i, j, k;
  int p;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
    scanf("%d", &a[i]);
  for (i=p=1; i<=N; i++, p=1)     //period
  if (!(N%i))
  {
    for (j=1; j<=N && p; j++)     //dphi
      for (k=0; k<N/i &&p; k++)   //n period
        if (a[k*i+j]!=a[(k+1)*i+j] && ((k+1)*i+j<=N))
          p=0;
    if (p)
      printf("%d ", i);
  }
  getch();
  return 0;
}
//---------------------------------------------------------------------------
 