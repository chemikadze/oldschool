#include <stdio.h>
#include <conio.h>

int N;

int a[7]= {1,  5,  10, 50, 100,500,1000};
char c[7]={'I','V','X','L','C','D','M'};


int main()
{
  int i;

  scanf("%d",&N);

  while (N>0)
  {
     for (i=0;i<7 && N/a[i];i++);
     i--;
     if (i>0 && (N-a[i])/a[i-1]==4)
     {
       printf("%c",c[i-1]);
       N+=a[i-1];
       continue;
     }
     if (N/a[i]==4 && i!=6)
     {
       printf("%c",c[i]);
       N+=a[i];
       continue;
     }
     N-=a[i];
     printf("%c",c[i]);
  }
  printf("\n");
  getch();
}