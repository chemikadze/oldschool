//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma argsused

FILE *in =fopen("color.in" , "r");
FILE *out=fopen("color.out", "w");

//bool **a;
#define _X 10
#define _Y 10
bool a[_X][_Y];
int b[_X][_Y][4];
int N, K, M;

int main(int argc, char* argv[])
{
  register int i, j;
  register int x, y;
  char s[10];
  char o[4][10];
  register int oi=0;
  fscanf(in, "%d %d %d", &N, &M, &K);
  //a=new bool*[N];
  //for (i=0; i<N; i++)
    //a[i]=new bool[M];
  for (i=0; i<N; i++)
    for (j=0; j<M; j++)
    {
      if (i>0)
        b[i][j][0]=i-1;
      else
        b[i][j][0]=-1;
      if (j<M-1)
        b[i][j][1]=j+1;
      else
        b[i][j][1]=-1;
      if (i<N-1)
        b[i][j][2]=i+1;
      else
        b[i][j][2]=-1;
      if (j>0)
        b[i][j][3]=j-1;
      else
        b[i][j][3]=-1;
    }
  for (i=0; i<K; i++)
  {
    fscanf(in, "%s %d %d", &s, &x, &y);
    x--;y--;
    if (s[0]=='N')
    {
      for (j=0; j<4; j++)
        if (b[y][x][j]>=0)
        {
          if (j%2)
            sprintf(o[oi++], "%d %d\0", b[y][x][j]+1, y+1);
          else
            sprintf(o[oi++], "%d %d\0", x+1, b[y][x][j]+1);
        }
      fprintf(out, "%d\n", oi);
      while (oi>0)
        fprintf(out, "%s\n", o[--oi]);
    }
    else
    {
      a[y][x]=true;

      j=y;
      while (j>=0 && a[j][x])
        j--;
      if (y<N-1 && j>=0)
        b[y+1][x][0]=j;
      else
        b[y+1][x][0]=-1;

      j=x;
      while (j<M && a[y][j])
        j++;
      if (x>0 && j<M)
        b[y][x-1][1]=j;
      else
        b[y][x-1][1]=-1;

      j=y;
      while (j<N && a[j][x])
        j++;
      if (y>0 && j<N)
        b[y-1][x][2]=j;
      else
        b[y-1][x][2]=-1;

      j=x;
      while (j>0 && a[y][j])
        j--;
      if (j<M-1 && j>=0)
        b[y][x+1][3]=j;
      else
        b[y][x+1][3]=-1;

    }
  }
  fclose(in);
  fclose(out);
  return 0;
}
//---------------------------------------------------------------------------
