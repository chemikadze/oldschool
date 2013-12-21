#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

FILE* in=fopen("sort.in","r");
FILE* out=fopen("sort.out","w");

bool** w;
int a[5000];
int N;

void swap(int &a,int &b)
{
  int buf=a;
  a=b;
  b=buf;
}

int main(int argc, char *argv[])
{
  int i,j;
  int x,y;
  int buf;
  bool changed;
  clrscr();
  printf("Press enter to start...");
  scanf("%*c");
  printf("Reading input file...\n");
  fscanf(in,"%d",&N);
  w=new bool*[N+1];
  for (i=0;i<N;i++)
  {
    fscanf(in,"%d",&a[i]);
    w[i]=new bool[N+1];
  }
  w[N]=new bool[N+1];

  for (i=0;i<N;i++)
    for (j=0;j<N;j++)
    {
      w[i][j]=true;
    }

  fscanf(in,"%d",&buf);
  for (i=0;i<buf;i++)
  {
    fscanf(in,"%d %d",&x,&y);
    w[x][y]=w[y][x]=false;
  }
  printf("Solving...\n");
  for (i=0;i<N-1;i++)
  {
    changed=false;
    for (j=0;j<N-1;j++)
      if (a[j]>a[j+1] && w[ a[j] ][ a[j+1] ])
      {
	changed=true;
        int buf=a[j];
	a[j]=a[j+1];
	a[j+1]=buf;
      }
    if (!changed)
      break;
  }
  printf("Solving complete...\nWriting output file...\n");
  for (i=0;i<N;i++)
    fprintf(out,"%d ",a[i]);
  fclose(in);
  fclose(out);
  printf("End of the program...\nPess enter to exit...");
  scanf("%*c");
  return 0;
}
