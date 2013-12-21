#include <stdio.h>
#include<conio.h>

struct sotr
{
  int x0, y0;
  int x1, y1;
};

typedef struct sotr totr;

int N, M;
totr o[100];
int  k[100];
totr tgt;

int main()
{
  int i, j;
  int ang;

  scanf("%d %d", &N, &M);
  for (i=0; i<N; i++)
    scanf("%d %d %d %d", &o[i].x0, &o[i].y0, &o[i].x1, &o[i].y1);
  scanf("%d %d %d %d", &tgt.x0, &tgt.y0, &tgt.x1, &tgt.y1);
  for (i=0; i<M; i++)
  {
    scanf("%d", &k[i]);
    k[i]--;
  }

  for (i=0; i<=355; i+=5) //angle
    for (j=0; j<M-1; j++)

}