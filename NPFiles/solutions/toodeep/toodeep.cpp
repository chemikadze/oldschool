//---------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

//---------------------------------------------------------------------------

int N;
char s[10001];

int main(int argc, char* argv[])
{
  register int i, j;
  register int sl, deep;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &N);
  scanf("%s", s);
  sl=strlen(s);
  for (i=deep=0; i<sl; i++)
  {
    if (s[i]=='(')
    {
      deep++;
      if (deep<=N)
        fputc(s[i], stdout);
    }
    else
    {
      if (deep<=N)
        fputc(s[i], stdout);
      deep--;
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
 