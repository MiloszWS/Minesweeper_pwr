//
// Created by pmi03 on 29.03.2023.
//
#ifndef INC_273116_MSTEXTCONTROLLER_H
#define INC_273116_MSTEXTCONTROLLER_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>

class MSTextController{
public:
     MinesweeperBoard & board;
     MSBoardTextView & view;
    MSTextController(MinesweeperBoard & board, MSBoardTextView & view);
    void play();
};

#endif //INC_273116_MSTEXTCONTROLLER_H