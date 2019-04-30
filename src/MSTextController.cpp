#include<iostream>
#include "MSTextController.h"


using namespace std;

MSTextController::MSTextController(MinesweeperBoard & b, MSBoardTextView & v) : board (b), view(v)
{}

void MSTextController::play(){

    int x=0,y=0,sw=0;
    cout<<board.getGameState();
    while(board.getGameState()== 0){

        cout << "\n\n1 - put the flag\n2 - reveal field\n3 - view board\n";
        cin >> sw;
        switch(sw){
         case 1:{
            cout<< "x = " ;
            cin >> x;
            cout << "y = ";
            cin >> y;

            board.toggleFlag(x,y);
            /*
            cout<< board.getFieldInfo(x,y);
            board.debug_display();
            cout<<endl<<endl;
            */
            view.display();
         }
         case 2:{
            cout<< "x = " ;
            cin >> x;
            cout << "y = ";
            cin >> y;

            board.revealField(x,y);
            board.debug_display();
            cout<<endl<<endl;
            cout<<"GameState = "<<board.getGameState()<<endl;

            //view.display();
         }
        }
}




}
