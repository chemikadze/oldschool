//---------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

const int INF=100000000;

int N;
long g[5003][3];
long t[5003];

int main(int argc, char* argv[])
{
  register int i, j;

  scanf("%d", &N);
  for (i=0; i<N; i++)
    scanf("%ld %ld %ld", &g[i][0], &g[i][1], &g[i][2]);
  for (i=0; i<N+1; i++)
    t[i]=INF;
  t[0]=0;
  for (i=0; i<N+1; i++)
    for (j=0; j<3; j++)
      t[i+j+1]=min(t[i+j+1], t[i]+g[i][j]);
  printf("%ld", t[N]);
  #ifdef _DEBUG
  while (fgetc(stdin)!='\n');fgetc(stdin);
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 