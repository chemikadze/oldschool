#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define MAX 32000

int main()
{
  unsigned i;
  short c;

  clrscr();
  //textbackground(WHITE);

  for (i=1; i<MAX; i++)
  {
    c=*((unsigned char*)i);
    textcolor(c%8);
    cprintf("%X%X ", c/0x10, c%0x10);
    if (!(i%16))
    {
      delay(500);
      printf("\n");
    }
  }
}