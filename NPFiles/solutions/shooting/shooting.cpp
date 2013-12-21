//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

bool a[6][6];
bool ans[6][6];
int cnt=0;
int  s[6];
int  m[6];

void snipe(char ps, char pm)
{
  if (pm==6) {ps++; pm=0;}
  if (ps==6)
  {
    //if (!cnt)
      for (char i=0; i<6; i++)
        for (char j=0; j<6; j++)
          ans[i][j]=a[i][j];
    cnt++;
    return;
  }
  if (!s[ps]) { snipe(ps+1, 0); return; }
  if (6-pm<s[ps]) return;
  if (6-pm>s[ps]) snipe(ps, pm+1);
  if (m[pm]>0 && s[ps]>0)
  {
    s[ps]--;
    m[pm]--;
    //if (!cnt)
      a[ps][pm]=true;
    snipe(ps, pm+1);
    //if (!cnt)
      a[ps][pm]=false;
    s[ps]++;
    m[pm]++;
  }
}

int main(int argc, char* argv[])
{
  char i, j;

  freopen("shooting.in", "r", stdin);
  freopen("shooting.out", "w", stdout);

  for (i=0; i<6; i++) scanf("%d", &s[i]);
  for (i=0; i<6; i++) scanf("%d", &m[i]);

  snipe(0, 0);
  printf("%d\n", cnt);
  if (cnt==1)
    for (i=0; i<6; i++, printf("\n"))
      for (j=0; j<6; j++)
        printf("%d ", ans[i][j]);

  return 0;
}
//---------------------------------------------------------------------------
