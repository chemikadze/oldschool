//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop

#define chtoint(X) ( (X>='0' && X<='9') ? (X-'0') : (X-'A'+10) )

//---------------------------------------------------------------------------

const bool hexbit[16][4]=
{
  {0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,1},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1},
  {1,0,1,0},
  {1,0,1,1},
  {1,1,0,0},
  {1,1,0,1},
  {1,1,1,0},
  {1,1,1,1}
};

bool A[4000][4000];
bool B[4000][4000];
bool C[4000][4000];

int N;

#pragma argsused
int main(int argc, char* argv[])
{
  char s[1000];
  int i,j,k;
  int slen;
  bool res;

  #ifndef _DEBUG
  freopen("matrix.in","r",stdin);
  freopen("matrix.out","w",stdout);
  #endif

  scanf("%d",&N);
  slen=N/4+( N%4 ? 1 : 0 );
  for (i=0; i<N; i++)
  {
    scanf("%s",&s);
    for (j=0; j<slen; j++)
      for (k=0; k<4 && k+j*4<N; k++)
        A[i][k+j*4]=hexbit[ chtoint(s[j]) ][k];
  }
  for (i=0; i<N; i++)
  {
    scanf("%s",&s);
    for (j=0; j<slen; j++)
      for (k=0; k<4 && k+j*4<N; k++)
        B[i][k+j*4]=hexbit[ chtoint(s[j]) ][k];
  }
  for (i=0; i<N; i++)
  {
    scanf("%s",&s);
    for (j=0; j<slen; j++)
      for (k=0; k<4 && k+j*4<N; k++)
        C[i][k+j*4]=hexbit[ chtoint(s[j]) ][k];
  }

  for (i=0;i<N;i++)
    for (j=0;j<N;j++)
    {
      res=false;
      for (k=0;k<N;k++)
        res^=A[i][k]&&B[k][j];
      if (res!=C[i][j])
      {
        printf("NO");
        #ifdef _DEBUG
        scanf("%*s");
        #endif
        return 0;
      }
    }

  printf("YES");
  #ifdef _DEBUG
  scanf("%*s");
  #endif

  return 0;
}
//---------------------------------------------------------------------------
