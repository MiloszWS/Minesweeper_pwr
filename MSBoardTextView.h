//
// Created by c on 3/22/23.
//

#ifndef INC_273116_MSBOARDTEXTVIEW_H
#define INC_273116_MSBOARDTEXTVIEW_H

#include "MinesweeperBoard.h"

class MSBoardTextView{
    const MinesweeperBoard& board;
public:
    MSBoardTextView( MinesweeperBoard &b) ;
    void display();
};

#endif //INC_273116_MSBOARDTEXTVIEW_H
