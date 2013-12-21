#include <stdio.h>

double S;
int ans[4];

int main()
{
  double i, j, k;
  double t;
  int start;
  scanf("%d", &start);
  S=start;
  printf("===%d===\n", start);
  //for (S=start; S<start+100; S++)
  {
  ans[0]=0;
    //scanf("%lf", &S);
  for (i=1; i<=S; i++)
    for (j=1; j<=S; j++)
      for (k=1; k<=S; k++)
      {
        if ( t=((i+j+k)*(i+j-k)*(i+k-j)*(j+k-i))==S*S*16 )
        {  
	  printf("%.0lf %.0lf %.0lf\n", i, j, k);      // DOBAVIT STORONbI!!!!!!!!!!!!!!!!!!!!
	  ans[0]++;  
        }
	if (t>S*S*2)
          break;
      }
  if (ans[0])
    printf("S=%.0lf n=%d\n", S, ans[0]/3);  
  //printf("Всего: %d\n", ans[0]);
  }
  return 0;
}
