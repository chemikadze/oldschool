#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define isopen(x) (x=='(' || x=='{' || x=='[')

char s[81];
char stack[40];
int top=0;

void push(char c)
{
  stack[top++]=c;
}

char pop()
{
  if (top==0) return 'X';
  return stack[--top];
}

int main()
{
  int len;
  int i;
  gets(s);
  len=strlen(s);
  if (len%2) goto NO;
  for (i=0;i<len;i++)
  {
    if (isopen(s[i]))
      push(s[i]);
    else
    {
      switch (pop())
      {
	case '[':if (s[i]!=']') goto NO;
		 break;
	case '{':if (s[i]!='}') goto NO;
		 break;
	case '(':if (s[i]!=')') goto NO;
		 break;
	default :goto NO;
      }
    }
  }
  if (top!=0) goto NO;
  printf("YES");
  scanf("%*s");
  return 0;
NO:
  printf("NO");
  scanf("%*s");
  return 0;
}