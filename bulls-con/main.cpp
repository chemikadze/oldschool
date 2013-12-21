#include <stdio.h>
#include <string.h>
#include <iostream>
#include "bulls.h"
using namespace std;
 
void errormsg()
{
      printf("Error: wrong syntax.\nProper program using: bulls [len] [digits]\n\'len\' and \'digits\' must be an natural value lesser than 10, len <= digits");
}

int main(int argc, char* argv[])
{ 
  Bulls* bulls;
  const char* s;
  int b, c;
  int len=4, base=9;
  if (argc==3)
  {
    len=argv[1][0]-'0';
    base=argv[2][0]-'0';
    if (len>base || len>9 || base>9 || strlen(argv[1])>1 || strlen(argv[2])>1)
    {
      errormsg();
      return 1;
    }
  }
  else
    if (argc!=1)
    {
      errormsg();
      return 1;
    }
  bulls=new Bulls(len, base);
  printf("\"Bulls and cows\" using bulls.cpp " BULLS_VERSION " by Chemikadze, 2008.\nEnter bulls and cows, bulls are right digits on right places, cows are right digits on wrong places.\n");
  do
  {
    s=bulls->getnext();
    if (s==NULL)
    {
      printf("Computer: sorry, but one of us have mistaken...\n");
      return 1;
    }
    printf("Computer: %s\n     You: ", s);
   bc_scan:
    scanf("%d %d", &b, &c); 
    if (c+b>len || b>len || c>len || b<0 || c<0)
    {
      printf("Computer: sorry, but you have mistaken...\n     you: ");
      goto bc_scan;
    }
  }
  while (!bulls->setbc(c+b, b));
  printf("Computer win with %d steps!\n\n", bulls->getsteps());
  delete bulls;
  return 0;
}
