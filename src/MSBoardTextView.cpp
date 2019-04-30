#include "MSBoardTextView.h"
#include <iostream>

using namespace std;

MSBoardTextView::MSBoardTextView(MinesweeperBoard b) : board (b){}

void MSBoardTextView::display() const{

    int height = board.getBoardHeight();
    int width = board.getBoardWidth();

         for(int y=0; y<height; y++){
            cout << endl;
           for(int x=0; x<width; x++){
                cout << "["<< board.getFieldInfo(x,y)<< "]";
            }
        }
    }
