//---------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

//---------------------------------------------------------------------------

int N, M;
char s[101];
int p['z'-'a'+1];

inline bool islett(const char c)
{
  return c>='a' && c<='z';
}

int main(int argc, char* argv[])
{
  bool first=true;
  int hi=0, lo=0;
  register int sl;
  register int i, j;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &N, &M);
  for (i=0; i<N; i++)
  {
    scanf("%s", s);
    sl=strlen(s);
    for (j=0; j<sl; j++)
    {
      if (islett(s[j]))
      {
        if (s[j+1]=='^')
        {
          p[s[j]-'a']+=s[j+2]-'0';
          j+=2;
        }
        else
          p[s[j++]-'a']++;
      }
    }
  }
  for (i=0; i<M; i++)
  {
    scanf("%s", s);
    sl=strlen(s);
    for (j=0; j<sl; j++)
    {
      if (islett(s[j]))
      {
        if (s[j+1]=='^')
        {
          p[s[j]-'a']-=s[j+2]-'0';
          j+=2;
        }
        else
          p[s[j++]-'a']--;
      }
    }
  }
  for (i=0; i<sizeof(p)/sizeof(p[0]); i++)
    if (p[i]>0)
      hi++;
    else
      if (p[i]<0)
        lo++;

  if (hi)
  {
    for (i=0; i<sizeof(p)/sizeof(p[0]); i++)
      if (p[i]>0)
      {
        if (!first) printf("*");
        first=false;
        if (p[i]>1)
          printf("%c^%d", char(i)+'a', p[i]);
        else
          printf("%c", char(i)+'a');
      }
  }
  else
  printf("1");
  printf("\n");
  first=true;
  if (lo)
  {
    for (i=0; i<sizeof(p)/sizeof(p[0]); i++)
      if (p[i]<0)
      {
        if (!first) printf("*");
        first=false;
        if (p[i]<-1)
          printf("%c^%d", char(i)+'a', -p[i]);
        else
          printf("%c", char(i)+'a');
      }
  }
  else
  printf("1");
  return 0;
}
//---------------------------------------------------------------------------
 