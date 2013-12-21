//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

FILE* in =fopen("reverse.in", "r");
FILE* out=fopen("reverse.out","w");

char stack[256];
int top;

#define issymb(CH) (CH>='A' && CH<='Z' || CH>='a' && CH<='z' || CH>='À' && CH<='ß' || CH>='à' && CH<='ÿ')
#define push(CH) (stack[top++]=CH)
#define pop() (stack[--top])

int main(int argc, char* argv[])
{
  char c;

  while ( (c=fgetc(in))!=EOF )
  {
    if ( issymb(c) )
      push(c);
    else
    {
      while ( top>0 )
        fputc(pop(), out);
      fputc(c, out);
    }
  }

  while ( top>0 )
    fputc(pop(), out);

  fclose(in);
  fclose(out);
  
  return 0;
}
//---------------------------------------------------------------------------
