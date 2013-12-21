//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N;
int t1, t2;
int p1, p2, p3;

int ans;

int main(int argc, char* argv[])
{
  int dt2=0;
  #ifndef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  scanf("%d %d %d %d %d %d", &N, &t1, &t2, &p1, &p2, &p3);
  if (N>=p1)
    ans+=t1;
  N-=p1;
  while (dt2<t2 && N>0)
  {
    N-=p2;
    dt2++;
  }
  ans+=dt2;
  while (N>0)
  {
    ans++;
    N-=p3;
  }
  printf("%d", ans);
  #ifdef _DEBUG
  while (fgetc(stdin)!='\n');
  fgetc(stdin);
  #endif
  return 0;
}
//---------------------------------------------------------------------------
