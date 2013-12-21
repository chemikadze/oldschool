//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "NewGame.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewGameForm *NewGameForm;
//---------------------------------------------------------------------------
__fastcall TNewGameForm::TNewGameForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNewGameForm::Button2Click(TObject *Sender)
{NewGame=0;
 this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TNewGameForm::Button1Click(TObject *Sender)
{NewGame=1;
 this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TNewGameForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{TmyTime Time;
 if (!NewGame) return;
 if (sscanf(Edit1->Text.c_str(),"%d:%d:%d",&Time.h,&Time.m,&Time.s))
   BTime=WTime=Time;
 else
   {ShowMessage("Неправильный формат времени!");
    return;
   }
 if (RadioButton1->Checked) hod=1;
 else hod=2;  
}
//---------------------------------------------------------------------------
