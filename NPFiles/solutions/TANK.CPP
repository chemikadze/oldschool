#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

#define us unsigned

#define sqr(_X_) ((_X_)*(_X_))

//--------------------------------------------------------------------------
//                       constants

const int g=1;

      int groundY;

const int bodyRX=40;
const int bodyRY=20;

const int towerRX=20;
const int towerRY=10;

const int towerH=bodyRY*2;

const int LTankPos=bodyRX;
      int RTankPos;

const int gunL=25;

const int tankStep=5;
const float gunStep=0.1;

const int LTankColor=BLUE;
const int RTankColor=RED;

const int ammoV=50;

const int ammoR=2;

const char BGIPath[]="C:\\DOS\\BC\\BGI\\";

//--------------------------------------------------------------------------
//                       classes


class TGraphObj
{
  public:
  int posx;
  virtual void draw()
  {
  }

  TGraphObj()
  {
  }
};

class TTank : public TGraphObj
{
  public:
  int hp;
  int ammo;
  float angle;

  void move(int dx)
  {
    posx+=dx;
    if (posx<0 || posx>getmaxx())
      posx-=dx;
  }

  void moveGun(float da)
  {
    angle+=da;
    if ( angle>M_PI/4 && angle<M_PI-M_PI/4 ||
	 angle>M_PI+M_PI/6 || angle<-M_PI/6 )
      angle-=da;
  }

  TTank()
  {
    hp=100;
    ammo=100;
  };
};

class TRTank : public TTank
{
  public:

  virtual void draw();
  void shoot();

  TRTank()
  {
    posx=RTankPos;
    angle=M_PI;
  }
};

class TLTank : public TTank
{
  public:

  virtual void draw();
  void shoot();

  TLTank()
  {
    posx=LTankPos;
    angle=0;
  }
};

class TAmmo : public TGraphObj
{
  public:
  int posy;
  int t;

  float angle;
  int X0;
  int Y0;

  void calcPos()
  {
    posx=ammoV*cos(angle)*this->t+X0;
    posy=Y0+ammoV*sin(angle)*this->t+g*sqr(t)/2;
  }

  TAmmo()
  {
  };
};

class TRAmmo : public TAmmo
{
  public:
  virtual void draw();

  TRAmmo(int x, int y, float na)
  {
    posx=X0=x;
    posy=Y0=y;
    angle=na;
    t=0;
  }
};

class TLAmmo : public TAmmo
{
  public:
  virtual void draw();

  TLAmmo(int x, int y, float na)
  {
    posx=X0=x;
    posy=Y0=y;
    angle=na;
    t=0;
  }
};

//--------------------------------------------------------------------------
//                        classes' functions

void TRTank::draw()
{
  setfillstyle(1,RTankColor);
  fillellipse(this->posx, groundY-bodyRY, bodyRX, bodyRY);
  fillellipse(this->posx, groundY-bodyRY*2, towerRX, towerRY);
  line   (this->posx-towerRX, groundY-bodyRY*2,
	  this->posx-towerRX+gunL*cos(this->angle),
	  groundY-bodyRY*2+gunL*sin(this->angle));

}


void TLTank::draw()
{
  setfillstyle(1,LTankColor);
  fillellipse(this->posx, groundY-bodyRY, bodyRX, bodyRY);
  fillellipse(this->posx, groundY-bodyRY*2, towerRX, towerRY);
  line   (this->posx+towerRX, groundY-bodyRY*2,
	  this->posx+towerRX+gunL*cos(this->angle),
	  groundY-bodyRY*2+gunL*sin(this->angle));
}

void TLTank::shoot()
{
}

void TRTank::shoot()
{
}

void TRAmmo::draw()
{
  setfillstyle(1,RTankColor);
  fillellipse(posx, posy, ammoR, ammoR);
}

void TLAmmo::draw()
{
  setfillstyle(1,LTankColor);
  fillellipse(posx, posy, ammoR, ammoR);
}

//--------------------------------------------------------------------------
//                         objects and values

TLTank* LTank;
TRTank* RTank;

TRAmmo* RAmmo;
TLAmmo* LAmmo;

//--------------------------------------------------------------------------
//                         other functions

int initGraph()
{
  int gd=DETECT,gm;
  initgraph(&gd, &gm, BGIPath);
  groundY=getmaxy()-40;
  RTankPos=getmaxx()-bodyRX;
  return 0;
}

void closeGraph()
{
  closegraph();
}

void drawAll()
{
  cleardevice();
  RTank->draw();
  LTank->draw();
}

//--------------------------------------------------------------------------
//                         main function
int main()
{
  char c;

  initGraph();

  LTank=new TLTank;
  RTank=new TRTank;

  drawAll();

  while ((c=getch())!=27)
  {
    switch (c)
    {
      case 77  : RTank->move(tankStep); break;
      case 75  : RTank->move(-tankStep);break;
      case 72  : RTank->moveGun(-gunStep);break;
      case 80  : RTank->moveGun(+gunStep);break;
      case '0' :
      {
	RAmmo=new TRAmmo(RTank->posx-towerRX+(int)(gunL*cos(RTank->angle)),
			 groundY-bodyRY*2+(int)(gunL*sin(RTank->angle)),
			 RTank->angle);
	while (RAmmo->posx<getmaxx() && RAmmo->posy<getmaxy())
	{
	  RAmmo->calcPos();
	  drawAll();
	  RAmmo->draw();
	  RAmmo->t++;
	  delay(25);
	}
	delete RAmmo;
      }
      break;

      case 'a' : LTank->move(-tankStep);break;
      case 'd' : LTank->move(tankStep);break;
      case 'w' : LTank->moveGun(-gunStep);break;
      case 's' : LTank->moveGun(+gunStep);break;

      case ' ' :
      {
	LAmmo=new TLAmmo(LTank->posx+towerRX+(int)(gunL*cos(LTank->angle)),
			 groundY-bodyRY*2+(int)(gunL*sin(LTank->angle)),
			 LTank->angle);
	while (LAmmo->posx<getmaxx() && LAmmo->posy<getmaxy())
	{
	  LAmmo->calcPos();
	  drawAll();
	  LAmmo->draw();
	  LAmmo->t++;
	  delay(25);
	}
	delete LAmmo;
      }
      break;
    }

    drawAll();
  }

  delete RTank;
  delete LTank;

  closeGraph();

  return 0;
}