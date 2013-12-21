#include <stdio.h>
#include <conio.h>


int nod(int a,int b)
{
  return (b==0)?(a):(nod(b,a%b));
}

int A,B;

int main()
{
  int n;
  printf("Enter A and B: ");
  scanf ("%d %d",&A,&B);
  printf("NOD=%d\nNOK=%d\n",n=nod(A,B),0);
  getch();
}