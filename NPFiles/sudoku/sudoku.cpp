//---------------------------------------------------------------------------

#include <conio.h>
#include <stdio.h>

//---------------------------------------------------------------------------

const int N=9;
const int n=3;
int a[10][10];
bool col[10][10];                           //есть ли к колонке i цифра j
bool row[10][10];                           //есть ли к столбце i цифра j
bool sqr[10][10];                           //есть ли к квадрате i цифра j

int putted=0;                               //количество написанных цифр

inline int getsqr(int x, int y)             //узнать номер квадрата
{
  return (x-1)/3+1+((y-1)/3)*3;
}

inline bool canbe(int x, int y, int k)      //можно ли написать цифру k в a[i][j]
{
  return (!col[x][k] && !row[y][k] && !sqr[getsqr(x, y)][k]);
}

bool put(int i, int j)                      //кладем фишку в a[i,j]
{
  int k;
  if (putted==N*N)                          //если положены все то выход
    return 1;                               //возвращает информацию об удачном выполнении
  if (!a[i][j])                             //если цифры нет то
  {                                         //подбор цифр
    for (k=1; k<=N; k++)                    //если можно поставить цифру то
      if (canbe(i, j, k))
      {
        putted++;                           //пишем
        a[i][j]=k;
        col[i][ a[i][j] ]=row[j][ a[i][j] ]=sqr[ getsqr(i, j) ][ a[i][j] ]=true;
        if (put( ((i+1)<=9)?(i+1):(1) , j+((i+1)>9) ))  //переход к следующей
          return true;                                  //если успешно положено то выход
        col[i][ a[i][j] ]=row[j][ a[i][j] ]=sqr[ getsqr(i, j) ][ a[i][j] ]=false;
        a[i][j]=0;                                      //убираем фишку
        putted--;
      }
  }
  else
    if (put( ((i+1)<=9)?(i+1):(1) , j+((i+1)>9) )) //т.к. цифра уже стоит то переходим к следующей
      return true;  
  return false;
}

int main(int argc, char* argv[])
{
  int i, j, k;
  printf("NP SudokuSolver 0.1\nCopyright: Sokolov Nikolay, 2008.\n");
  printf("Enter sudoku field; if cell is free print 0:\n");
  for (i=1; i<=N; i++)              //чтение чисел; если клетка пуста то там 0
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
  put(1, 1);                        //запуск алгоритма
  printf("\n");
  if (putted==N*N)
  {
    for (i=1; i<=N; i++)            //вывод
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
