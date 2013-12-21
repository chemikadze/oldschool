//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "NewGame.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

Graphics::TBitmap* pwhite=new Graphics::TBitmap();
Graphics::TBitmap* pblack=new Graphics::TBitmap();
Graphics::TBitmap* pwhiteshb=new Graphics::TBitmap();
Graphics::TBitmap* pblackshb=new Graphics::TBitmap();
Graphics::TBitmap* pwhiteshw=new Graphics::TBitmap();
Graphics::TBitmap* pblackshw=new Graphics::TBitmap();

int sh[8][8];
int cango[8][8];
int hod;
TGridDrawState BState;
TmyTime BTime;
TmyTime WTime;
int NewGame=0;

int X=-1,Y=-1;

//---------------------------------------------------------------------------
int whowin()
{int i,j;
 int r=0;
 #define N 3
 #define M 4
 for (i=0;i<N;i++)
   for (j=0;j<M;j++)
     if (sh[i][j]!=2) goto next1;
 r=2;
next1:
 for (i=0;i<N;i++)
   for (j=0;j<M;j++)
     if (sh[N-i][M-j]!=1) goto next2;
 if (r) r=-1;
next2:
 return r;
}

#define cangoleft   (x>0 && !sh[x-1][y])
#define cangoright  (x<7 && !sh[x+1][y])
#define cangotop    (y>0 && !sh[x][y-1])
#define cangobottom (y<7 && !sh[x][y+1])

#define canjmpleft   (x>1 && sh[x-1][y] && !sh[x-2][y])
#define canjmpright  (x<6 && sh[x+1][y] && !sh[x+2][y])
#define canjmptop    (y>1 && sh[x][y-1] && !sh[x][y-2])
#define canjmpbottom (y<6 && sh[x][y+1] && !sh[x][y+2])

void gethod(int x=X,int y=Y)
{int i,j;

 if (x==X && y==Y)
  for (i=0;i<8;i++)
    for (j=0;j<8;j++)
      cango[i][j]=0;

 if (cangoleft && !cango[x][y])
   cango[x-1][y]=-1;
 else
   if (canjmpleft)
     {if (!cango[x-2][y])
        {cango[x-2][y]=1;
         gethod(x-2,y);
        }
     }
 if (cangoright && !cango[x][y])
   cango[x+1][y]=-1;
 else
   if (canjmpright)
     {if (!cango[x+2][y])
        {cango[x+2][y]=1;
         gethod(x+2,y);
        }
     }
 if (cangotop && !cango[x][y])
   cango[x][y-1]=-1;
 else
   if (canjmptop)
     {if (!cango[x][y-2])
        {cango[x][y-2]=1;
         gethod(x,y-2);
        }
     }
 if (cangobottom && !cango[x][y])
   cango[x][y+1]=-1;
 else
   if (canjmpbottom)
     {if (!cango[x][y+2])
        {cango[x][y+2]=1;
         gethod(x,y+2);
        }
     }
}
//---------------------------------------------------------------------------

int correcthod(int x,int y)
{
 return cango[x][y];
}
//---------------------------------------------------------------------------
void disptime()
{MainForm->Label5->Caption=MainForm->Label5->Caption.sprintf("%02d:%02d:%02d",BTime.h,BTime.m,BTime.s);
 MainForm->Label6->Caption=MainForm->Label6->Caption.sprintf("%02d:%02d:%02d",WTime.h,WTime.m,WTime.s);
}
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
 BTime.h=0;
 BTime.s=0;
 BTime.m=30;
 WTime=BTime;
 hod=1;
 disphod();
 pwhite->LoadFromFile("white.bmp");
 pblack->LoadFromFile("black.bmp");
 pwhiteshw->LoadFromFile("whiteshw.bmp");
 pblackshw->LoadFromFile("blackshw.bmp");
 pwhiteshb->LoadFromFile("whiteshb.bmp");
 pblackshb->LoadFromFile("blackshb.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N2Click(TObject *Sender)
{
 MainForm->Close();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::BoardDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{int i,j;

 if ((ARow%2 && ACol%2) || (!(ARow%2) && !(ACol%2)))
   if (sh[ARow][ACol])
     if (sh[ARow][ACol]==1)
       Board->Canvas->Draw(Board->CellRect(ACol,ARow).Left,
                           Board->CellRect(ACol,ARow).Top,
                           pwhiteshw);
       else
         Board->Canvas->Draw(Board->CellRect(ACol,ARow).Left,
                             Board->CellRect(ACol,ARow).Top,
                             pblackshw);
   else
     Board->Canvas->Draw(Board->CellRect(ACol,ARow).Left,
                         Board->CellRect(ACol,ARow).Top,
                         pwhite);
 else
   if (sh[ARow][ACol])
     if (sh[ARow][ACol]==1)
       Board->Canvas->Draw(Board->CellRect(ACol,ARow).Left,
                           Board->CellRect(ACol,ARow).Top,
                           pwhiteshb);
       else
         Board->Canvas->Draw(Board->CellRect(ACol,ARow).Left,
                             Board->CellRect(ACol,ARow).Top,
                             pblackshb);
   else
     Board->Canvas->Draw(Board->CellRect(ACol,ARow).Left,
                         Board->CellRect(ACol,ARow).Top,
                         pblack);
 BState=State;
 Board->Canvas->Brush->Color=clRed;
 Board->Canvas->Pen->Color=clRed-0x30;
 if (X>=0 && Y>=0)
 Board->Canvas->Ellipse(Board->CellRect(Y,X).Left+20,Board->CellRect(Y,X).Top+20,
                        Board->CellRect(Y,X).Left+30,Board->CellRect(Y,X).Top+30);
 Board->Canvas->Brush->Color=clLime;
 Board->Canvas->Pen->Color=clGreen;
 for (i=0;i<8;i++)
   for (j=0;j<8;j++)
     if (cango[i][j])
       {Board->Canvas->Ellipse(Board->CellRect(j,i).Left+22,Board->CellRect(j,i).Top+22,
                               Board->CellRect(j,i).Left+26,Board->CellRect(j,i).Top+26);
       }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{int i,j;
 for (i=0;i<8;i++)
   for (j=0;j<8;j++)
     sh[i][j]=0;
 for (i=0;i<N;i++)
   for (j=0;j<M;j++)
     {sh[i][j]=1;
      sh[7-i][7-j]=2;
     }
}
//---------------------------------------------------------------------------
void TMainForm::DrawBoard()
{int i,j;
 for (i=0;i<8;i++)
   for (j=0;j<8;j++)
     BoardDrawCell(this,i,j,Board->CellRect(i,j),BState);
}
//---------------------------------------------------------------------------
void disphod()
{if (hod==2) MainForm->LabelHod->Caption="Черные";
 else MainForm->LabelHod->Caption="Белые";
}
//---------------------------------------------------------------------------
char hodtochar()
{if (hod==2) return 'Ч';
 else return 'Б';
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BoardSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{int buf;
 int win;
 int i,j;
 AnsiString S;

 if (!hod) return;

 if (X>=0 && Y>=0 && sh[X][Y] && !sh[ARow][ACol])
   {
    if (!correcthod(ARow,ACol))
      {for (i=0;i<8;i++) for (j=0;j<8;j++) cango[i][j]=0;
       ShowMessage("Ход некорректен!");
       S.sprintf("%c: %c-%d холостой ход на %c-%d",hodtochar(),'A'+X,Y+1,'A'+ARow,ACol+1);
       Memo1->Lines->Add(S);
       if (hod==1) hod++;else hod--;
       X=Y=-1;
       
       disphod();
       DrawBoard();
       return;
      }
    buf=sh[ARow][ACol];
    sh[ARow][ACol]=sh[X][Y];
    sh[X][Y]=buf;
    S.sprintf("%c: %c-%d ход на %c-%d",hodtochar(),'A'+X,Y+1,'A'+ARow,ACol+1);
    for (i=0;i<8;i++) for (j=0;j<8;j++) cango[i][j]=0;
    Memo1->Lines->Add(S);
    X=ACol;
    Y=ARow;
    if (hod==1) hod++;
    else hod--;
    X=Y=-1;
    win=whowin();
    if (win)
     {if (win>0)
       {if (win==1)
         {S.sprintf("Победа белых: размещение в углу");
          Memo1->Lines->Add(S);
          ShowMessage("Победа белых!");
         }
      else
        {S.sprintf("Победа черных: размещение в углу");
         Memo1->Lines->Add(S);
         ShowMessage("Победа черных!");
        }
       }
      hod=0;
     }
    }
 else
   {
    if (sh[ARow][ACol]!=hod)
      {CanSelect=false;
       X=Y=-1;
       for (i=0;i<8;i++) for (j=0;j<8;j++) cango[i][j]=0;
       DrawBoard();
       return;
      }
    X=ARow;
    Y=ACol;
    gethod();
   }
 DrawBoard();
 disphod();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject *Sender)
{int buf=hod;
 hod=0;
 NewGameForm->ShowModal();
 if (!NewGame)
   {hod=buf;
    return;
   }
 MainForm->FormCreate(this);
 MainForm->Memo1->Lines->Clear();
 DrawBoard();
 disphod();
}
//---------------------------------------------------------------------------
bool dechr(TmyTime& Time)
{if (Time.h==0) return false;
 Time.h--;
 return true;
}

bool decmin(TmyTime& Time)
{if (Time.m>0) Time.m--;
 else
   {
    if (!dechr(Time)) return false;
    Time.m=59;
   }
 return true;
}

bool decsec(TmyTime& Time)
{if (Time.s>0) Time.s--;
 else
   {
    if (!decmin(Time)) return false;
    Time.s=59;
   }
 return true;  
}

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{AnsiString S;
 int win;
 if (!hod) return;
 if (hod==2)
  if (!decsec(BTime))
    {hod=0;
     for (int i=0;i<8;i++) for (int j=0;j<8;j++) cango[i][j]=0;
     X=Y=-1;
     DrawBoard();
     ShowMessage("У черных кончилось время, \nбелые выиграли!");
     S.sprintf("Победа белых: кончилось время");
     Memo1->Lines->Add(S);
    }
 if (hod==1)
  if (!decsec(WTime))
    {hod=0;
     for (int i=0;i<8;i++) for (int j=0;j<8;j++) cango[i][j]=0;
     X=Y=-1;
     DrawBoard();
     ShowMessage("У белых кончилось время, \nчерные выиграли!");
     S.sprintf("Победа черных: кончилось время");
     Memo1->Lines->Add(S);
    }
 disptime();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N4Click(TObject *Sender)
{int buf=hod;
 hod=0;
 if (SaveDialog1->Execute())
   if (SaveDialog1->FilterIndex)
     Memo1->Lines->SaveToFile(SaveDialog1->FileName+".txt");
   else
     Memo1->Lines->SaveToFile(SaveDialog1->FileName);
 hod=buf;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N6Click(TObject *Sender)
{
 AboutForm->Show();
}
//---------------------------------------------------------------------------

