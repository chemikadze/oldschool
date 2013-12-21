#include <stdio.h>
#include <conio.h>
#include <math.h>

#define uint  unsigned int
#define uchar unsigned char

int N, M;             //N=high/width    M=lines
int  sqr[100];       //sqare tab
int  len[100];       //sqares of lines
char a[101][101];    //
uint step=0;

int isZ(double x)
{
  return ( x==(double)((int)(x)) );
}

int go(int x, int y)
{
    int rv=0;
    double p_sqrt, p_dy;
    int dx, dy, i;

    if ( (x==0 && y==0 && step>0 && step<M) || x<0 || y<0 || x>N || y>N )
      return 0;

    if (x==0 && y==0 && step==M)
      {rv=1;goto END;}

    if (a[x][y])
      return 0;

    a[x][y]=1;
    step++;
    p_sqrt=(int)(sqrt(len[step-1]));
    for (dx=0; dx<=p_sqrt/2+1; dx++)
    {
      p_dy=(len[step-1]-sqr[dx]>=0) ? sqrt(len[step-1]-sqr[dx]) : -1;
      if (isZ(p_dy) && p_dy>0)
      {
	dy=int(p_dy);

	if (go( x+dx , y+dy )) {rv=1;goto END;}
	if (go( x+dy , y+dx )) {rv=1;goto END;}

	if (go( x+dx , y-dy )) {rv=1;goto END;}
	if (go( x+dy , y-dx )) {rv=1;goto END;}

	if (go( x-dx , y+dy )) {rv=1;goto END;}
	if (go( x-dy , y+dx )) {rv=1;goto END;}

	if (go( x-dx , y-dy )) {rv=1;goto END;}
	if (go( x-dy , y-dx )) {rv=1;goto END;}
      }
    }
END:
  step--;
  a[x][y]=0;
  if (rv && step!=M-1)
    printf("%d %d\n", x, y);
  return rv;
}

int main()
{
  int i, j;

  scanf("%d %d", &N, &M);
  for (i=0; i<M; i++)
    scanf("%d", &len[i]);
  for (i=1; i<100 && sqr[i-1]<N; i++)
    sqr[i]=i*i;

  if (!go(0,0))
  {
    printf("Net reshenij...\n");
    getch();
    return 0;
  }

  getch();
  return  0;
}