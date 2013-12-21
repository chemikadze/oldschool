#include <stdio.h>
#include <conio.h>


#define min( A , B ) ( ((A) < (B)) ? (A) : (B) )
#define max( A , B ) ( ((A) > (B)) ? (A) : (B) )

int k[2003][2];
int I, J, N;
double FI, FJ;

int main()
{
  int i, di;
  double F0, F1, FN;
  scanf("%d %lf %d %lf %d", &I, &FI, &J, &FJ, &N);
  k[0][0]=1;
  k[1][1]=1;
  di=-min(min(I,J),N)+2;
  I+=di;
  J+=di;
  N+=di;
  for (i=2; i<=max(max(I,J),N); i++)
  {
    k[i][0]=k[i-1][0]+k[i-2][0];
    k[i][1]=k[i-1][1]+k[i-2][1];
  }
  double &A=FI;
  double &B=FJ;
  double &x=F0;
  double &y=F1;
  double &m=k[I][0];
  double &n=k[I][1];
  double &p=k[J][0];
  double &q=k[J][1];

  y=(B*m-p*A)/(q*m-p*n);
  x=(A-n*y)/m;
  FN=k[N][0]*x+k[N][1]*y;
  printf("%ld\n", long(FN));
  getch();
  return 0;
}