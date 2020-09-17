//---------------------------------------------------------------------------

#ifndef MClassesH
#define MClassesH
//---------------------------------------------------------------------------
class Coord
{
protected:
        int x;
        int y;
public:
          int __fastcall GetX();
          int __fastcall GetY();
          void __fastcall SetX(int x);
          void __fastcall SetY(int y);
};


//------------------------------------------------------------------------------------------------------
class MemoBoard : public Coord
{
protected:
        bool color;
public:
        __fastcall MemoBoard(int x, int y);
        bool __fastcall GETcolor();
        void __fastcall SETcolor(bool z);
};


//------------------------------------------------------------------------------------------------------
class MemoCard : public Coord
{
public:
        bool faceUp;
        TImage *im;
        int cardID;
public:

        __fastcall MemoCard(int x, int y);
        bool __fastcall GETfaceUP(){return this->faceUp;};
        void __fastcall SETfaceUp(bool faceUP){this->faceUp = faceUP;};






};
//------------------------------------------------------------------------------------------------------
class JUCATOR
{
protected:
        int score;
        String name;
public:
        __fastcall JUCATOR();
        String __fastcall GetName();
        int __fastcall GetScore();
        void __fastcall SetScore(int x);
        void __fastcall SetName(String name);


};

//------------------------------------------------------------------------------------------------------
class JOC
{
public:
        int nr,dist,sizeOfImg;
        MemoBoard *board[4][8];
        MemoCard *piece[32];
        TImage *cards[32];
        TImage *cardsHide[32];
        int numOfPairsFlipped;

        int cardsSelected;
        int first,second;
        int firstID, secondID;

        JUCATOR *player1, *player2;
        int playersTurn;

public:
        void __fastcall CreateIMG(TImage *img, TForm *f);
        void __fastcall ShowCards();
        void __fastcall HideCards();
        void __fastcall RandomCards();
        void __fastcall BoardColor();
        void __fastcall WhoWon();
        void __fastcall UpdatePiece();
          __fastcall JOC();
          __fastcall ~JOC();



};


#endif
