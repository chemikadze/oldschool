#include <stdio.h>
#include <stdlib.h>

struct SPoint
{
  int x, y;
};

typedef struct SPoint TPoint;

struct SSqr
{
  TPoint a, b;
  int s;
};

typedef struct SSqr TSqr;

bool cross(TPoint a, TPoint b, TSqr s2)
{
  return !(((a.x>=s2.b.x) || (b.x<=s2.a.x)) || ((b.y<=s2.a.y) || (a.y>=s2.b.y)));
}

int A, B;
int N, M;
TPoint pnts[1000]; int pntc=0;
int px[1000]; int pxc=0;
int py[1000]; int pyc=0;
TSqr   sqrs[1000]; int sqrc=0;
TSqr   good[1000]; int goodc=0;
TSqr*  msqr[2];    int maxs=0;

inline int fcmp(const void* a, const void* b)
{
  return *((int*)a)-*((int*)b);
}

int main()
{
  int i, j, k;
  bool c;
  
  freopen("garden.in", "r", stdin);
  freopen("garden.out", "w", stdout);
  scanf("%d %d", &N, &M);
  scanf("%d %d", &A, &B);
  px[pxc++]=0;
  px[pxc++]=A;
  py[pyc++]=0;
  py[pyc++]=B;
  for (i=0; i<N; i++)
  {
    scanf("%d %d", &sqrs[sqrc].a.x, &sqrs[sqrc].a.y);
    scanf("%d %d", &sqrs[sqrc].b.x, &sqrs[sqrc].b.y);
    px[pxc++]=sqrs[sqrc].a.x;
    px[pxc++]=sqrs[sqrc].b.x;
    py[pyc++]=sqrs[sqrc].a.y;
    py[pyc++]=sqrs[sqrc].b.y;
    sqrc++;
  }
  qsort(px, pxc, sizeof(int), fcmp);
  qsort(py, pyc, sizeof(int), fcmp);
  for (i=0; i<pxc; i++)
  {
    while (px[i]==px[i+1] && i<pxc) i++;
    for (j=0; j<pyc; j++)
    {
      while (py[j]==py[j+1] && j<pyc) j++;
      pnts[pntc].x=px[i];
      pnts[pntc].y=py[j];
      pntc++;
    }
  }
  for (i=0; i<pntc; i++)
    for (j=0; j<pntc; j++)
      if (pnts[i].x<pnts[j].x && pnts[i].y<pnts[j].y)
      {
        c=false;
        for (k=0; k<sqrc; k++)
          c=c || cross(pnts[i], pnts[j], sqrs[k]);
        if (!c)
        {
          good[goodc].a.x=pnts[i].x;
          good[goodc].a.y=pnts[i].y;
	  good[goodc].b.x=pnts[j].x;
	  good[goodc].b.y=pnts[j].y;
	  good[goodc].s=(good[goodc].b.x-good[goodc].a.x)*(good[goodc].b.y-good[goodc].a.y);
	  goodc++;
	}
      }
  msqr[0]=&good[0];
  msqr[1]=&good[1];
  maxs=sqrs[0].s+sqrs[1].s;
  for (i=0; i<goodc; i++)
    for (j=i+1; j<=goodc; j++)
	 if (!cross(good[i].a, good[i].b, good[j]))
	   if (good[i].s+good[j].s>maxs)
	   {
             msqr[0]=&good[i];
	     msqr[1]=&good[j];
             maxs=good[i].s+good[j].s;
	   }
  if (M==2)
  {
    printf("%d %d %d %d\n", msqr[0]->a.x, msqr[0]->a.y, msqr[0]->b.x, msqr[0]->b.y);
    printf("%d %d %d %d\n", msqr[1]->a.x, msqr[1]->a.y, msqr[1]->b.x, msqr[1]->b.y);
  }
  else
    if (msqr[0]->s > msqr[1]->s)
	 printf("%d %d %d %d\n", msqr[0]->a.x, msqr[0]->a.y, msqr[0]->b.x, msqr[0]->b.y);
    else
	 printf("%d %d %d %d\n", msqr[1]->a.x, msqr[1]->a.y, msqr[1]->b.x, msqr[1]->b.y);
}
