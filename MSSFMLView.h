//
// Created by pmi03 on 08.04.2023.
//
#ifndef INC_273116_MSSFMLVIEW_H
#define INC_273116_MSSFMLVIEW_H
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class MSSFMLView {

    MinesweeperBoard& board;
    sf::RectangleShape field;
    sf:: Font font, font1, font2;
    sf::Text text, text1, text2;

public:
    MSSFMLView(MinesweeperBoard& board1);
    void iconChoose(sf::RenderWindow &window, const std::string& filename, sf::Text &text);
    void draw(sf:: RenderWindow & window);
};

#endif //INC_273116_MSSFMLVIEW_H