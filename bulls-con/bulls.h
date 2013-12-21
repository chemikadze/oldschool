#include <stdio.h>
#include <algorithm>
#include <deque>
using namespace std;

#define BULLS_VERSION "0.1.1"

class Bulls
{
  protected:
    int len;
    int base;
    deque <bool>  w;
    deque <char*> str;
    deque <bool>  can;
    deque <int>   loop;
    char *curs;
    int steps;

  public:
    const deque <char*> getstr() const;
    const char* getnext();
    bool setbc(int cows, int bulls);
    void clear();
    int getsteps();
    Bulls(int mlen, int mbase);
    ~Bulls();
};
bool exist(const char *s, char c);
  

