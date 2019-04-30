#ifndef MSTEXTCONTROLLER_H
#define MSTEXTCONTROLLER_H

#include<MSBoardTextView.h>
#include<MinesweeperBoard.h>


class MSTextController
{
    MinesweeperBoard board;
    MSBoardTextView view;

    public:

        MSTextController(MinesweeperBoard & b, MSBoardTextView & v);
        void play() ;

};

#endif // MSTEXTCONTROLLER_H
