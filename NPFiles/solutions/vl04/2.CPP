#include <stdio.h>
#include <conio.h>
#include <graphics.h>


#define corrX(X) ((X)>=x1 && (X)<=x2)
#define corrY(Y) ((Y)>=y1 && (Y)<=y2)

int x1,y1;
int x2,y2;

int lx,ly;
int rx,ry;

void drbar(int x1,int y1,int x2,int y2)
{
  line(x1,y1,x1,y2);
  line(x1,y1,x2,y1);
  line(x2,y2,x1,y2);
  line(x2,y2,x2,y1);
}

int main()
{
  int gd=DETECT,gm;

  printf("Enter x1,y1: ");
  scanf("%d %d",&x1,&y1);
  printf("Enter x2,y2: ");
  scanf("%d %d",&x2,&y2);

  lx=x1;

  if ( !corrY( ly=(480*lx/640) ) )
  {
    lx=640*y1/480;
    ly=y1;
    if (!corrX(lx))
    {
      lx=800;
      ly=800;
    }

  }
  rx=x2;
  if ( !corrY( 480*rx/640 ) )
  {
    rx=640*y2/480;
    ry=y2;
    if (!corrX(rx))
    {
      rx=800;
      ry=800;
    }

  }

  initgraph(&gd,&gm,"C:\\DOS\\BC\\BGI\\");
  line(0,0,lx,480-ly);
  line(rx,480-ry,640,480);

  drbar(x1,y1,x2,y2);
  getch();
  closegraph();
}