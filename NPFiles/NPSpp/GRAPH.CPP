#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include "NPS.h"

#define M 25.L
#define P 100.L
#define GRAPH

int gd=VGA,gm=VGAHI,err,color,grcnt=0;
long double x,y,lx,ly,step=(1.L/M/P);
int maxx=5,maxy=5;
int lp=1,llp=1;
char s[80];

int ldtoi(long double n)
{int N;
 if (n>INT_MAX) return (INT_MAX);
 if (n<INT_MIN) return (INT_MIN);
 return (int)n;
}

void fresh()
{int i,j;
 grcnt=0;
 clrscr();
 cleardevice();
 setcolor(WHITE);
 maxx=getmaxx();
 maxy=getmaxy();
 line(0,maxy/2,maxx,maxy/2);
 line(maxx/2,0,maxx/2,maxy);
 line(maxx-5,maxy/2-5,maxx,maxy/2);
 line(maxx-5,maxy/2+5,maxx,maxy/2);
 line(maxx/2-5,5,maxx/2,0);
 line(maxx/2+5,5,maxx/2,0);
 for (i=0;i<maxx/2;i+=M)
   for (j=0;j<maxy/2;j+=M)
     {putpixel(maxx/2+i,maxy/2+j,WHITE);
      putpixel(maxx/2-i,maxy/2+j,WHITE);
      putpixel(maxx/2+i,maxy/2-j,WHITE);
      putpixel(maxx/2-i,maxy/2-j,WHITE);
     }
 setcolor(color=GREEN);
}

int inc(int& c)
{c++;
 if (c>14) c=1;
 return c;
}

int main()
{
//step=0.05L;
 TSolver solver;
 int clr=1;
#ifdef GRAPH
 initgraph(&gd,&gm,"");
 err=graphresult();
 if (err!=grOk)
   {printf("Graphics error code %d",err);
    return 0;
   }
 fresh();
#endif
 do
 {
  printf("Vvedite formulu:\ny=");
  gets(s);
  if (!strcmp(s,"exit"))
    {
     #ifdef GRAPH
     closegraph();
     #endif
     solver.~TSolver();
     return 0;
    }
#ifdef GRAPH
  if (!strcmp(s,"clear")) {clr=1;fresh();continue;}
  if (!strcmp(s,"clrscr")||!strcmp(s,"cls")) {fresh();continue;}
  if (!strcmp(s,"noclear")) {clr=0;continue;}
  if (clr) fresh();
  else {setcolor(color);inc(color);}
  if (grcnt>=10) fresh();
  grcnt++;
#endif
  lp=llp=1;
  solver.sets(s);
  solver.strtopol();
  if (solver.geterr()!=E_NO) continue;
  y=solver.solvepolx(-maxx/M/2,step);
#ifdef GRAPH
  moveto((-maxx/M/2)*M+maxx/2,ldtoi(-y*M+maxy/2));
#endif
  for (x=-maxx/M/2;x<=maxx/M/2;x+=step)
    {y=solver.solvepolx(x,step/2);
#ifdef GRAPH
     if (solver.geterr()==E_NO)
       {lx=ldtoi(x*M+maxx/2);
	ly=ldtoi(-y*M+maxy/2);
	if (lp && llp) lineto(lx,ly);
	else
	  if (llp) circle(lx,ly,3);
	  else putpixel(lx,ly,color);
       }
     else
       {if (!lp) moveto(ldtoi(x*M+maxx/2),ldtoi(-y*M+maxy/2));
	else circle(lx,ly,3);
       }
     llp=lp;
     lp=(solver.geterr()==E_NO);
#endif
    }
 }
 while (1);
}