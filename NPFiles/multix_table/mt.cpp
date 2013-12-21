//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

//---------------------------------------------------------------------------

const int N=10;
bool w[10][10];
int a, b, ans, rans;
int rcount=0;
int mark;

int main(int argc, char* argv[])
{
  int i, j;
  printf("[NP] Multiplex_Tab 0.1\n[Nicolas_Programs] by Sokolov_Nikolay, 2008\n");
  printf("Answer this 10 questions:\n\n");
  for (i=0; i<N; i++)
  {
    do
    {
      a=rand()%8+2;
      b=rand()%8+2;
    }
    while (w[a][b] || w[b][a]);
    w[a][b]=w[b][a]=1;
    rans=a*b;
    printf("%2d * %2d = ", a, b);
    scanf("%d", &ans);
    if (ans==rans)
      rcount++;
    else
      printf("No! Right answer was %d\n", rans);
  }
  if (N-rcount == 0) mark=5;
  else if (N-rcount <= 2) mark=4;
  else if (N-rcount == 3) mark=3;
  else mark=2;
  printf("Right answers: %d\nMistakes: %d\nMark: %d\n", rcount, N-rcount, mark);
  printf("\n\nPress any key to exit...");
  getchar();
  return 0;
}
//---------------------------------------------------------------------------
