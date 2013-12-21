//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <algorithm>

using namespace std;

//---------------------------------------------------------------------------

struct slen
{
  int c;
  int l;
};

typedef struct slen len;

const int maxN=1000001;
int N;
int a[maxN];
bool w[maxN];
int b[maxN];
len* l[maxN]; int hs=0;
int pos1[maxN];
int pos2[maxN];

int cmp1(const void* a, const void* b)
{
  return ((len*)b)->l-((len*)a)->l;
}

int cmp2(const void* a, const void* b)
{
  return pos1[((len*)b)->c]-pos1[((len*)a)->c];
}

int main(int argc, char* argv[])
{
  int i, j, k;
  scanf("%d", &N);
  for (i=0; i<maxN; i++)
    l[i]=new len;
  for (i=1; i<=N; i++)
  {
    scanf("%d", &a[i]);
  }
  for (i=1; i<=N; i++)
  {
    if (!pos1[a[i]])
      pos1[a[i]]=pos2[a[i]]=i;
    else
      if (i>pos2[a[i]])
      {
        pos2[a[i]]=i;
        l[a[i]]->l=pos2[a[i]]-pos1[a[i]];
        l[a[i]]->c=a[i];
      }
  }
  qsort(l, N+1, sizeof(len*),cmp1);
  for (i=1, w[i]=true; i<=N && l[i]->l>0; i++)
    for (j=2; j<=i && w[i]; j++)
    {
      w[i]=w[i] && pos2[i]>pos1[j] || pos2[j]>pos1[i];
    }
  qsort(l, N+1, sizeof(len*),cmp2);
  j=k=1;
  for (i=1; i<N; i++)
  {
    if (i<=pos1[l[j]->c])
      b[k++]=a[i];
    else
      i=pos2[l[j++]->c]+1;
  }
  printf("%d\n", k-1);
  for (i=1; i<k; i++)
    printf("%d ", b[i]);
  getch();  
  return 0;
}
//---------------------------------------------------------------------------
