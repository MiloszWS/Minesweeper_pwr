//
// Created by c on 3/22/23.
//
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <iostream>

using std::cout;

MSBoardTextView::MSBoardTextView( MinesweeperBoard &b): board(b){}

void  MSBoardTextView::display() {

    cout << std::endl;
    for (int i = 0; i < board.getBoardHeight(); ++i) {
        for (int j = 0; j < board.getBoardWidth(); ++j) {
            cout << "[" << board.getFieldInfo(i,j) << "]";
        }
        cout << std::endl;
    }
}