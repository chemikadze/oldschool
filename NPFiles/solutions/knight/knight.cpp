//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop

int a[10][10];
int p[10][10];
bool w[10][10];
int N;

int sx,sy;
int fx,fy;
int i=0;

//---------------------------------------------------------------------------

void jump(int x,int y,int lx,int ly)
{
  w[x][y]=true;
  i++;
  if (i>a[fx][fy])
    goto END;
  if (a[x][y]>a[lx][ly]+1)
  {
    a[x][y]=a[lx][ly]+1;
    p[x][y]=lx+ly*N;
    if (x==fx && y==fy)
      goto END;
  }
  if (x>0 && y>1       && (x-1!=lx || y-2!=ly) && !w[x-1][y-2]) jump(x-1,y-2,x,y);//1
  if (x<N-1 && y>1     && (x+1!=lx || y-2!=ly) && !w[x+1][y-2]) jump(x+1,y-2,x,y);//2
  if (x<N-2 && y>0     && (x+2!=lx || y-1!=ly) && !w[x+2][y-1]) jump(x+2,y-1,x,y);//3
  if (x<N-2 && y<N-1   && (x+2!=lx || y+1!=ly) && !w[x+2][y+1]) jump(x+2,y+1,x,y);//4
  if (x<N-1 && y<N-2   && (x+1!=lx || y+2!=ly) && !w[x+1][y+2]) jump(x+1,y+2,x,y);//5
  if (x>0 && y<N-2     && (x-1!=lx || y+2!=ly) && !w[x-1][y+2]) jump(x-1,y+2,x,y);//6
  if (x>1 && y<N-1     && (x-2!=lx || y+1!=ly) && !w[x-2][y+1]) jump(x-2,y+1,x,y);//7
  if (x>1 && y>0       && (x-2!=lx || y-1!=ly) && !w[x-2][y-1]) jump(x-2,y-1,x,y);//8
END:
  w[x][y]=false;
  i--;
}

void printpath(int x,int y)
{
  if (!(x==sx && y==sy))
    printpath(p[x][y]%N,p[x][y]/N);
  printf("(%d, %d) ",x+1,y+1);
}

#pragma argsused
int main(int argc, char* argv[])
{
  int i,j;

  for (i=0;i<10;i++)
    for (j=0;j<10;j++)
      a[i][j]=10000;
  scanf("%d",&N);
  scanf("%d %d",&sx,&sy);
  scanf("%d %d",&fx,&fy);
  sx--;sy--;fx--;fy--;
  a[sx][sy]=0;
  jump(sx,sy,sx,sy);
  printf("%d\n",a[fx][fy]);
  printpath(fx,fy);
  scanf("%*s");
  return 0;
}
//---------------------------------------------------------------------------
