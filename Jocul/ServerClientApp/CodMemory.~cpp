//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CodMemory.h"
#include "MClasses.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//variabile globale
TForm1 *Form1;
JOC *a = new JOC();

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        GameBoard->Top=48;
        GameBoard->Left=16;
        Form1->Height=627;
        Form1->Width=1225;
        Form1->Top=98;
        Form1->Left=187;


        ServerSocket1->Close();
       // ServerSocket1->Port = 2002;


        ClientSocket1->Close();
       // ClientSocket1->Address = "127.0.0.1";
       // ClientSocket1->Port = 2002;






         //       a->ShowCards();
         //       a->RandomCards();




                              









}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
       /* a->HideCards();
        Form1->Timer1->Enabled=false;

       //------- game logic -------\\

       for(int i=0;i<32;i++)
        {
            a->cardsHide[i]->OnClick= funcClick;

        }

           */
    












}
//------------------------------------------------------------------------------------------------------
void __fastcall TForm1::btn1Click(TObject *Sender)
{

        a->ShowCards();
        a->RandomCards();
        Form1->Timer1->Interval=8000;
        Form1->Timer1->Enabled=true;
        a->BoardColor();

        a->player1->SetScore(0);
        a->player2->SetScore(0);
        Form1->Label2->Caption = "Score player 1: " + IntToStr(a->player1->GetScore());
        Form1->Label1->Caption = "Score player 2: " + IntToStr(a->player2->GetScore());



}
//-----------------------------------------------------------------------------------------------------
 void __fastcall TForm1::funcClick(TObject *Sender)
 {
        a->cardsSelected++;


        int cardfound = -1;
        for(int i=0;i<32;i++)
        {


               // a->cardsHide[i] = dynamic_cast<TImage *>(Sender);
               // if(a->cardsHide[i])
               if(a->cardsHide[i] == Sender)
                {
                        a->cards[i]->Visible=true;
                        a->cardsHide[i]->Visible=false;
                        cardfound=i;

                        if(Form1->ServerSocket1->Active)
                        Form1->ServerSocket1->Socket->Connections[0]->SendText("firstID: " + IntToStr(cardfound));
                        if(Form1->ClientSocket1->Active)
                        Form1->ClientSocket1->Socket->SendText("firstID: " + IntToStr(cardfound));


                }
         }
        // ShowMessage(cardfound);



                        if(a->cardsSelected == 1)
                        {
                        a->first = a->cards[cardfound]->Tag;
                        a->firstID = cardfound;
                        //ShowMessage(first);



                        }else if(a->cardsSelected == 2)
                        {
                                a->second= a->cards[cardfound]->Tag;
                                a->secondID = cardfound;
                               //ShowMessage(second);
                                a->cardsSelected=0;
                        ShowMessagePos("Continui?",1065+Form1->Left,400+Form1->Top);

                        if(a->first == a->second)
                        {
                                if(Form1->ServerSocket1->Active)
                                { a->player1->SetScore(a->player1->GetScore()+1);
                                      //  Form1->ServerSocket1->Socket->Connections[0]->SendText("Score: " + a->player1->GetScore());
                                       }

                                if(Form1->ClientSocket1->Active)
                                {a->player2->SetScore(a->player2->GetScore()+1);
                                      //  Form1->ClientSocket1->Socket->SendText("Score: " + a->player2->GetScore());
                                      }



                                a->cards[a->firstID]->Enabled=false;
                                a->cardsHide[a->firstID]->Enabled=false;
                                a->cards[a->secondID]->Enabled=false;
                                a->cardsHide[a->secondID]->Enabled=false;
                                a->numOfPairsFlipped++;
                                a->WhoWon();
                                }else{
                                        a->cards[a->firstID]->Visible=false;
                                        a->cardsHide[a->firstID]->Visible=true;
                                        a->cards[a->secondID]->Visible=false;
                                        a->cardsHide[a->secondID]->Visible=true;

                                         if(Form1->ServerSocket1->Active)
                                         Form1->ServerSocket1->Socket->Connections[0]->SendText("ID: " + IntToStr(a->firstID)  +" "+ IntToStr(a->secondID));
                                         if(Form1->ClientSocket1->Active)
                                         Form1->ClientSocket1->Socket->SendText("ID: " + IntToStr(a->firstID)  +" "+  IntToStr(a->secondID));

                                }
                           a->playersTurn++;
                           Form1->Label2->Caption = "Score player 1: " + IntToStr(a->player1->GetScore());
                           Form1->Label1->Caption = "Score player 2: " + IntToStr(a->player2->GetScore());
                         }








 }
//-----------------------------------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
         
         a->ShowCards();
         Form1->Timer1;
         

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        a->ShowCards();
        a->RandomCards();
        Form1->Timer1;
        a->HideCards();



}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn2Click(TObject *Sender)
{
        net->ShowModal();
        if(net->ShowModal() == mrOk)
        {
                ServerSocket1->Open();
                btn2->Hide();
        }
        else if(net->ShowModal() == mrAll)
        {
                ClientSocket1->Open();
                btn2->Hide();
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
        //ShowMessage("transmit");
        String rec;
        int k1 = -1, k2 = -2;
        rec = Socket->ReceiveText();
        for(int i=0; i<32; i++)
        {
                for(int j=0; j<32; j++)
                {
                        if(AnsiSameStr(rec, "swap: " + IntToStr(i) + " " + IntToStr(j))) // recunoastere stringuri
                        {
                                k1 = i;
                                k2 = j;
                        }
                }

        }

        
               if(k1!=-1 && k2!=-2)
               {
                Form1->Image1->Picture = a->cards[k1]->Picture;
                a->cards[k1]->Picture = a->cards[k2]->Picture;
                a->cards[k2]->Picture = Form1->Image1->Picture;

                Form1->Image1->Tag = a->cards[k1]->Tag;
                a->cards[k1]->Tag = a->cards[k2]->Tag;
                a->cards[k2]->Tag= Form1->Image1->Tag;
                Form1->Image1->Visible=false;
                }

                if(AnsiSameStr(rec, "hide: "))
                {
                 a->HideCards();
                }

                for(int i=0 ;i<32;i++)
                {
                        if(AnsiSameStr(rec, "firstID: "+IntToStr(i)))
                        {
                                a->cardsHide[i]->Visible=false;
                        }
                }

                 for(int i=0 ;i<32;i++){
                        for(int j=0;j<32;j++)
                        {
                        if(AnsiSameStr(rec, "ID: "+IntToStr(i)+ " " + IntToStr(j)))
                        {
                                a->cardsHide[i]->Visible=true;
                                a->cards[i]->Visible=false;
                                a->cardsHide[j]->Visible=true;
                                a->cards[j]->Visible=false;
                        }
                 }
                 }

                 for(int i=0;i<32;i++)
                        if(AnsiSameStr(rec, "Score: " + IntToStr(i)))
                                Form1->Label2->Caption = "Score player 1: " + IntToStr(a->player1->GetScore());





}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
         Form1->ServerSocket1->Close();
         Form1->ClientSocket1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
String rec = Socket->ReceiveText();
        for(int i=0 ;i<32;i++)
                {
                        if(AnsiSameStr(rec, "firstID: "+IntToStr(i)))
                        {
                                a->cardsHide[i]->Visible=false;
                        }
                }

for(int i=0 ;i<32;i++){
                        for(int j=0;j<32;j++)
                        {
                        if(AnsiSameStr(rec, "ID: "+IntToStr(i)+" " + IntToStr(j)))
                        {
                                a->cardsHide[i]->Visible=true;
                                a->cards[i]->Visible=false;
                                a->cardsHide[j]->Visible=true;
                                a->cards[j]->Visible=false;
                        }
                 }
                 }


                 for(int i=0;i<32;i++)
                        if(AnsiSameStr(rec, "Score: " + IntToStr(i)))
                                Form1->Label1->Caption = "Score player 2: " + IntToStr(a->player2->GetScore());
}
//---------------------------------------------------------------------------

