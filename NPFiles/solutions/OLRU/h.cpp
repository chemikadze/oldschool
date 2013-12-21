//---------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
using namespace std;

#ifdef _DEBUG
#include <conio.h>
#endif

//---------------------------------------------------------------------------

unsigned long N, M;
unsigned long R;

int main(int argc, char* argv[])
{
  #ifndef _DEBUG
  freopen("h.in", "r", stdin);
  freopen("h.out", "w", stdout);
  #endif

  scanf("%ld %ld", &N, &M);
  R=N/2+M/2;
  printf("%d", R);

  #ifdef _DEBUG
  getch();
  #endif

  return 0;
}
//---------------------------------------------------------------------------
 