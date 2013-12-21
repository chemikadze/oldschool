//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N;
char s[9];
int  c[8];
int  h[8]; int sc;

int main(int argc, char* argv[])
{
  register int i, j;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%s", s);
  for (i=0; i<8; i++)
  {
    for (j=0; j<sc && h[j]!=s[i]; j++);
    if (j==sc)
      h[sc++]=s[i];
    c[j]++;
    if (c[h[sc]]>4)
    {
      printf("0"); return 0;
    }
  }
  printf("1");
  return 0;
}
//---------------------------------------------------------------------------
