//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

typedef struct sstack
{
  char c;
  struct sstack* next;
} tstack;

tstack *stack;

void push(tstack* &top, char c)
{
  tstack* p;
  p=new tstack;
  p->c=c;
  p->next=top;
  top=p;
}

char pop(tstack* &top)
{
  char c;
  tstack* p;
  c=top->c;
  p=top;
  top=top->next;
  delete p;
  return c;
}

inline bool islett(char c)
{
  return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

int main(int argc, char* argv[])
{
  char c;

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  while (c=fgetc(stdin))
  {
    if (feof(stdin)) break;
    if (islett(c))
      push(stack, c);
    else
    {
      while (stack!=NULL)
        fputc(pop(stack), stdout);
      fputc(c, stdout);
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
