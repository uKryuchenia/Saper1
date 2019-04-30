#include "MinesweeperBoard.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>


using namespace std;



GameState MinesweeperBoard::getGameState() const{

    if(isRevealedWithMine()) return FINISHED_LOSS;
        else if( flagWithMine() or isClosedWithMine() ) return FINISHED_WIN;
            else return RUNNING;

}

char MinesweeperBoard::getFieldInfo(int x, int y) const{

    int countM = countMines(x,y);
    char c;
    switch(countM){
         case 1:{ c='1'; break;}
         case 2:{ c='2'; break;}
         case 3:{ c='3'; break;}
         case 4:{ c='4'; break;}
         case 5:{ c='5'; break;}
         case 6:{ c='6'; break;}
         case 7:{ c='7'; break;}
         case 8:{ c='8'; break;}
    }

    if(x<0 or y<0 or x>width or y>height) return '#';
    if(board[x][y].isRevealed == true and board[x][y].hasMine == true) return 'x';
    if(board[x][y].isRevealed == false and board[x][y].hasFlag == true) return 'F';
    if(board[x][y].isRevealed == false and board[x][y].hasFlag == false) return '_';
    if(board[x][y].isRevealed == true and countM==0 ) return ' ';
    else return c;
}

void MinesweeperBoard::fillMenes(int w, int h, GameMode mode){

   double percent=0;
   int maxRand = w*h;

   if(mode == EASY) percent=0.1;
   else if(mode == NORMAL) percent=0.2;
   else if(mode == HARD) percent=0.3;
   else if(mode == DEBUG){

        h=7;
        w=9;

        for(int y=0; y<h; y++){
            for(int x=0; x<w; x++){
                if(x==y or y==0 or ( x==0 and y%2 == 0)){
                    board[x][y].hasMine= true;
                }
            }
        }
    }

    double maxEasy = maxRand*percent ;
    for(int k=0; k< maxEasy; k++){

            int x=rand()%(width);
            int y=rand()%(height);

            if(board[x][y].hasMine == true){
                    k--;}
            else board[x][y].hasMine = true;
       }
    }

MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode ){

      width = w; //szerokosc
      height = h; //wysokosc

      for(int j=0; j<height; j++){
            for(int i=0; i<width; i++){
                board[i][j].hasMine= false;
                board[i][j].hasFlag= false;
                board[i][j].isRevealed= false;
            }
        }

        if (mode==DEBUG) {height=h; width=w;}
        fillMenes(width,height,mode);


/*
        board[3][3].hasFlag = true;
        board[5][5].isRevealed = true;
        board[5][5].hasMine = false;
        board[4][4].isRevealed = true;
*/
}
int MinesweeperBoard::countAllMines() const{

    int countM=0;

    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            if(board[x][y].hasMine== true){
                countM++;
                    }
                }
            }


    return countM;

}

int MinesweeperBoard::getBoardWidth() const{

    return width;

    }

int MinesweeperBoard::getBoardHeight() const{

    return height;

    }

int MinesweeperBoard::getMineCount() const{

    int quantity=0;

    for(int j=0; j<height; j++){
            for(int i=0; i<width; i++){
                if(board[i][j].hasMine== true){
                    quantity++;
                }

            }
        }
    return quantity;
    }

bool MinesweeperBoard::isRevealed(int x, int y) const{

    if(board[x][y].isRevealed == true)
        return true;
    else return false;
}

bool MinesweeperBoard::isRevealedWithMine() const{

    for(int y=0; y<height; y++){
       for(int x=0; x<width; x++){
          if(board[x][y].isRevealed == true and board[x][y].hasMine == true)  //jeśli jest spęłniony ten warunek wiadomo że jest to koniec gry
        return true;
          }
        }
        return false;
}

bool MinesweeperBoard::isClosedWithMine() const{

        int counter=0;
        int fieldWithoutMine=(height*width)-countAllMines();
        for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
          if(board[x][y].isRevealed == true and board[x][y].hasMine == false)
            counter++;

          }
        }
        if( fieldWithoutMine==counter){
                return true;
        }
        else return false;
}

bool MinesweeperBoard::flagWithMine() const{

    int counter=0;
    for(int y=0; y<height; y++){
       for(int x=0; x<width; x++){
          if((board[x][y].hasFlag == true and board[x][y].hasMine == true)  )
            counter++;

          }
        }
        if( countAllMines()==counter){
                return true;
        }
        else return false;
}

int MinesweeperBoard::countMines(int x, int y) const{

    int quantity=0;
    int x1=x-1,y1=y-1;
    if(x1<0) x1++;
    if(y1<0) y1++;

    if(x > width or y > height){
        return -1;
    }
    for(int j=y1; j<=y+1; j++){
         for(int i=x1; i<=x+1; i++){
                if(board[i][j].hasMine == true){
                    quantity++;
                }
            }
        }
        if(board[x][y].hasMine == true){
                    quantity--;
                }
        return quantity;
    }

bool MinesweeperBoard::hasFlag(int x, int y) const{

    if(board[x][y].hasFlag == true)
        return true;
        /*
    else if(x<0 or x>width or y<0 or y>height or board[x][y].hasFlag == false or board[x][y].isRevealed == true)
        return false;
        */
        else return false;
    }



void MinesweeperBoard::toggleFlag(int x, int y){

    if(x<0 or x>width or y<0 or y>height or board[x][y].hasFlag == true or board[x][y].isRevealed == true){  }
    else
        board[x][y].hasFlag = true;
    }

void MinesweeperBoard::deleteFlag(int x, int y){

    if(board[x][y].hasFlag == true){ board[x][y].hasFlag = false ; }

    }



void MinesweeperBoard::revealField(int x, int y){     //jesli to jest pierwszy krok, zmien miejsce miny, jesli nie pierwszy koniec gry

    if(x<0 or x>width or y<0 or y>height or board[x][y].hasFlag == true or board[x][y].isRevealed == true){  }
    else if(board[x][y].isRevealed == false and board[x][y].hasMine == false)
        board[x][y].isRevealed = true;
    else if(board[x][y].isRevealed == false and board[x][y].hasMine == true){

        if(step == 0){
            for(int k=0; k<1; k++){
            int x1=rand()%(width);
            int y1=rand()%(height);

            if(board[x1][y1].hasMine == true )
                    k--;
            else board[x1][y1].hasMine = true;

            }
                board[x][y].hasMine = false;
                step ++;
                cout << "Step +1 " << endl;

         } else {
            board[x][y].isRevealed = true;
            state = FINISHED_LOSS;
            cout << " FINISHED_LOSS\n";
            }
  }
}

void MinesweeperBoard::debug_display() const{

     for(int j=0; j<height; j++){
            cout << endl;

           for(int i=0; i<width; i++){

                cout << "[";
                if(board[i][j].hasMine)
                    cout<<"M";
                    else cout << ".";

                if(board[i][j].isRevealed)
                    cout<<"o";
                    else cout << ".";

                if(board[i][j].hasFlag)
                    cout<<"f";
                    else cout << ".";

                cout << "]";

            }

      }
}
