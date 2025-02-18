
// Created by pmi03 on 08.04.2023.

// Created by pmi03 on 08.04.2023.

#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include <iostream>

MSSFMLView::MSSFMLView(MinesweeperBoard& board1) : board(board1)
{
    field = sf::RectangleShape (sf::Vector2f(40, 40));
    field.setFillColor(sf::Color(0, 0, 0));
    field.setOutlineThickness(5);
    field.setOutlineColor(sf::Color(0, 255, 100));

    font= sf::Font();
    font.loadFromFile("../Textures/Disharmony.ttf");
    text=sf::Text("Minesweeper", font, 65);
    text.setFillColor(sf::Color::Black);
    text.setOutlineColor(sf::Color(0,255,100));
    text.setOutlineThickness(5);
    text.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    font1= sf::Font();
    font1.loadFromFile("../Textures/Disharmony.ttf");
    text1=sf::Text("GAME  OVER", font1, 75);
    text1.setFillColor(sf::Color::Red);
    text1.setOutlineColor(sf::Color::Black);
    text1.setOutlineThickness(5);
    text1.setStyle(sf::Text::Bold);
    text1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    font2= sf::Font();
    font2.loadFromFile("../Textures/Disharmony.ttf");
    text2=sf::Text("  YOU   WON! ", font2, 75);
    text2.setFillColor(sf::Color::Cyan);
    text2.setOutlineColor(sf::Color::Black);
    text2.setOutlineThickness(5);
    text2.setStyle(sf::Text::Bold);
    text2.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

}


void MSSFMLView:: iconChoose(sf::RenderWindow &window, const std::string& filename, sf::Text &text){
    sf :: Texture icon;
    icon.loadFromFile(filename);
    sf::Sprite sprite;
    sprite.setTexture(icon);
    sprite.setScale(0.2f, 0.2f);
    sprite.setPosition(field.getPosition().x + (field.getSize().x - sprite.getGlobalBounds().width) / 2,
                       field.getPosition().y + (field.getSize().y - sprite.getGlobalBounds().height) / 2);
    text.setPosition(sf::Vector2f(window.getSize().x / 2.0f, 40.0f));
    window.draw(field);
    window.draw(sprite);
    window.draw(text);
}


void MSSFMLView::draw(sf::RenderWindow &window)
{
    sf :: Texture EmptyField;
    if (!EmptyField.loadFromFile("../Textures/MINESWEEPER_0.png")){
        std :: cout << "Error! EmptyField texture can't be loaded.\n";
    }
    int boardWidth = board.getBoardWidth();
    int boardHeight = board.getBoardHeight();
    int fieldSize = 48; // rozmiar pojedynczego pola
    int boardWidthPixels = boardWidth * fieldSize;
    int boardHeightPixels = boardHeight * fieldSize;

// obliczamy pozycję lewego górnego rogu planszy
    int boardLeft = (window.getSize().x - boardWidthPixels) / 2;
    int boardTop = (window.getSize().y - boardHeightPixels) / 2;

    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            int x = boardLeft + i * fieldSize;
            int y = boardTop + 20 + j * fieldSize;
            field.setPosition(x, y);

            if (board.getFieldInfo(i,j)=='_'){
                iconChoose(window,"../Textures/MINESWEEPER_X.png",text);
            } else if (board.getFieldInfo(i,j)==' '){
                iconChoose(window,"../Textures/MINESWEEPER_0.png",text);
            } else if (board.getFieldInfo(i,j)=='F'){
                iconChoose(window,"../Textures/MINESWEEPER_F.png",text);
            } else if (board.getFieldInfo(i,j)=='x'){
                iconChoose(window,"../Textures/MINESWEEPER_M.png",text);
            } else if (board.getFieldInfo(i,j)=='1'){
                iconChoose(window,"../Textures/MINESWEEPER_1.png",text);
            } else if (board.getFieldInfo(i,j)=='2'){
                iconChoose(window,"../Textures/MINESWEEPER_2.png",text);
            } else if (board.getFieldInfo(i,j)=='3'){
                iconChoose(window,"../Textures/MINESWEEPER_3.png",text);
            } else if (board.getFieldInfo(i,j)=='4'){
                iconChoose(window,"../Textures/MINESWEEPER_4.png",text);
            } else if (board.getFieldInfo(i,j)=='5'){
                iconChoose(window,"../Textures/MINESWEEPER_5.png",text);
            } else if (board.getFieldInfo(i,j)=='6'){
                iconChoose(window,"../Textures/MINESWEEPER_6.png",text);
            } else if (board.getFieldInfo(i,j)=='7'){
                iconChoose(window,"../Textures/MINESWEEPER_7.png",text);
            } else if (board.getFieldInfo(i,j)=='8'){
                iconChoose(window,"../Textures/MINESWEEPER_8.png",text);
            }
        }
    }

    if (board.getGameState()==FINISHED_LOSS){
        text1.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y/2.0f));
        window.draw(text1);
    } else if (board.getGameState()== FINISHED_WIN){
        text2.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y/2.0f));
        window.draw(text2);
    }
}