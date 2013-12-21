//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

extern inline bool cmpcubes();
extern void init();
extern inline void rollup();
extern inline void rolldn();
extern inline void rolllt();
extern inline void rollrt();
extern inline bool iso(int x, int y);

const int MAXMIN=21;

struct scube
{
  int up;
  int dn;
  int lt;
  int rt;
  int fw;
  int bw;
};

typedef struct scube cube;

int a[9][9];
int x1, y1;
int x2, y2;
int path[65][2];
int  res[65][2];
cube *cur, *buf, *ft;
int maxp=64;

int pnt=0;

void step(int x, int y)
{
  if (path[0][0]>=res[0][0] || path[0][0]>=maxp)
    return;

  int ppt=0;
  path[++path[0][0]][0]=x;
  path[path[0][0]][1]=y;
  a[x][y]=path[0][0];
  if (x==x2 && y==y2)
  {
    if (cmpcubes())
    {
      int i;
      for (i=0; i<=path[0][0]; i++)
      {
        res[i][0]=path[i][0];
        res[i][1]=path[i][1];
      }
    }
    ppt++;
  }
  else
  {
    if (x>1)
      if (!a[x-1][y])
      {
        ppt++;
        rolllt();
        step(x-1,y);
        rollrt();
      }
    if (y>1)
      if (!a[x][y-1])
      {
        ppt++;
        rollup();
        step(x, y-1);
        rolldn();
      }
    if (y<8)
      if (!a[x][y+1])
      {
        ppt++;
        rolldn();
        step(x, y+1);
        rollup();
      }
    if (x<8)
      if (!a[x+1][y])
      {
        ppt++;
        rollrt();
        step(x+1, y);
        rolllt();
      }
  }
  if (!ppt)
    maxp=max(path[0][0],MAXMIN);
  path[0][0]--;
  a[x][y]=0;
}

int main(int argc, char* argv[])
{
  int i;
  char s[2];
  scanf("%1s%d", &s, &y1);
  x1=s[0]-'a'+1;
  scanf("%1s%d", &s, &y2);
  x2=s[0]-'a'+1;

  init();

  step(x1, y1);

  if (res[0][0]==65 && res[1][0]==0)
    res[0][0]=-1;
  printf("%d\n", res[0][0]);
  for (i=1; i<=res[0][0]; i++)
    printf("%c%d ", res[i][0]+'a'-1, res[i][1]);

  getch();
  return 0;
}
//-------------------------------------------------------------------------
bool cmpcubes()
{
  return ft->up==cur->up &&
         ft->dn==cur->dn &&
         ft->lt==cur->lt &&
         ft->rt==cur->rt &&
         ft->fw==cur->fw &&
         ft->bw==cur->bw;
}

void init()
{
  ft=new cube;
  cur=new cube;
  buf=new cube;
  ft->up=1;
  ft->dn=2;
  ft->lt=3;
  ft->rt=4;
  ft->fw=5;
  ft->bw=6;

  cur->up=ft->up;
  cur->dn=ft->dn;
  cur->lt=ft->lt;
  cur->rt=ft->rt;
  cur->fw=ft->fw;
  cur->bw=ft->bw;

  res[0][0]=65;
}

inline void rollup()
{
  buf->up=cur->bw;
  buf->bw=cur->dn;
  buf->dn=cur->fw;
  buf->fw=cur->up;

  buf->lt=cur->lt;
  buf->rt=cur->rt;

  swap(buf, cur);
}

inline void rolldn()
{
  buf->bw=cur->up;
  buf->dn=cur->bw;
  buf->fw=cur->dn;
  buf->up=cur->fw;

  buf->lt=cur->lt;
  buf->rt=cur->rt;

  swap(buf, cur);
}

inline void rolllt()
{
  buf->up=cur->rt;
  buf->rt=cur->dn;
  buf->dn=cur->lt;
  buf->lt=cur->up;

  buf->fw=cur->fw;
  buf->bw=cur->bw;

  swap(buf, cur);
}

inline void rollrt()
{
  buf->rt=cur->up;
  buf->dn=cur->rt;
  buf->lt=cur->dn;
  buf->up=cur->lt;

  buf->fw=cur->fw;
  buf->bw=cur->bw;

  swap(buf, cur);
}

inline bool iso(int x, int y)
{
  return (x>1 ? a[x-1][y] : 1)&&
         (y>1 ? a[x][y-1] : 1)&&
         (x<8 ? a[x+1][y] : 1)&&
         (y<8 ? a[x][y+1] : 1);
}

//---------------------------------------------------------------------------
