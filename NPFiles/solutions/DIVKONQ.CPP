// REDONE TO A B C!!!!!!!!!!!!!!


#include <stdio.h>
#include <conio.h>


#define NOZERO(_X) ( ( (_X)>0 ) ? (_X) : (0) )

int N;
int   p[100][4];    //tochki
float l[100][2];    //linii
float x[10][10][2];  //peresech vseh    / razmer 10!!!!
int   X[100];
float pnt[100][2];//tochki peresech V

int   w[100];       //activnost linii

int V=0;
int E=0;


void addln(int i, float x, float y)
{
  int j;

  for (j=0; j<X[i]; j++)
  {
    if (::x[i][j][0]==x && ::x[i][j][1]==y)
      return;
  }

  ::x[i][j][0]=x;
  ::x[i][j][1]=y;
  X[i]++;
}

void addpnt(int i, int j)
{
  float x,y;

  x=(l[j][1]-l[i][1])/(l[i][0]-l[j][0]);
  y=l[i][0]*x+l[i][1];
  addln(i,x,y);
  addln(j,x,y);
  for (i=0; i<V; i++)
    if (pnt[i][0]==x && pnt[i][1]==y)
      return;
  pnt[i][0]=x;
  pnt[i][1]=y;
  V++;
}


int main()
{
  int i, j;
  float B,C;

  scanf("%d", &N);
  for (i=0; i<N; i++)
  {
    w[i]=1;
    for (j=0; j<4; j++)
      scanf("%d",&p[i][j]);
    B=(p[i][1]-p[i][3])/(p[i][0]-p[i][2]);
    C=p[i][1]-B*p[i][0];
    l[i][0]=B;
    l[i][1]=C;
  }

  for (i=0; i<N; i++)
    if (w[i])
      for (j=i+1; j<N; j++)
	if (!w[i])
	  if (l[i][0]==l[j][0] && l[j][1]==l[j][1])
	    w[i]=0;

  for (i=0; i<N; i++)
    if (w[i])
      for (j=i+1; j<N; j++)
	if (w[i])
	{
	  if (l[i][0]!=l[j][0])
	    addpnt(i,j);
	}

  for (i=0; i<N; i++)
    E+=NOZERO(X[i]-1);

  if (V>0)
    printf("%d", E-V+1+N*2);
  else
    printf("%d", N+1);


  getch();

  return 0;
}