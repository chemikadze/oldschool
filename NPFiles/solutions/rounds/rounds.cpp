//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <algorithm>

#define sqr(SQRX) ( (SQRX)*(SQRX) )

using namespace std;
//---------------------------------------------------------------------------

struct scircle
{
  double x, y, r;
};

struct svector
{
  double x,y;
};

typedef struct scircle tcircle;
typedef struct svector tvector;

int N;
tcircle c[10000];

void check(const tcircle o1, const tcircle o2)
{

  tvector ob, b, h1, h2;
  tvector a1, a2;
  double k, lobl, l, h;

  l=sqrt( sqr(o2.x-o1.x)+sqr(o2.y-o1.y) );

  if (l==0 && (o1.r==o2.r))
  {
    printf("I can't count them - too many points :(");
    return;
  }
  if (l>(o1.r+o2.r))
  {
    printf("There are no points!!!\n\n");
    return;
  }
  if (l==(o1.r+o2.r))
  {
    lobl=(-sqr(o2.r)+sqr(o1.r)+sqr(l))/(2*l);
    k=lobl/l;

    ob.x=(o2.x-o1.x)*k;
    ob.y=(o2.y-o1.y)*k;
    printf("There are only 1 of them....\n");
    printf("%lf %lf\n\n", o1.x+ob.x, o1.y+ob.y);
    return;
  }
  if (l==o1.r)
  {
    printf("There are only 1 of them....\n");
    printf("%lf %lf\n\n", o2.x, o2.y);
    return;
  }

  {
    lobl=(-sqr(o2.r)+sqr(o1.r)+sqr(l))/(2*l);
    k=lobl/l;

    ob.x=(o2.x-o1.x)*k;
    ob.y=(o2.y-o1.y)*k;

    b.x=o1.x+ob.x;
    b.y=o1.y+ob.y;

    h=sqrt( sqr(o1.r)-sqr(lobl) );
    h1.x=(-ob.y/lobl)*h;
    h1.y=(ob.x/lobl)*h;

    h2.x=-h1.x;
    h2.y=-h1.y;

    a1.x=b.x+h1.x;
    a1.y=b.y+h1.y;

    a2.x=b.x+h2.x;
    a2.y=b.y+h2.y;

    printf("There are only 2 of them....\n");
    printf("%lf %lf\n", a1.x, a1.y);
    printf("%lf %lf\n\n", a2.x, a2.y);
    return;
  }
}

int main(int argc, char* argv[])
{
  int i, j;

  scanf("%d", &N);
  for (i=0; i<N*2; i++)
    scanf("%lf %lf %lf", &c[i].x, &c[i].y, &c[i].r);

  for (i=0; i<N*2; i+=2)
    check( (c[i].r>=c[i+1].r)?(c[i]):(c[i+1]) , (c[i].r<c[i+1].r)?(c[i]):(c[i+1]));

  getch();
  return 0;
}
//---------------------------------------------------------------------------
