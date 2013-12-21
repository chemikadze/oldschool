#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <deque>
#include <time.h>
#include "bulls.h"
using namespace std;

bool exist(const char *s, char c)
{
  int i;
  for (i=0; i<strlen(s); i++)
    if (s[i]==c)
      return true;
  return false;
}

int pow(int base, int power)
{
  int ans=1;
  int i;
  for (i=0; i<power; i++)
    ans*=base;
  return ans;
}

int factorial(int n)
{
  int i, ans=1;
  for (i=2; i<=n; i++)
    ans*=i;
  return ans;
}

const char* Bulls::getnext()
{
  int i;
  for (i=rand()%str.size(); i<str.size() && !can[i]; i++);
  if (i<str.size())
    return curs=str[i];
  else
  {
    for (i=0; i<str.size() && !can[i]; i++);
    if (i<str.size())
      return curs=str[i];
  }
  return curs=NULL;
}

bool Bulls::setbc(int cows, int bulls)
{
  int i, j, x;
  steps++;
  if (bulls==len) 
    return true;
  for (i=0; i<str.size(); i++)
    if (can[i])
    {
      for (x=j=0; j<len; j++)
        if (curs[j]==str[i][j]) 
          x++;
      if (x!=bulls)
      {
        can[i]=false;
        continue;
      }
      for (x=j=0; j<len; j++)
        if (exist(curs, str[i][j]))
          x++;
      if (x!=cows)
        can[i]=false;
    }
  return false;
}

const deque <char*> Bulls::getstr()const
{
  return str;
}

void Bulls::clear()
{
  int i;
  time_t t;
  srand((unsigned)time(&t));
  w.assign(w.size(), true);
  can.assign(can.size(), true);
  steps=0;
}

int Bulls::getsteps()
{
  return steps;
}

Bulls::Bulls(int mlen, int mbase) 
{
  int i, j;
  char* s;
  time_t t;
  srand((unsigned)time(&t));
  len=mlen; 
  base=mbase;
  w.resize(base, true);
  loop.resize(len, 0);
  steps=0;
  i=0;
  do
  { 
    for (; loop[i]<base; loop[i]++)  
      if (w[loop[i]])
        if (i==(len-1))
        {
          s=new char[len+1];
          for (j=0; j<len; j++)
            s[j]='1'+loop[j];
          s[j]='\0';
          str.push_back(s);
          can.push_back(true);
        }
        else
        {
          w[loop[i]]=false;
          loop[++i]=0;
          break;
        }
    if  (loop[i]==base) 
    {
      i--;
      w[loop[i]++]=true;
    }
  }
  while (i || loop[i]!=base);
}


Bulls::~Bulls()
{
  while (str.size())
  {
    delete[] str.back();
    str.pop_back();
  }
}
