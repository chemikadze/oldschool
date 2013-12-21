//---------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#ifdef _DEBUG
#include <conio.h>
#endif

//---------------------------------------------------------------------------

long double L, K;
long double A, B;
long double M, N;

inline long double sqr(long double a)
{
  return a*a;
}

int main(int argc, char* argv[])
{
  long double D;
  scanf("%Lf %Lf", &K, &L);
  D=sqr(2*K-L)-4*K;
  D=sqrt(D);
  //M=(-2*K+L+D)/2;
  //if (M<0)
  M=(-2*K+L-D)/2;
  N=K/M;
  A=M+1;
  B=N+1;  
  printf("%.0Lf %.0Lf", A, B);
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
