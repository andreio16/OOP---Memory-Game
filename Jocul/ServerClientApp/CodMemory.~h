//---------------------------------------------------------------------------

#ifndef CodMemoryH
#define CodMemoryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
#include "Unit2.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *GameBoard;
        TImage *Image1;
        TImage *Image2;
        TTimer *Timer1;
        TButton *btn1;
        TLabel *Label1;
        TLabel *Label2;
        TServerSocket *ServerSocket1;
        TClientSocket *ClientSocket1;
        TButton *btn2;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall btn1Click(TObject *Sender);
        void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall btn2Click(TObject *Sender);
        void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
private:	// User declarations
public:
        // User declarations
        void __fastcall funcClick(TObject *Sender);
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

//---------------------------------------------------------------------------
#endif
