/*     Учебная задачка, но очень интересная:
		   Расставить на шахматной доске восемь ферзей так, чтобы
	 они не били друг друга.
		   Известно, что существует 92 решения этой задачи.
				  Гатин Г.Н.     27.03.2010
		   В своё время это была моя первая задачка, которую я сделал
	 просто так из любопыства.
*/
//  первый вариант: самое простое решение - обыкновенный перебор.
//      перебираем все (!) позиции и для каждой позиции проверяем
//      есть ли ферзь под боем. Реализация в лобешник !
#include <vcl.h>
#include <iostream.h>
#include <fstream.h>
#pragma hdrstop

#include "queenChess.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;

ofstream B;   //   файл вывода решений

int ChessDesk[8][8];   //  собственно шахматная доска
int i,j,k, n;             //  рабочие лошадки
int j1, j2, j3, j4, j5, j6, j7, j8;   //  восемь индексов для примитивного решения
TDateTime Ts, Tf, Ti;    //   время старта задачи и время финиша, интервал работы
int p = 0;
int jt[8];   //   номера строк для автоматизации решения
AnsiString hor = "abcdefgh";   //   строка букв для привычной нотации шахматиста

//  контроль позиции   Гатин Г.Н.   27.03.2010
bool ControlPozition ();
//   проверка полей, которые пробиваются ферзём с поля i, j  Гатин Г.Н. 27.03.2010
bool ControlFields (int i, int j);
//   функция определить столбец: Гатин Г.Н.  28.03.2010
void DefineColumn (int j);

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
		 k = 0;
		 B.open("Result.txt");
		 B << "    Решения задачи о восьми ферзях: \n";
Ts = Time();
		 for (j1 = 0; j1 < 8; ++j1) {
			  ChessDesk[j1][0] = 8;
			  for (j2 = 0; j2 < 8; ++j2) {
					ChessDesk[j2][1] = 8;
					for (j3 = 0; j3 < 8; ++j3) {
						 ChessDesk[j3][2] = 8;
						 for (j4 = 0; j4 < 8; ++j4) {
							  ChessDesk[j4][3] = 8;
							  for (j5 = 0; j5 < 8; ++j5) {
								   ChessDesk[j5][4] = 8;
								   for (j6 = 0; j6 < 8; ++j6) {
										ChessDesk[j6][5] = 8;
										for (j7 = 0; j7 < 8; ++j7) {
											 ChessDesk[j7][6] = 8;
											 for (j8 = 0; j8 < 8; ++j8) {
												  ChessDesk[j8][7] = 8;
												  if (ControlPozition()) {
														   ++k;
														   B << k;
														   B << ("  a"+IntToStr(j1+1)).c_str();
														   B << ("  b"+IntToStr(j2+1)).c_str();
														   B << ("  c"+IntToStr(j3+1)).c_str();
														   B << ("  d"+IntToStr(j4+1)).c_str();
														   B << ("  e"+IntToStr(j5+1)).c_str();
														   B << ("  f"+IntToStr(j6+1)).c_str();
														   B << ("  g"+IntToStr(j7+1)).c_str();
														   B << ("  h"+IntToStr(j8+1)+"\n").c_str();
													  }
												  ChessDesk[j8][7] = 0;
											   }
											 ChessDesk[j7][6] = 0;
										  }
										ChessDesk[j6][5] = 0;
									 }
								   ChessDesk[j5][4] = 0;
								}
							  ChessDesk[j4][3] = 0;
						   }
						 ChessDesk[j3][2] = 0;
					  }
					ChessDesk[j2][1] = 0;
				}
			  ChessDesk[j1][0] = 0;
		   }
Tf = Time();
		 B << " время старта ";
		 B << (DateTimeToStr(Ts)+"\n").c_str();
		 B << " время финиша ";
		 B << (DateTimeToStr(Tf)+"\n").c_str();
		 Ti = Tf - Ts;
		 B << " интервал работы : ";
		 B << (DateTimeToStr(Ti)+"\n\n\n").c_str();

//   вторая реализация: просто предыдущий вид некрасив! Он зависит от числа 8
//          Используем алгоритм пересчёта одномерного индекса в восьмимерный
//    где размер 8*8*8*8*8*8*8*8
		 for (i = 0; i < 8; ++i) jt[i] = 0;
		 n = 0;
Ts = Time();
		 for (i = 0; ; ++i) {
			  j = i; k = 7;
			  while ((j > 0) & (k >= 0)) {
					  jt[k] = j % 8;
					  j /= 8;
					  --k;
				 }
			  if (j > 0) ++p;

			  for (j = 0; j < 8; ++j)
					ChessDesk[jt[j]][j] = 8;
					if (ControlPozition()) {
						   ++n;
						   B << n;
						   for (j = 0; j < 8; ++j) {
								B << "  ";
								B << hor[j+1];
								B << jt[j]+1;
							 }
						   B << "\n";
					   }
			  for (j = 0; j < 8; ++j)
					ChessDesk[jt[j]][j] = 0;
			  if (p > 0) break;
		  }
Tf = Time();
		 B << " время старта ";
		 B << (DateTimeToStr(Ts)+"\n").c_str();
		 B << " время финиша ";
		 B << (DateTimeToStr(Tf)+"\n").c_str();
		 Ti = Tf - Ts;
		 B << " интервал работы : ";
		 B << (DateTimeToStr(Ti)+"\n\n\n").c_str();

//   Наконец : третья реализация с использованием рекурсивных функций
//     в C все функции рекурсивны.
//   Фактически, это первый вариант, но только сделан так, что не зависит от
//      числа измерений. Всё дело в рекурсивности. Первая реализация  демонстрирует
//   алгоритм.

		 for (i = 0; i < 8; ++i) jt[i] = 0;
		 k = 0;
Ts = Time();
		 DefineColumn(0);
Tf = Time();
		 B << " время старта ";
		 B << (DateTimeToStr(Ts)+"\n").c_str();
		 B << " время финиша ";
		 B << (DateTimeToStr(Tf)+"\n").c_str();
		 Ti = Tf - Ts;
		 B << " интервал работы : ";
		 B << (DateTimeToStr(Ti)+"\n\n\n").c_str();

		 MessageDlg (" Расчёт закончен!",
			   mtInformation, TMsgDlgButtons() << mbOK, NULL);

		 Application -> Terminate();
}

//  проверка позиции. Ни один феррзь не должен быть под боем  Гатин Г.Н.  27.03.2010
bool ControlPozition ()
{
int i, j;
		 for (i = 0; i < 8; ++i)
			  for (j = 0; j < 8; ++j) {
				   if (ChessDesk[i][j] != 8) continue;
				   if (!ControlFields(i, j)) return false;
				}
		 return true;
}


//   проверка полей, которые пробиваются ферзём с поля i, j  Гатин Г.Н. 27.03.2010
//      возвращает true если под бой не попало ферзя, иначе возвращает false
bool ControlFields (int i, int j)
{
int n, m;
//    проверка не попали ли мы на ферзя                                     <<
//   по горизонтали
		 for (n = 0; n < 8; ++n)
				 if (n != j)
						 if (ChessDesk[i][n] == 8) return false;
//   по вертикали
		 for (n = 0; n < 8; ++n)
				 if (n != i)
						 if (ChessDesk[n][j] == 8) return false;
//   по диагонали наверх влево
		 n = i; m = j;
		 while ((n < 7) & (m > 0)) {
				  ++n; --m;
				  if (ChessDesk[n][m] == 8) return false;
		   }
//   по диагонали наверх вправо
		 n = i; m = j;
		 while ((n < 7) & (m < 7)) {
				  ++n; ++m;
				  if (ChessDesk[n][m] == 8) return false;
		   }
//   по диагонали вниз вправо
		 n = i; m = j;
		 while ((n > 0) & (m < 7)) {
				  --n; ++m;
				  if (ChessDesk[n][m] == 8) return false;
		   }
//   по диагонали вниз влево
		 n = i; m = j;
		 while ((n > 0) & (m > 0)) {
				  --n; --m;
				  if (ChessDesk[n][m] == 8) return false;
		   }
		 return true;
}

//   функция определить столбец: Гатин Г.Н.  28.03.2010
void DefineColumn (int j)
{
int i, n;

		 for (i = 0; i < 8; ++i) {
				  ChessDesk[i][j] = 8;
				  jt[j] = i;
				  if (j < 7)
							  DefineColumn(j+1);   //  вот он вызов рекурсивной функции
					  else
							  if (ControlPozition()) {
									   ++k;
									   B << k;
									   for (n = 0; n < 8; ++n) {
											   B << "  ";
											   B << hor[n+1];
											   B << jt[n]+1;
										  }
									   B << "\n";
									}
				  ChessDesk[i][j] = 0;
		   }
}

