//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
typedef struct
  {signed short h,m,s;
  } TmyTime;
//---------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMemo *Memo1;
        TDrawGrid *Board;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *LabelHod;
        TGroupBox *GroupBox2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TMenuItem *Gjvjom1;
        TMenuItem *N6;
        TLabel *A;
        TLabel *B;
        TLabel *C;
        TLabel *D;
        TLabel *E;
        TLabel *F;
        TLabel *G;
        TLabel *H;
        TLabel *L1;
        TLabel *L2;
        TLabel *L3;
        TLabel *L4;
        TLabel *L5;
        TLabel *L6;
        TLabel *L7;
        TLabel *L8;
        TTimer *Timer1;
        TSaveDialog *SaveDialog1;
        void __fastcall N2Click(TObject *Sender);
        void __fastcall BoardDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BoardSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        void DrawBoard();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
extern int sh[8][8];
extern int hod;
extern TGridDrawState BState;
extern TmyTime BTime;
extern TmyTime WTime;
void disphod();
extern int NewGame;
//---------------------------------------------------------------------------
#endif
