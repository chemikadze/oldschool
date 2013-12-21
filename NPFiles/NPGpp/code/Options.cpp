//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Options.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOptionsForm *OptionsForm;
TGrOptions pGrOptions;
//---------------------------------------------------------------------------
__fastcall TOptionsForm::TOptionsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::Button1Click(TObject *Sender)
{
 GrOptions=pGrOptions;
 GrOptions.ShowPnt=CheckBox1->Checked;
 GrOptions.RandDefColor=CheckBox2->Checked;
 functions[0]->showing=CheckBox3->Checked;
 functions[0]->linestyle=(TLineStyle)(LineStyle->ItemIndex);
 this->ModalResult=mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::Button2Click(TObject *Sender)
{
 this->ModalResult=mrNo;
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::FormShow(TObject *Sender)
{pGrOptions=GrOptions;
 CheckBox1->Checked=GrOptions.ShowPnt;
 CheckBox2->Checked=GrOptions.RandDefColor;
 CheckBox3->Checked=functions[0]->showing;
 LineStyle->ItemIndex=functions[0]->linestyle;
 Image1->Canvas->Brush->Color=functions[0]->color;
 Image1->Canvas->FillRect(Image1->ClientRect);
 Image2->Canvas->Brush->Color=pGrOptions.BkColor;
 Image2->Canvas->FillRect(Image2->ClientRect);
 Image3->Canvas->Brush->Color=pGrOptions.PntColor;
 Image3->Canvas->FillRect(Image3->ClientRect);
 Image4->Canvas->Brush->Color=pGrOptions.OsColor;
 Image4->Canvas->FillRect(Image4->ClientRect);
 this->ModalResult=mrNone;
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::Button3Click(TObject *Sender)
{
 ColorDialog1->Color=pGrOptions.BkColor;
 ColorDialog1->Execute();
 pGrOptions.BkColor=ColorDialog1->Color;
 Image2->Canvas->Brush->Color=ColorDialog1->Color;
 Image2->Canvas->FillRect(Image2->ClientRect);
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::Button4Click(TObject *Sender)
{
 ColorDialog1->Color=pGrOptions.OsColor;
 ColorDialog1->Execute();
 pGrOptions.OsColor=ColorDialog1->Color;
 Image4->Canvas->Brush->Color=ColorDialog1->Color;
 Image4->Canvas->FillRect(Image4->ClientRect);
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::Button5Click(TObject *Sender)
{
 ColorDialog1->Color=pGrOptions.PntColor;
 ColorDialog1->Execute();
 pGrOptions.PntColor=ColorDialog1->Color;
 Image3->Canvas->Brush->Color=ColorDialog1->Color;
 Image3->Canvas->FillRect(Image3->ClientRect);
}
//---------------------------------------------------------------------------


void __fastcall TOptionsForm::Button7Click(TObject *Sender)
{
 ColorDialog1->Color=functions[0]->color;
 ColorDialog1->Execute();
 functions[0]->color=ColorDialog1->Color;
 Image1->Canvas->Brush->Color=ColorDialog1->Color;
 Image1->Canvas->FillRect(Image1->ClientRect);
}
//---------------------------------------------------------------------------



