#include <stdio.h>

int arr[8][8];
int n;

void print()
{
  int i, j;
  for (i=1; i<=7; i++, printf("\n"))
    for (j=1; j<=7; j++)
      printf("%3d ", arr[i][j]);
  printf("\n");
}

int main()
{
  int i, j;
  getchar();
  for (n=1, i=1; i<=4; i++)
  {
    for (j=1; j<=7-i*2+1; j++)
    {
      arr[i][j+i-1]=n+j-1;
      arr[j+i-1][7-i+1]=n+(7-i*2)*1+j;
      arr[7-i+1][7-j-i+2]=n+(7-i*2)*2+j+1;
      arr[7-j-i+2][i]=n+(7-i*2)*3+j+2;
    }
    if (i==4) arr[4][4]=49;
    n+=j+(7-i*2)*3+2;
  }
  print();
}
