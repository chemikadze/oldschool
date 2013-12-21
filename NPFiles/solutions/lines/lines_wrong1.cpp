//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>

//---------------------------------------------------------------------------

double ln[100][2];
int    pt[100][4];
bool   w[100];
int N;

double x[10000][2];

int X=0,L,R;

int main(int argc, char* argv[])
{
  int i,j;
  scanf("%d",&N);
  L=N;
  for (i=0; i<N; i++)
  {
    w[i]=true;
    for (j=0; j<4; j++)
      scanf("%d",&pt[i][j]);
    ln[i][0]=(pt[i][3]-pt[i][1])/(pt[i][2]-pt[i][0]);
    ln[i][1]=pt[i][1]-pt[i][0]*ln[i][0];
  }

  for (i=0; i<N; i++)
    if (w[i])
      for (j=i+1; j<N; j++)
      if (w[j])
        {
          w[j]=!(ln[i][0]==ln[j][0] && ln[i][1]==ln[j][1]);
          if (!w[j])
            L--;
        }

  for (i=0; i<N; i++)
  if (w[i])
    for (j=i+1; j<N; j++)
      if (ln[i][0]!=ln[j][0] && w[j])
      {
        double px,py;
        int p;

        px=(ln[j][1]-ln[i][1])/(ln[i][0]-ln[j][0]);
        py=ln[i][0]*px+ln[i][1];

        for (p=0; p<X; p++)
          if (x[p][0]==px && x[p][1]==py)
            goto WOZ;
        x[p][0]=px;
        x[p][1]=py;
        X++;
        WOZ:
        ;
      }

  if (X!=1)
    R=X+L+1;
  else
    R=L*2;  
  printf("%d",R);

  #ifdef _DEBUG
  getch();
  #endif

  return 0;
}
//---------------------------------------------------------------------------
