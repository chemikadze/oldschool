//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Change.h"
//#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChangeForm *ChangeForm;
int changed;
//---------------------------------------------------------------------------
__fastcall TChangeForm::TChangeForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChangeForm::Button2Click(TObject *Sender)
{
 ChangeFunction();
}
//---------------------------------------------------------------------------
void __fastcall TChangeForm::Button1Click(TObject *Sender)
{
 ColorDialog1->Execute();
 Image1->Canvas->Brush->Color=ColorDialog1->Color;
 Image1->Canvas->FillRect(Image1->ClientRect);
}
//---------------------------------------------------------------------------

