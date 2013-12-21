//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif

//---------------------------------------------------------------------------

struct spos
{
  short x, y;
};

typedef struct spos tpos;

int N, M;
long a[300+1][300+1];//Y, X
short hi[300+1];// i - X, val - Y
short lo[300+1];
short rt[300+1];// i - Y, val - X
short lt[300+1];
tpos pos[300l*300l/2+1][2];
long stack[300l*300l/2+1];
long top=0;

int main(int argc, char* argv[])
{
  int i, j;
  char chd;
  char exit;

  #ifndef _DEBUG
  freopen("mahjong.in", "r", stdin);
  freopen("mahjong.out", "w", stdout);
  #endif

  scanf("%ld %ld", &N, &M);
  for (i=1; i<=N; lt[i]=1, rt[i]=M, i++)  //y
    for (j=1; j<=M; hi[j]=1, lo[j]=N, j++)  //x
    {
      scanf("%ld", &a[i][j]);
      if (pos[a[i][j]][0].x)
      {
        pos[a[i][j]][1].x=j;
        pos[a[i][j]][1].y=i;
      }
      else
      {
        pos[a[i][j]][0].x=j;
        pos[a[i][j]][0].y=i;
      }
    }
  do
  {
    exit=0;
    for (i=1; i<=N; i++)         //lefter -------------------------------------
    if (lt[i]<=rt[i])
      {// opredelit nomer cveta
        long col=a[i][lt[i]];
        if (!col) continue;
        int y1=i, x1=lt[i];
        int x2, y2;
        y2=pos[col][pos[col][0].x==x1 && pos[col][0].y==y1].y;
        x2=pos[col][pos[col][0].x==x1 && pos[col][0].y==y1].x;
        // esli drugaya fishka s kraya to
        // udalit obe

        if (lt[y2]==x2)
        {
          a[y1][x1]=a[y2][x2]=0;

          while ((!a[y1][lt[y1]]) && lt[y1]<=rt[y1]) lt[y1]++;
          while ((!a[y2][lt[y2]]) && lt[y2]<=rt[y2]) lt[y2]++;

          while ((!a[hi[x1]][x1]) && hi[x1]<=lo[x1]) hi[x1]++;
          while ((!a[lo[x1]][x1]) && hi[x1]<=lo[x1]) lo[x1]--;

          while ((!a[hi[x2]][x2]) && hi[x2]<=lo[x2]) hi[x2]++;
          while ((!a[lo[x2]][x2]) && hi[x2]<=lo[x2]) lo[x2]--;

          while ((!a[hi[x1]][x1]) && hi[x1]<=lo[x1]) hi[x1]++;
          while ((!a[lo[x1]][x1]) && hi[x1]<=lo[x1]) lo[x1]--;
          stack[++top]=col;
          exit=exit || 1;
        }
        
      }
      for (i=1; i<=N; i++)         //righter ----------------------------------
      if (lt[i]<=rt[i])
      { // opredelit nomer cveta
        long col=a[i][rt[i]]; 
        if (!col) continue;
        int y1=i, x1=rt[i];
        int x2, y2;
        chd=0;
        y2=pos[col][pos[col][0].x==x1 && pos[col][0].y==y1].y;
        x2=pos[col][pos[col][0].x==x1 && pos[col][0].y==y1].x;
        // esli drugaya fishka s kraya to
        // udalit obe
        if (rt[y2]==x2)
        {
          a[y1][x1]=a[y2][x2]=0;

          while ((!a[y1][rt[y1]]) && lt[y1]<=rt[y1]) rt[y1]--;
          while ((!a[y2][rt[y2]]) && lt[y1]<=rt[y2]) rt[y2]--;

          while ((!a[hi[x1]][x1]) && hi[x1]<=lo[x1]) hi[x1]++;
          while ((!a[lo[x1]][x1]) && hi[x1]<=lo[x1]) lo[x1]--;


          while ((!a[hi[x2]][x2]) && hi[x2]<=lo[x2]) hi[x2]++;
          while ((!a[lo[x2]][x2]) && hi[x2]<=lo[x2]) lo[x2]--;

          while ((!a[hi[x1]][x1]) && hi[x1]<=lo[x1]) hi[x1]++;
          while ((!a[lo[x1]][x1]) && hi[x1]<=lo[x1]) lo[x1]--;
          stack[++top]=col;
          exit=exit || 1;
        }
      }
      for (i=1; i<=M; i++)         //upper ------------------------------------
      if (hi[i]<=lo[i])
      { // opredelit nomer cveta
        long col=a[hi[i]][i];  
        if (!col) continue;
        int y1=hi[i], x1=i;
        int x2, y2;
        chd=0;
        y2=pos[col][pos[col][0].x==x1 && pos[col][0].y==y1].y;
        x2=pos[col][pos[col][0].x==x1 && pos[col][0].y==y1].x;
        // esli drugaya fishka s kraya to
        // udalit obe
        if (hi[x2]==y2)
        {
          a[y1][x1]=a[y2][x2]=0;

          while ((!a[hi[x1]][x1]) && hi[x1]<=lo[x1]) hi[x1]++;
          while ((!a[hi[x2]][x2]) && hi[x2]<=lo[x2]) hi[x2]++;

          while ((!a[y1][rt[y1]]) && lt[y1]<=rt[y1]) rt[y1]--;
          while ((!a[y1][lt[y1]]) && lt[y1]<=rt[y1]) lt[y1]++;

          while ((!a[y2][rt[y2]]) && lt[y2]<=rt[y2]) rt[y2]--;
          while ((!a[y2][lt[y2]]) && lt[y2]<=rt[y2]) lt[y2]++;

          while ((!a[y1][rt[y1]]) && lt[y1]<=rt[y1]) rt[y1]--;
          while ((!a[y1][lt[y1]]) && lt[y1]<=rt[y1]) lt[y1]++;
          stack[++top]=col;
          exit=exit || 1;
        }

      }
      for (i=1; i<=M; i++)         //lower
      if (hi[i]<=lo[i])
      { // opredelit nomer cveta
        long col=a[lo[i]][i];    
        if (!col) continue;
        int y1=lo[i], x1=i;
        int x2, y2;
        chd=0;
        y2=pos[col][pos[col][0].x==x1 && pos[col][0].y==y1].y;
        x2=pos[col][pos[col][0].x==x1 && pos[col][0].y==y1].x;
        // esli drugaya fishka s kraya to
        // udalit obe
        if (lo[x2]==y2)
        {
          a[y1][x1]=a[y2][x2]=0;
          while ((!a[lo[x1]][x1]) && hi[x1]<=lo[x1]) lo[x1]--;
          while ((!a[lo[x2]][x2]) && hi[x2]<=lo[x2]) lo[x2]--;

          while ((!a[y1][rt[y1]]) && lt[y1]<=rt[y1]) rt[y1]--;
          while ((!a[y1][lt[y1]]) && lt[y1]<=rt[y1]) lt[y1]++;

          while ((!a[y2][rt[y2]]) && lt[y2]<=rt[y2]) rt[y2]--;
          while ((!a[y2][lt[y2]]) && lt[y2]<=rt[y2]) lt[y2]++;

          while ((!a[y1][rt[y1]]) && lt[y1]<=rt[y1]) rt[y1]--;
          while ((!a[y1][lt[y1]]) && lt[y1]<=rt[y1]) lt[y1]++;
          stack[++top]=col;
          exit=exit || 1;
        }
      }

  }
  while (exit && (top<(N*M/2)));

  printf("%ld\n", top);
  for (i=1; i<=top; i++)
    printf("%ld ", stack[i]);

  #ifdef _DEBUG
  getch();
  #endif

  return 0;
}
//---------------------------------------------------------------------------
