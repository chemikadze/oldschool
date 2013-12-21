//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include "CSPIN.h"
#include <ExtCtrls.hpp>

#include "NPS.h"
#include <ImgList.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
extern Graphics::TBitmap* bmp;
extern AnsiString filename;
extern AnsiString path;
//---------------------------------------------------------------------------
typedef enum {point,line} TLineStyle;

class TDrFunction
{public:
   TSolver* solver;
   AnsiString text;
   TColor color;
   TLineStyle linestyle;
   int showing;
   void build();
   void SetText(AnsiString s)
     {text=s;
      solver->sets(s.c_str());
      return;
     }
   TDrFunction(AnsiString s,TColor clr,TLineStyle ls,int show);
   TDrFunction(AnsiString s,TColor clr,TLineStyle ls);
   TDrFunction(AnsiString s,TColor clr,int show);
   TDrFunction(AnsiString s,TColor clr);
   TDrFunction(AnsiString s);
   TDrFunction(TColor clr);
   TDrFunction();
   ~TDrFunction();
};
//---------------------------------------------------------------------------
class TGrOptions
{ public:
    TColor BkColor;
    TColor OsColor;
    TColor PntColor;
    int ShowPnt;
    int RandDefColor;
    TColor GetDefColor();
    void SetDefaults();
    void LoadGrOptions();
    void SaveGrOptions();
};
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Afqk1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *N12;
        TMenuItem *N13;
        TEdit *EFn;
        TCSpinEdit *EPoints;
        TButton *BBuild;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TImageList *ImageList1;
        TMenuItem *N14;
        TCSpinEdit *EStep;
        TMenuItem *Cthdbc1;
        TMenuItem *N15;
        TImage *Grafic;
        TProgressBar *Progress;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TMemo *Memo1;
        TMenuItem *N16;
        TMenuItem *N17;
        TMenuItem *N18;
        TStatusBar *StatusBar1;
        TCoolBar *CoolBar1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton8;
        TComboBox *CFn;
        TToolButton *ToolButton4;
        TToolButton *ToolButton7;
        TToolButton *ToolButton9;
        TLabel *Label4;
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall BBuildClick(TObject *Sender);
        void __fastcall ToolButton5Click(TObject *Sender);
        void __fastcall CFnSelect(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall CFnClick(TObject *Sender);
        void __fastcall EPointsChange(TObject *Sender);
        void __fastcall EStepChange(TObject *Sender);
        void __fastcall ToolButton8Click(TObject *Sender);
        void __fastcall ToolButton6Click(TObject *Sender);
        void __fastcall GraficClick(TObject *Sender);
        void __fastcall GraficMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall N13Click(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall EFnChange(TObject *Sender);
        void __fastcall Label4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
      //  void
        void RemoveFn(int n);
        void ClearFns();
        void ClearImg();
        void DrawCoords();
        void ShowBitmap();
        void Prepare()
          {
           bmp->Height=Grafic->Height;
           bmp->Width=Grafic->Width;
           Memo1->Lines->Clear();
           ClearImg();
           DrawCoords();
           //ShowBitmap();
          }
        void SetHeader(AnsiString fn=filename)
          {if (fn=="")
             this->Caption="NP Graph++";
           else
             this->Caption=fn+" - NP Graph++";
          }
        void SetBuildEnabled(bool enabled)
          {
           /*
           #include "Wait.h"
           if (enabled) WaitForm->Show();else WaitForm->Close();
           */
           ToolButton5->Enabled=enabled;
           ToolButton6->Enabled=enabled;
           ToolButton8->Enabled=enabled;
           CFn->Enabled=enabled;
           BBuild->Enabled=enabled;
           EStep->Enabled=enabled;
           EPoints->Enabled=enabled;
          }
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
extern TGrOptions GrOptions;
extern void DefaultFunctionLoad();
extern void DefaultFunctionSave();
extern bool fchanged;
extern TDrFunction** functions;
//---------------------------------------------------------------------------
#endif
