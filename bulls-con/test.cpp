#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include "bulls.h"
using namespace std;

const int len=4;
const int base=9;

void calcbc(const char* s1, const char* s2, int &cows, int &bulls)
{
  cows=bulls=0;
  int i;
  for (i=0; i<strlen(s1); i++)
  {
    if (exist(s1, s2[i]))
      cows++;
    if (s1[i]==s2[i])
      bulls++;
  }
}
 
int main()
{
  Bulls b(len, base);
  int w[base];
  int i, maxsteps=0;
  char* maxs;
  double allsteps=0;
  int cows=4, bulls=0;
  for (i=0; i<b.getstr().size(); i++)
  {
    do
    {
      calcbc(b.getnext(), b.getstr()[i], cows, bulls);
    }
    while (!b.setbc(cows, bulls));
    if (b.getsteps()>maxsteps)
    {
      maxsteps=b.getsteps();
      maxs=b.getstr()[i];
    }
    allsteps+=b.getsteps();
    b.clear();
  }  
  printf("Max steps = %d on %s\nAverage = %lf\n", maxsteps, maxs, allsteps/double(i));
  return 0;
}
