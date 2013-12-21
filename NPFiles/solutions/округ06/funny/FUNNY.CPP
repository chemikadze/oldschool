#ifndef _DEBUG
#define _DEBUG
#include <conio.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#define uchar unsigned char

int N;
int A[100];
int ans;
int L;
short Ai[101][26];
int simp[26]={1, 2, 3, 5, 7, 11, 13, 17, 19, 23,
		29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
		71, 73, 79, 83, 89, 97};

int power(int i, int j)
{
  int r=1;
  while (j>0)
  {
    if (!(j%2))
    {
      r*=r;
      j/=2;
    }
    else
    {
      r*=i;
      j--;
    }
  }
  return r;
}

int calc(int pi, int pj)
{
  int i;
  int r=1;
  for (i=0; i<26; i++)
    r*=power(simp[i],Ai[0][i]+Ai[pi][i]+Ai[pj][i]);
  return r;
}

int main()
{
  int i, j, k;
  int b;

  scanf("%d", &N);
  for (i=L=0; i<N; i++)
  {
    scanf("%d", &A[i]);
    L+=A[i];
  }

  for (i=0; i<N; i++)
  {
    for (j=1; j<=A[i]; j++)
    {
      b=j;
      for (k=1; k<26 && b>1; k++)
	while (!(b%simp[k]))
	{
	  b/=simp[k];
	  Ai[i+1][k]++;
	}
    }
  }
  for (j=1; j<=L-1; j++)
    {
      b=j;
      for (k=1; k<26 && b>1; k++)
	while (!(b%simp[k]))
	{
	  b/=simp[k];
	  Ai[0][k]++;
	}
    }

  for (i=0; i<26; i++)
    for (j=1; j<=N; j++)
      Ai[0][i]-=Ai[j][i];

  for (i=0; i<N; i++)
    for (j=i+1; j<N; j++)
    {
      ans+=calc(i,j);
    }

  printf("%d", ans);
#ifdef _DEBUG
  printf("\n");
  getch();
#endif
  return 0;
}
