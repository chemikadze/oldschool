//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <algorithm>
#pragma hdrstop

using namespace std;

//---------------------------------------------------------------------------

#pragma argsused

double a, b, c, d;

int main(int argc, char* argv[])
{
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  if (a>b) swap(a, b);
  if (c>d) swap(c, d);

  if (c>a || d>b) printf("NO");
  else            printf("YES");

  getch();
  return 0;
}
//---------------------------------------------------------------------------
 