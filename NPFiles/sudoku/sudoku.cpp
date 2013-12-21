//---------------------------------------------------------------------------

#include <conio.h>
#include <stdio.h>

//---------------------------------------------------------------------------

const int N=9;
const int n=3;
int a[10][10];
bool col[10][10];                           //���� �� � ������� i ����� j
bool row[10][10];                           //���� �� � ������� i ����� j
bool sqr[10][10];                           //���� �� � �������� i ����� j

int putted=0;                               //���������� ���������� ����

inline int getsqr(int x, int y)             //������ ����� ��������
{
  return (x-1)/3+1+((y-1)/3)*3;
}

inline bool canbe(int x, int y, int k)      //����� �� �������� ����� k � a[i][j]
{
  return (!col[x][k] && !row[y][k] && !sqr[getsqr(x, y)][k]);
}

bool put(int i, int j)                      //������ ����� � a[i,j]
{
  int k;
  if (putted==N*N)                          //���� �������� ��� �� �����
    return 1;                               //���������� ���������� �� ������� ����������
  if (!a[i][j])                             //���� ����� ��� ��
  {                                         //������ ����
    for (k=1; k<=N; k++)                    //���� ����� ��������� ����� ��
      if (canbe(i, j, k))
      {
        putted++;                           //�����
        a[i][j]=k;
        col[i][ a[i][j] ]=row[j][ a[i][j] ]=sqr[ getsqr(i, j) ][ a[i][j] ]=true;
        if (put( ((i+1)<=9)?(i+1):(1) , j+((i+1)>9) ))  //������� � ���������
          return true;                                  //���� ������� �������� �� �����
        col[i][ a[i][j] ]=row[j][ a[i][j] ]=sqr[ getsqr(i, j) ][ a[i][j] ]=false;
        a[i][j]=0;                                      //������� �����
        putted--;
      }
  }
  else
    if (put( ((i+1)<=9)?(i+1):(1) , j+((i+1)>9) )) //�.�. ����� ��� ����� �� ��������� � ���������
      return true;  
  return false;
}

int main(int argc, char* argv[])
{
  int i, j, k;
  printf("NP SudokuSolver 0.1\nCopyright: Sokolov Nikolay, 2008.\n");
  printf("Enter sudoku field; if cell is free print 0:\n");
  for (i=1; i<=N; i++)              //������ �����; ���� ������ ����� �� ��� 0
    for (j=1; j<=N; j++)
    {
      scanf("%d", &a[i][j]);
      if (a[i][j])
      {
        if (col[i][ a[i][j] ] || row[j][ a[i][j] ] || sqr[ getsqr(i, j) ][ a[i][j] ])
        {
          printf("Irregular input data!\n");
          goto EXIT;
        }
        col[i][ a[i][j] ]=row[j][ a[i][j] ]=true;
        sqr[ getsqr(i, j) ][ a[i][j] ]=true;
        putted++;
      }
    }
  put(1, 1);                        //������ ���������
  printf("\n");
  if (putted==N*N)
  {
    for (i=1; i<=N; i++)            //�����
    {
      for (j=1; j<=N; j++)
      {
        printf("%d ", a[i][j]);
        if (!(j%3))
          printf(" ");
      }
      printf("\n");
      if (!(i%3))
          printf("\n");
    }
  }
  else
    printf("It's impossible!");
EXIT:
  printf("Press any key to exit...");
  getch();
  return 0;
}
//---------------------------------------------------------------------------
