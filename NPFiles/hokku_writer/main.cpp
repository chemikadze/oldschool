//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "about.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
#define isglas(_s) ( _s=='а' || _s=='е' || _s=='ё' || _s=='и' || _s=='о' || _s=='у' || _s=='ы' || _s=='э' || _s=='ю' || _s=='я' || \
                     _s=='А' || _s=='Е' || _s=='Ё' || _s=='И' || _s=='О' || _s=='У' || _s=='Ы' || _s=='Э' || _s=='Ю' || _s=='Я')
#define islett(_s) (_s>='А' && _s<='Я' || _s>='а' && _s<='я')
int slogcount(AnsiString s)
{int slog=0;
 int i;
 AnsiString word;
 for (i=1;i<=s.Length();i++)
   {if (isglas(s[i]))
           slog++;
   }
 return slog;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Memo1Change(TObject *Sender)
{int i;
 int slog;
 AnsiString s;
 const int nado[]={5,7,5};
 const TLabel *label[]={MainForm->Label4,MainForm->Label5,MainForm->Label6};
 for (i=0;i<3;i++)
   {slog=((i<Memo1->Lines->Count)?(slogcount(Memo1->Lines->operator [](i))):(0));
    if (slog==nado[i])
      {label[i]->Font->Color=clGreen;
       label[i]->Caption="Ок";
      }
    else
      {label[i]->Font->Color=clRed;
       if (slog>nado[i])
         s.printf("Лишние %d слога(ов)",slog-nado[i]);
       else
         s.printf("Недостает %d слога(ов)",nado[i]-slog);
       label[i]->Caption=s;
      }
   }
 Memo1->Font->Color=clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N3Click(TObject *Sender)
{
 this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N2Click(TObject *Sender)
{
 Memo1->Lines->Clear();
 SaveDialog1->FileName="";
 this->Memo1Change(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
 this->Memo1Change(NULL);        
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N6Click(TObject *Sender)
{
 AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N7Click(TObject *Sender)
{
 if (SaveDialog1->FileName.Length()==0)
   {if (!SaveDialog1->Execute())
      return;
    if (SaveDialog1->FileName.Length()>4)
      {if ( AnsiCompareText(SaveDialog1->FileName.SubString(SaveDialog1->FileName.Length()-3,4),".txt") )
         SaveDialog1->FileName=SaveDialog1->FileName+".txt";
      }
    else
      {if (SaveDialog1->FileName.Length()>0)
         SaveDialog1->FileName=SaveDialog1->FileName+".txt";
       else
         return;
      }
   }
 Memo1->Lines->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N9Click(TObject *Sender)
{
 if (OpenDialog1->Execute())
   {SaveDialog1->FileName=OpenDialog1->FileName;
    Memo1->Lines->LoadFromFile(SaveDialog1->FileName);
    Memo1Change(NULL);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N10Click(TObject *Sender)
{
 SaveDialog1->FileName="";
 N7Click(NULL);
}
//---------------------------------------------------------------------------

