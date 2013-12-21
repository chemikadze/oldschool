//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------------

#define WH 0
#define GR 1
#define BL 2

const char* gold="золото";    //DOS-format!!!!!!!!!!!!
const char* pb="свинец";

int N, M;
int goldi;
int pbi;
char s[100][11];
int a[100][100];
int t[100][100];
int ans[100];
int w[100];

int cmp(const void* s1, const void* s2)
{
  strcmp((char*)s1, (char*)s2);
}

int transist(int u)
{
  int v;
  int k;
  w[u]=GR;
  for (v=0; v<N; v++)
    if (a[u][v])
    {
      t[u][v]=1;
      ans[v]+=1;
      if (w[v]!=GR)
        transist(v);
    }
  for (v=0; v<N; v++)
    if (t[u][v])
      for (k=0; k<N; k++)
        t[u][k]=t[u][k] || t[v][k];
  w[u]=BL;      
}

int main(int argc, char* argv[])
{
  int i, j;
  int u, v;
  char rs[11];
  scanf("%d", &N);
  for (i=0; i<N; i++)
    scanf("%s", &s[i]);
  //qsort(s, N, sizeof(s[0]), cmp);
  //goldi=bsearch((void*)gold, s, N, sizeof(s[0]), cmp);
  for (i=0; i<N; i++)
    if (!strcmp(gold,s[i]))
    {
      goldi=i;
      break;
    }
  //pbi=bsearch((void*)pb, s, N, sizeof(s[0]), cmp);
  for (i=0; i<N; i++)
    if (!strcmp(pb,s[i]))
    {
      pbi=i;
      break;
    }
  scanf("%d", &M);
  for (i=0; i<M; i++)
  {
    scanf("%s", rs);
    //
    for (j=0; j<N; j++)
      if (!strcmp(rs,s[j]))
      {
        u=j;
        break;
      }
    do
    {
      scanf("%s", &rs);
      //v=bsearch((void*)rs, s, N, sizeof(s[0]), cmp);
      for (j=0; j<N; j++)
       if (!strcmp(rs,s[j]))
       {
         v=j;
         break;
       }
      a[u][v]=1;
    }
    while (getc(stdin)!='\n');
  }
  ans[pbi]=1;
  transist(pbi);
  printf("%d", ans[goldi]);
  getc(stdin);
  return 0;
}
//---------------------------------------------------------------------------
