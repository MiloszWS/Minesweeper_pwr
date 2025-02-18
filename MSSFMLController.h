//
// Created by pmi03 on 13.04.2023.
//
#ifndef INC_273116_MSSFMLCONTROLLER_H
#define INC_273116_MSSFMLCONTROLLER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

class MSSFMLController{

public:
    MinesweeperBoard & board;
    MSSFMLView & view;
    MSSFMLController(MinesweeperBoard & board, MSSFMLView & view);
    void play();
};

#endif //INC_273116_MSSFMLCONTROLLER_H

