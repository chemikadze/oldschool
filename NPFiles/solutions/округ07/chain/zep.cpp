//---------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

#ifdef _DEBUG
#include <conio.h>
#endif

//---------------------------------------------------------------------------

struct sp
{
  int sm;
  struct sp* next;
};

typedef struct sp tp;

int m, k;
int max=-1;
char s[250000];
int pos[250000];
int len[250000];
int pref[250000];

int x[250000];
tp* xpref[250000];

int findpref(int sm, int big)
{
  tp* p=xpref[big];
  while (p!=NULL)
  {
    if ((p->sm)!=sm)
    {
      if ((p->sm)>sm) return 0;
      p=p->next;
    }
    else
      return 1;
  }
  return 0;
}

void addpref(int sm, int big)
{
  tp* p=xpref[big];
  tp* np;
  while (p!=NULL)
  {
    if ((p->sm)>sm)
      break;
  }
  np=new tp;
  np->sm=sm;
  np->next=p;
  p=np;
}

int prefix(int a, int b)
{
  if (len[a]>=len[b])
    return 0;
  if (pref[b]>=b-a || findpref(a, b))
    return 1;
  int i, j;
  for (i=0; i<len[a]; i++)
    if (s[pos[a]+i]!=s[pos[b]+i])
      return 0;
  addpref(a, b);
  return 1;
}

int main(int argc, char* argv[])
{
  int i, j;
  int l, r;
  int maxl=0, maxr=0;
  char c[250000];
  char cc[250000];

  
  #ifndef _DEBUG
  freopen("chain.in", "r", stdin);
  freopen("chain.out", "w", stdout);
  #endif

  scanf("%d", &m);
  for (i=0; i<m; i++)
  {
    scanf("%s", &c);
    len[i]=strlen(c);
    l=0;
    if (i)
    {
      if (len[i-1]<len[i])
      {
        for (l=0; l<len[i-1]; l++)
          if (s[pos[i-1]+l]!=c[l])
          {
            l=0;
            pos[i]=pos[i-1]+len[i-1];
            break;
          }
      }
      else
      {
        l=0;
        pos[i]=pos[i-1]+len[i-1];
      }
      if (!pos[i])
      {
        pos[i]=pos[i-1];
        pref[i]=pref[i-1]+1;
      }
    }
    for (j=0; j<len[i]-l; j++)
      s[pos[i-1]+len[i-1]+j]=c[j+l];
  }

  scanf("%d", &k);
  for (i=0; i<k; i++)
  {
    scanf("%d", &x[i]);
    x[i]--;
  }

  for (i=0; i<k; i++)
  {
    for(j=i+1; j<k; j++)
      if (!prefix(x[j-1],x[j]))
      {
        if (j-i-1>max)
        {
          maxl=i;
          maxr=j-1;
          max=j-i-1;
        }
        break;
      }
    if (j==k-1 && j-i-1>max)
    {
      maxl=i;
      maxr=j-1;
      break;
    }
    i=j-1;
  }

FOUND:
  printf("%d %d", maxl+1, maxr+1);

  #ifdef _DEBUG
  getch();
  #endif

  return 0;
}
//---------------------------------------------------------------------------
