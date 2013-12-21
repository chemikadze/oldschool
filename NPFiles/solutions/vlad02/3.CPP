#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define sqr(_x) ((_x)*(_x))

const double shar[4][3]=
{
 {0,0,0},
 {1,0,0},
 {0,1,0},
 {0,0,1}
};

const double rad[4]={1, 0.5, 0.5, 0.5};

//x,y,z in [-1 1.5]

long in=0,all=2000000;

double randpoint()
{
  long br=rand();
  double r=(double)br/100;
  while (r>1.5)
    r-=1;
  if (br%2)
  {
    r=-r;
    while (r<-1)
      r+=1;
  }
  return r;
}

int inshar(double x,double y,double z,int i)
{
  double r=sqr(x-shar[i][0])+sqr(y-shar[i][1])+sqr(z-shar[i][2]);
  return r<=sqr(rad[i]);
}

int main()
{
  long b=0;
  double x,y,z;
  long i,j;
  randomize();
  for (i=0;i<all;i++)
  {
    b=0;
    x=randpoint();
    y=randpoint();
    z=randpoint();
    for (j=0;j<4;j++)
      b=b || (inshar(x,y,z,j));
    if (b)
     in++;
  }
  double r=(2.5*2.5*2.5)*( ((double)in)/((double)all) );
  printf("%lf\n",r);
  scanf("%*s");
}