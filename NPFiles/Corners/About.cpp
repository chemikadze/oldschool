//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//--------------------------------------------------------------------- 
__fastcall TAboutForm::TAboutForm(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutForm::OKButtonClick(TObject *Sender)
{
 Close();        
}
//---------------------------------------------------------------------------

