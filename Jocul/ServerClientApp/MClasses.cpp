//---------------------------------------------------------------------------


#pragma hdrstop
#include <vcl.h>
#include "MClasses.h"
#include "CodMemory.h"

#pragma package(smart_init)
//------------------------------------------------------------------------------------------------------
//------------------------------------ COORDINATES CLASS  ----------------------------------------------

 int __fastcall Coord::GetX()
 {
        return this->x;
 }

 int __fastcall Coord::GetY()
 {
        return this->y;
 }

 void __fastcall Coord::SetX(int x)
 {
        this->x = x;
 }

 void __fastcall Coord::SetY(int y)
 {
        this->y = y;
 }

//------------------------------------------------------------------------------------------------------
//------------------------------------ BOARD CLASS  ----------------------------------------------------

 __fastcall MemoBoard::MemoBoard(int x, int y)
 {
        this->x = x;
        this->y = y;
        this->color =false;
 }

 bool __fastcall MemoBoard::GETcolor()
 {
        return this->color;
 }

 void __fastcall MemoBoard::SETcolor(bool z)
 {
        this->color = z;
 }


//------------------------------------------------------------------------------------------------------
//------------------------------------ CARDS CLASS  ----------------------------------------------------

 __fastcall MemoCard::MemoCard(int x, int y)
{
        this->x=x;
        this->y=y;
        this->faceUp = false;
}


 

//------------------------------------------------------------------------------------------------------
//------------------------------------ GAME CLASS  -----------------------------------------------------

        __fastcall JOC::JOC()
{
         nr=16;
         dist= 120;
         sizeOfImg=70;
         cardsSelected=0;
         playersTurn=0;

         numOfPairsFlipped=0;

         player1 = new JUCATOR();
         player2 = new JUCATOR();


          //Instantiere obiecte board si card

        int dist2 = 72;
        for(int i = 0 ; i < 4 ; i++)
        {
                for(int j=0;j< 8;j++){
                        board[i][j] = new MemoBoard(59+dist*j, dist2);
               }
                dist2 += dist;
        }


        int ct = 0;
        for(int j = 0; j < 32 ; j++){

           if(j<8)
           {
                int i=0;
                piece[j] = new MemoCard(board[i][j]->GetX(), board[i][j]->GetY()) ;
                ct++;
           }
           else
           {
                if(ct >= 8 && ct <16)
                {
                        int i=1;
                        int j2 = j-8;
                        piece[j] = new MemoCard(board[i][j2]->GetX(), board[i][j2]->GetY()) ;
                        ct++;
                }
                else if(ct >= 16 && ct < 24)
                {       int i=2;
                        int j2= j-16;
                        piece[j] = new MemoCard(board[i][j2]->GetX(), board[i][j2]->GetY()) ;
                        ct++ ;

                }
                else if(ct >= 24 && ct < 32)
                {      int i=3;
                        int j2= j-24;
                        piece[j] = new MemoCard(board[i][j2]->GetX(), board[i][j2]->GetY()) ;
                        ct++ ;
                }


           }


        }
}
//------------------------------------------------------------------------------------------------------
 void __fastcall JOC::CreateIMG(TImage *img, TForm *f)
{
        img->Parent=f;
        img->Height=sizeOfImg+20;
        img->Width=sizeOfImg;
        img->Transparent=false;
        img->Visible=true;
        img->Stretch=true;

}
//------------------------------------------------------------------------------------------------------
void __fastcall JOC::ShowCards()
{
         // int keys[32];
          String path= "images\\";
          String str[17]={path+"card2.bmp",path+"card3.bmp",path+"card4.bmp",path+"card5.bmp",path+"card6.bmp",path+"card7.bmp",
                path+"card8.bmp",path+"card9.bmp",path+"card10.bmp",path+"card11.bmp",path+"card12.bmp",path+"card13.bmp",path+"card14.bmp",
                path+"card15.bmp",path+"card16.bmp",path+"card17.bmp"};
          for(int i = 0 ;i < nr*2 ; i++)
          {
                cards[i]=new TImage(Form1);
                CreateIMG(cards[i],Form1);                      /*fct cu 2 param ,(this)  (TForm*)this    */
                //piece[i]->im->Top = piece[i]->GetY();
                //piece[i]->im->Left= piece[i]->GetY();
                //piece[i]->im->Picture->LoadFromFile(str[i/2])
                cards[i]->Top = piece[i]->GetY();
                cards[i]->Left = piece[i]->GetX();
                cards[i]->Picture->LoadFromFile(str[i/2]);
                //------------------------
                piece[i]->SETfaceUp(true);
                cards[i]->Visible= piece[i]->GETfaceUP();


                if(i%2==0)
                {
                        cards[i]->Tag = i;
                        piece[i]->cardID = i*10;

                }else{
                        cards[i]->Tag = i-1;
                        piece[i]->cardID = i*10;

                        }
                 /* cards[0]-- 0
                        cards[1]-- 0
                        cards[2]-- 2
                        cards[3]-- 2
                        cards[4]-- 4
                        cards[5]-- 4

                        keys[i]=i;
                else keys[i]=i-1;*/

          }

}
void __fastcall JOC::UpdatePiece()
{
        for(int i = 0 ;i < nr*2 ; i++)
          {
                piece[i]->SetY(cards[i]->Top);
                piece[i]->SetX(cards[i]->Left);
          }

}
//------------------------------------------------------------------------------------------------------
void __fastcall JOC::RandomCards()
{      int k1,k2;
        srand(time(NULL));
                for(int i=0;i<10;i++)
                {
                k1= rand()%32;
                k2= rand()%32;


                Form1->Image1->Picture = cards[k1]->Picture;
                cards[k1]->Picture = cards[k2]->Picture;
                cards[k2]->Picture = Form1->Image1->Picture;

                Form1->Image1->Tag = cards[k1]->Tag;
                cards[k1]->Tag = cards[k2]->Tag;
                cards[k2]->Tag= Form1->Image1->Tag;
                 //transmitem catre client imaginile amestecate, deci indecsii cartilor care fac swap
                 Form1->ServerSocket1->Socket->Connections[0]->SendText("swap: " + IntToStr(k1)+ " " + IntToStr(k2));
                 Sleep(500);

                }
                Form1->Image1->Visible=false;
}
//------------------------------------------------------------------------------------------------------
void __fastcall JOC::HideCards()
{

          for(int i = 0 ;i < nr*2 ; i++)
          {
                 String path="images\\";
                cardsHide[i]=new TImage(Form1);
                CreateIMG(cardsHide[i],Form1);
                cardsHide[i]->Top= piece[i]->GetY();
                cardsHide[i]->Left=piece[i]->GetX();
                cardsHide[i]->Picture->LoadFromFile(path+"greenCard.bmp");
                //------------------------
                piece[i]->SETfaceUp(true);
                cardsHide[i]->Visible=piece[i]->GETfaceUP();
                //trimitem catre client un mesaj "hide: " pentru a stii sa intoarca cartiile
                if(Form1->ServerSocket1->Active)
                        Form1->ServerSocket1->Socket->Connections[0]->SendText("hide: ");


          }
           for(int i=0;i<32;i++)
        {
            cardsHide[i]->OnClick= Form1->funcClick;

        }
}
//------------------------------------------------------------------------------------------------------

void __fastcall JOC::BoardColor()
{
             if(board[1][1]->GETcolor()==true)
                {
                        Form1->Color = clSilver;
                        board[1][1]->SETcolor(false);
                }
                else if(board[1][1]->GETcolor()==false)
                        {
                                Form1->Color= clActiveCaption;
                                board[1][1]->SETcolor(true);

                        }



 }
//------------------------------------------------------------------------------------------------------
__fastcall JOC::~JOC()
{

}
//------------------------------------------------------------------------------------------------------
void __fastcall JOC::WhoWon()
{

         if(numOfPairsFlipped == nr)
         {
                if(player1->GetScore() > player2->GetScore() )
                {
                        ShowMessage("Player 1 wins!");
                }else if(player1->GetScore() < player2->GetScore())
                        {
                                ShowMessage("Player 2 wins!");
                        }else   ShowMessage("Draw!");
         }




}
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
//------------------------------------ PLAYER CLASS  -----------------------------------------------------

String __fastcall JUCATOR::GetName()
{
        return this->name;
}
int __fastcall JUCATOR::GetScore()
{
        return this->score;
}
void __fastcall JUCATOR::SetScore(int x)
{
        this->score=x;

}
void __fastcall JUCATOR::SetName(String name)
{
        this->name=name;
}

__fastcall JUCATOR::JUCATOR()
{
        this->score=0;
        this->name="Mike";
}
