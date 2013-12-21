//---------------------------------------------------------------------------

#ifndef ChangeH
#define ChangeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "Main.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TChangeForm : public TForm
{
__published:	// IDE-managed Components
        TColorDialog *ColorDialog1;
        TButton *Button2;
        TButton *Button3;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TLabel *Label1;
        TEdit *Edit1;
        TButton *Button1;
        TCheckBox *CheckBox1;
        TRadioGroup *LineStyle;
        TLabel *Label2;
        TImage *Image1;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        TDrFunction* chfunction;
        __fastcall TChangeForm(TComponent* Owner);
        void SetFunction(TDrFunction* funct)
          {
           this->chfunction=funct;
           ColorDialog1->Color=chfunction->color;
           Image1->Canvas->Brush->Color=chfunction->color;
           Image1->Canvas->FillRect(Image1->ClientRect);
           Edit1->Text=chfunction->text;
           CheckBox1->Checked=chfunction->showing;
           LineStyle->ItemIndex=(int)(chfunction->linestyle);
          }
        void ChangeFunction()
          {chfunction->color=ColorDialog1->Color;
           chfunction->SetText(Edit1->Text);
           chfunction->showing=CheckBox1->Checked;
           chfunction->linestyle=(TLineStyle)LineStyle->ItemIndex;
          }
};
//---------------------------------------------------------------------------
extern PACKAGE TChangeForm *ChangeForm;
extern int changed;
//---------------------------------------------------------------------------
#endif
