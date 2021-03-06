//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "Main.h"
#include "About.h"
#include "Change.h"
#include "Options.h"
#include <vector>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "PERFGRAP"
#pragma resource "*.dfm"
TMainForm *MainForm;
TDrFunction** functions;
Graphics::TBitmap* bmp;
int fns=0;
int lastselected=0;
int M;
bool fchanged=false;
long double step;
int mouseX,mouseY;
AnsiString filename="";
TGrOptions GrOptions;
AnsiString path;

void rmfn(int n)
{
 if (!fns) return;
 if (fns==1)
   {delete functions[0];
    delete[] functions;
    fns--;
    return;
   }
 TDrFunction** pf=new TDrFunction*[fns-1];
 int i;
 for (i=0;i<n;i++)
   {pf[i]=functions[i];
   }
 delete functions[i];
 for (i=n+1;i<fns;i++)
   {pf[i-1]=functions[i];
   }
 if (functions!=NULL) delete[] functions;
 functions=pf;
 fns--;
}

void popfn()
{
 rmfn(fns-1);
}

void pushfn(TDrFunction* fn)
{TDrFunction** pf=new TDrFunction*[fns+1];
 int i;
 for (i=0;i<fns;i++)
   {pf[i]=functions[i];
   }
 pf[i]=fn;
 if (functions!=NULL) delete[] functions;
 functions=pf;
 fns++;
}

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{bmp=new Graphics::TBitmap();
 bmp->Height=Grafic->Height;
 bmp->Width=Grafic->Width;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject *Sender)
{
 MainForm->Close();
}
//---------------------------------------------------------------------------
//NEWFILE
void __fastcall TMainForm::N1Click(TObject *Sender)
{
 fchanged=false;
 filename="";
 this->SetHeader();
 ClearFns();
 Prepare();
 ShowBitmap();
 SetBuildEnabled(true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormResize(TObject *Sender)
{
 if (bmp!=NULL)
   {
    Prepare();
    ShowBitmap();
    Progress->Max=bmp->Width;
   }
}
//---------------------------------------------------------------------------
void TMainForm::RemoveFn(int n)
{if (!n) return;
 rmfn(n);
 CFn->Items->Delete(n);
}
//---------------------------------------------------------------------------
void TMainForm::ClearFns()
{while (fns>1) popfn();
 CFn->Items->Clear();
 CFn->Items->Add("����� �������");
 CFn->ItemIndex=0;
}
//---------------------------------------------------------------------------
void TMainForm::ClearImg()
{
 bmp->Canvas->Brush->Color=GrOptions.BkColor;
 bmp->Canvas->FillRect(Grafic->Canvas->ClipRect);
}
//---------------------------------------------------------------------------
void TMainForm::DrawCoords()
{int i,j;
 int m=M;
 int maxx,maxy;
 AnsiString s;
 bmp->Canvas->Pen->Color=clBlack;
 bmp->Canvas->MoveTo(0,0);
 bmp->Canvas->LineTo(bmp->Width-1,0);
 bmp->Canvas->LineTo(bmp->Width-1,bmp->Height-1);
 bmp->Canvas->LineTo(0,bmp->Height-1);
 bmp->Canvas->LineTo(0,0);
 bmp->Canvas->Pen->Color=GrOptions.OsColor;
 bmp->Canvas->MoveTo(bmp->Width/2,0);
 bmp->Canvas->LineTo(bmp->Width/2,bmp->Height);
 bmp->Canvas->MoveTo(0,bmp->Height/2);
 bmp->Canvas->LineTo(bmp->Width,bmp->Height/2);
#define line(x1,y1,x2,y2) bmp->Canvas->MoveTo(x1,y1),bmp->Canvas->LineTo(x2,y2)
#define putpixel(x,y) bmp->Canvas->Pixels[x][y]=bmp->Canvas->Pen->Color
 maxx=bmp->Width;
 maxy=bmp->Height;
 line(0,maxy/2,maxx,maxy/2);
 line(maxx/2,0,maxx/2,maxy);
 line(maxx-5,maxy/2-5,maxx,maxy/2);
 line(maxx-5,maxy/2+5,maxx,maxy/2);
 line(maxx/2-5,5,maxx/2,0);
 line(maxx/2+5,5,maxx/2,0);
 while (m<16) m*=2;
 s.printf("%d",m/M);
 for (i=1;i<bmp->Height/m/2;i++)
   {s.printf("%d",m/M*i);
    bmp->Canvas->TextOutA(maxx/2+2,maxy/2-m*i,s);
    bmp->Canvas->TextOutA(maxx/2+2,maxy/2+m*i,"-"+s);
   }
 for (i=1;i<bmp->Width/m/2;i++)
   {s.printf("%d",m/M*i);
    bmp->Canvas->TextOutA(maxx/2+i*m,maxy/2+2,s);
    bmp->Canvas->TextOutA(maxx/2-i*m,maxy/2+2,"-"+s);
   }
 bmp->Canvas->TextOutA(maxx/2+2,maxy/2+2,"0");  
 if (!GrOptions.ShowPnt) return;
 bmp->Canvas->Pen->Color=GrOptions.PntColor;
 for (i=0;i<maxx/2;i+=m)
   for (j=0;j<maxy/2;j+=m)
     {putpixel(maxx/2+i,maxy/2+j);
      putpixel(maxx/2-i,maxy/2+j);
      putpixel(maxx/2+i,maxy/2-j);
      putpixel(maxx/2-i,maxy/2-j);
     }
#undef line
#undef putpixel     
}
//---------------------------------------------------------------------------
void TMainForm::ShowBitmap()
{
// Grafic->Canvas->Lock();
 Grafic->Picture->Bitmap->Assign(bmp);
// Grafic->Canvas->Unlock();
}

void __fastcall TMainForm::BBuildClick(TObject *Sender)
{
 SetBuildEnabled(false);
 Prepare();
 functions[CFn->ItemIndex]->SetText(EFn->Text);
 MainForm->Memo1->Lines->Add("�������:");
 functions[CFn->ItemIndex]->build();
 ShowBitmap();
 SetBuildEnabled(true);
}
//---------------------------------------------------------------------------
//PLUS FUNCTION
void __fastcall TMainForm::ToolButton5Click(TObject *Sender)
{
 fchanged=true;
 if (EFn->Text!="" && (EFn->Text!=functions[CFn->ItemIndex]->text || !CFn->ItemIndex))
   {CFn->Items->Add(EFn->Text);
    pushfn(new TDrFunction(functions[CFn->ItemIndex]->text,GrOptions.GetDefColor(),functions[CFn->ItemIndex]->linestyle,functions[CFn->ItemIndex]->showing));
    functions[fns-1]->SetText(EFn->Text);
    //EFn->Text=functions[CFn->ItemIndex]->text;
    CFn->ItemIndex=fns-1;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CFnSelect(TObject *Sender)
{
 fchanged=true;
 functions[lastselected]->SetText(EFn->Text);
 if (lastselected)
   {
    CFn->Items->Delete(lastselected);
    CFn->Items->Insert(lastselected,functions[lastselected]->text);
   }
 if (CFn->ItemIndex<0)
   CFn->ItemIndex=0;
 EFn->Text=functions[CFn->ItemIndex]->text;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
 randomize();
 path=Application->ExeName.Delete(Application->ExeName.Length()-8,9);
 SetHeader();
 pushfn(new TDrFunction(clRed));
 GrOptions.LoadGrOptions();
 step=0.0001L*EStep->Value;
 M=1+EPoints->Value;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
 GrOptions.SaveGrOptions();
 while (fns>0)
   popfn();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CFnClick(TObject *Sender)
{
 lastselected=CFn->ItemIndex;
}
//---------------------------------------------------------------------------

int ldtoi(long double n)
{int N;
 if (n>INT_MAX) return (INT_MAX);
 if (n<INT_MIN) return (INT_MIN);
 return (int)n;
}

void TDrFunction::build()
{
 MainForm->Memo1->Lines->Add("\"y="+this->text+"\"");
 if (!this->showing)
   {MainForm->Memo1->Lines->Add("������ �� �������");
    return;
   }
 int lp=1,llp=1;
#define lineto(_X,_Y) bmp->Canvas->LineTo(_X,_Y)
#define moveto(_X,_Y) bmp->Canvas->MoveTo(_X,_Y)
#define circle(_X,_Y,r) bmp->Canvas->Ellipse(_X-r/2,_Y-r/2,_X+r/2,_Y+r/2)
#define putpixel(_X,_Y) bmp->Canvas->Pixels[_X][_Y]=bmp->Canvas->Pen->Color
 long double x,y;
 int lx=0,ly=0;
 int llx=0,lly=0;
 bmp->Canvas->Pen->Color=this->color;
 solver->strtopol();
 if (solver->geterr()!=E_NO)
   {MainForm->Memo1->Lines->Add(AnsiString("��������� ������: "));
    MainForm->Memo1->Lines->Add(AnsiString(solver->getruserr()));
    //MainForm->Memo1->Lines->Add("");
    return;
   }
 y=solver->solvepolx(-((long double)(bmp->Width))/M/2,step);
 moveto(0,ldtoi(-y*M+bmp->Height/2));
 for (x=-((double)(bmp->Width))/M/2;x<=((double)(bmp->Width))/M/2;x+=step)
   {y=solver->solvepolx(x,step/4);
    Application->ProcessMessages();
    lx=ldtoi(x*M+bmp->Width/2);
    ly=ldtoi(-y*M+bmp->Height/2);
    if (solver->geterr()==E_NO &&
        abs(ly-lly)<ldtoi(3./2.*bmp->Height))
      {if (lp && llp)
         {if (this->linestyle==line)
            lineto(lx,ly);
          else
            putpixel(lx,ly);
         }
       else
         if (llp)
           {if (!lp)
              circle(llx,ly,6);
            moveto(lx,ly);
           }
         else
           {//if (!lp)
            //  circle(llx,ly,6);
            moveto(lx,ly);
           }
       llp=lp;
       lp=1;
      }
    else
      {moveto(lx,ly);
       llp=lp;
       //if (abs(ly-lly)<ldtoi(3./2.*bmp->Height))
         lp=0;
      }
    MainForm->Progress->Position=ldtoi(x*M+bmp->Width/2);
    llx=lx;
    //lly=ly;
   }
 MainForm->Progress->Position=0;
 //MainForm->Memo1->Lines->Add("");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EPointsChange(TObject *Sender)
{
 M=1+abs(EPoints->Value);
 Prepare();
// functions[CFn->ItemIndex].build();
 ShowBitmap();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EStepChange(TObject *Sender)
{
 step=0.0001L*EStep->Value;
}
//---------------------------------------------------------------------------
//BUILD ALL
void __fastcall TMainForm::ToolButton8Click(TObject *Sender)
{int i;
 SetBuildEnabled(false);
 Prepare();
 functions[CFn->ItemIndex]->SetText(EFn->Text);
 for (i=0;i<fns;i++,MainForm->Memo1->Lines->Add(""))
   {MainForm->Memo1->Lines->Add("������� ("+AnsiString(i+1)+" �� "+AnsiString(fns)+"):");
    functions[i]->build();
    Application->ProcessMessages();
   }
 ShowBitmap();
 SetBuildEnabled(true);
}
//---------------------------------------------------------------------------
//MINUS FUNCTION
void __fastcall TMainForm::ToolButton6Click(TObject *Sender)
{
 fchanged=true;
 if (!CFn->ItemIndex) return;
 rmfn(CFn->ItemIndex);
 CFn->Items->Delete(CFn->ItemIndex);
 CFn->ItemIndex=fns-1;
 EFn->Text=functions[CFn->ItemIndex]->text;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GraficClick(TObject *Sender)
{
 Grafic->Hint.printf("x=%.2g, y=%.2g",((double)(mouseX-Grafic->Width/2))/M,
                                      ((double)(Grafic->Height/2-mouseY))/M);        
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::GraficMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{AnsiString sx;
 AnsiString sy;
 mouseX=X;
 mouseY=Y;
#define N 3
 if (X<N || Y<N || X+N>bmp->Width || Y+N>bmp->Height)
   {StatusBar1->Panels->operator [](1)->Text=" ";
    StatusBar1->Panels->operator [](2)->Text=" ";
    return ;
   }
 sx.printf("x=% .2g",((double)(mouseX-Grafic->Width/2))/M);
 sy.printf("y=% .2g",((double)(Grafic->Height/2-mouseY))/M);
 StatusBar1->Panels->operator [](1)->Text=sx;
 StatusBar1->Panels->operator [](2)->Text=sy;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N13Click(TObject *Sender)
{
 AboutBox=new TAboutBox(MainForm);
 AboutBox->ShowModal();
 delete AboutBox;
}
//---------------------------------------------------------------------------
void SaveGrToFile(AnsiString f)
{if (f=="") return;
 switch (MainForm->SaveDialog1->FilterIndex)
   {case 2: if (!f.Pos(".npg")) f=f+".npg";break;
    case 1: if (!f.Pos(".txt")) f=f+".txt";break;
    case 3: if (!f.Pos(".bmp"))
              {f=f+".bmp";
               bmp->SaveToFile(f);
               return;
              }
    case 4: break;
   }
 int i;
 MainForm->SetHeader(f);
 FILE* fil=fopen(f.c_str(),"w");
 fprintf(fil,"%d\n",fns-1);
 for (i=1;i<fns;i++)
   {fputs(functions[i]->text.c_str(),fil);
    fprintf(fil,"\n%d\n%d\n",functions[i]->color,(int)(functions[i]->linestyle));
   }
 fclose(fil);
 fchanged=false;
}

void OpenGrFromFile(AnsiString f)
{if (f=="")
   {MainForm->N1Click(NULL);
    return;
   }
 MainForm->SetHeader();
 char s[1024];
 int i;
 TColor clr;
 int ls;
 FILE* fil=fopen(f.c_str(),"r");
 fscanf(fil,"%d\n",&i);
 while (i-->0)
   {fgets(s,1024,fil);
    s[strlen(s)-1]='\0';
    if (fscanf(fil,"%d\n%d\n",&clr,&ls)!=2)
      {MainForm->N1Click(NULL);
       return;
      }
    pushfn(new TDrFunction(AnsiString(s),clr,(TLineStyle)ls));
    MainForm->CFn->Items->Add(AnsiString(s));
   }
 fclose(fil);
 fchanged=true;
}
//---------------------------------------------------------------------------
//SAVE FILE
void __fastcall TMainForm::ToolButton3Click(TObject *Sender)
{
 if (filename=="")
   {if (!SaveDialog1->Execute()) return;
    filename=SaveDialog1->FileName;
   }
 SaveGrToFile(filename);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N5Click(TObject *Sender)
{
 if (!SaveDialog1->Execute()) return;
 filename=SaveDialog1->FileName;
 SaveGrToFile(filename);
}
//---------------------------------------------------------------------------
//LOAD FILE
void __fastcall TMainForm::N14Click(TObject *Sender)
{
 if (!OpenDialog1->Execute()) return;
 filename=OpenDialog1->FileName;
 OpenGrFromFile(filename);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N10Click(TObject *Sender)
{
 fchanged=true;
 ChangeForm=new TChangeForm(MainForm);
 functions[CFn->ItemIndex]->SetText(this->EFn->Text);
 ChangeForm->SetFunction(functions[CFn->ItemIndex]);
 ChangeForm->ShowModal();
 this->EFn->Text=functions[CFn->ItemIndex]->text;
 MainForm->ToolButton8Click(this);
 delete ChangeForm;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N8Click(TObject *Sender)
{
 fchanged=true;
 pushfn(new TDrFunction());
 ChangeForm=new TChangeForm(MainForm);
 ChangeForm->SetFunction(functions[fns-1]);
 if (ChangeForm->ShowModal()!=mrOk)
   {popfn();
    return;
   }
 CFn->Items->Add(functions[fns-1]->text);
 EFn->Text=functions[CFn->ItemIndex]->text;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N15Click(TObject *Sender)
{
 OptionsForm=new TOptionsForm(MainForm);
 OptionsForm->ShowModal();
 if (OptionsForm->ModalResult!=mrOk) return;
 MainForm->ToolButton8Click(this);
 delete OptionsForm;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N17Click(TObject *Sender)
{
 GrOptions.SaveGrOptions();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N16Click(TObject *Sender)
{
 GrOptions.SetDefaults();
 Prepare();
 ShowBitmap();
}
//---------------------------------------------------------------------------
TColor TGrOptions::GetDefColor()
{if (RandDefColor)
   {
    int r,g,b;
    r=random(255);
    g=random(255);
    b=random(255);
    return (TColor)RGB(r,g,b);
   }
 return functions[0]->color;
}

void TGrOptions::LoadGrOptions()
{FILE* fil=fopen(AnsiString(path+"NPGpp.cfg").c_str(),"r");
 if (fil==NULL)
   {this->SetDefaults();
    return;
   }
 TColor clr;
 int ls;
 fscanf(fil,"%d %d %d %d %d",&BkColor,&OsColor,&PntColor,&ShowPnt,&RandDefColor);
 fscanf(fil,"\n%d %d %d",&clr,&ls,&(functions[0]->showing));
 functions[0]->color=clr;
 functions[0]->linestyle=(TLineStyle)ls;
 fclose(fil);
}

void TGrOptions::SaveGrOptions()
{FILE* fil=fopen(AnsiString(path+"NPGpp.cfg").c_str(),"w");
 fprintf(fil,"%d %d %d %d %d",BkColor,OsColor,PntColor,ShowPnt,RandDefColor);
 fprintf(fil,"\n%d %d %d",functions[0]->color,(int)(functions[0]->linestyle),functions[0]->showing);
 fclose(fil);
}

TDrFunction::TDrFunction(AnsiString s,TColor clr,TLineStyle ls,int show)
{text=s;
 solver=new TSolver(text.c_str());
 color=clr;
 showing=show;
 linestyle=ls;
}

TDrFunction::TDrFunction(AnsiString s,TColor clr,TLineStyle ls)
{text=s;
 solver=new TSolver(text.c_str());
 color=clr;
 showing=1;
 linestyle=ls;
}

TDrFunction::TDrFunction(AnsiString s,TColor clr,int show)
{text=s;
 solver=new TSolver(text.c_str());
 color=clr;
 showing=show;
 linestyle=line;
}

TDrFunction::TDrFunction(AnsiString s,TColor clr)
{text=s;
 solver=new TSolver(text.c_str());
 color=clr;
 showing=1;
 linestyle=line;
}

TDrFunction::TDrFunction(AnsiString s)
{text=s;
 solver=new TSolver(text.c_str());
 color=GrOptions.GetDefColor();
 showing=1;
 linestyle=line;
}

TDrFunction::TDrFunction(TColor clr)
{text="";
 solver=new TSolver();
 color=clr;
 showing=1;
 linestyle=line;
}

TDrFunction::TDrFunction()
{text="";
 solver=new TSolver();
 color=GrOptions.GetDefColor();
 showing=1;
 linestyle=line;
}
TDrFunction::~TDrFunction()
{delete solver;
}

void DefaultFunctionLoad()
{TColor clr;
 int ls;
 FILE* fil=fopen(AnsiString(path+"NPGpp.cfg").c_str(),"r");
 fscanf(fil,"%d\n%d\n%d",&clr,&ls,&(functions[0]->showing));
 functions[0]->color=clr;
 functions[0]->linestyle=(TLineStyle)ls;
 fclose(fil);
}

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{if (changed)
 switch
   (MessageBox(0,"��������� ���� ����� ���������?",
               "���������� ������...",MB_YESNOCANCEL)
   )
   {case IDYES   : this->ToolButton3Click(this);
    case IDNO    : ;break;
    case IDCANCEL: Action=caNone;
   }
}
//---------------------------------------------------------------------------
void TGrOptions::SetDefaults()
{
 BkColor=clWhite;
 OsColor=clBlack;
 PntColor=clBlack;
 functions[0]->color=clRed;
 ShowPnt=1;
 RandDefColor=0;
 return;
}


void __fastcall TMainForm::EFnChange(TObject *Sender)
{
 changed=true;        
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Label4Click(TObject *Sender)
{
  EFn->Text=functions[CFn->ItemIndex]->text;        
}
//---------------------------------------------------------------------------

