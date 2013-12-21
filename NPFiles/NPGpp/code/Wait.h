//---------------------------------------------------------------------------

#ifndef WaitH
#define WaitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TWaitForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
private:	// User declarations
public:		// User declarations
        __fastcall TWaitForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWaitForm *WaitForm;
//---------------------------------------------------------------------------
#endif
