//
// Created by pmi03 on 13.04.2023.
//
#include <SFML/Graphics.hpp>
#include "MSSFMLController.h"
#include <cmath>

MSSFMLController::MSSFMLController(MinesweeperBoard & board2, MSSFMLView & view2) : board(board2), view(view2){}

void MSSFMLController::play()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    while (window.isOpen()) {

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (board.getGameState()==RUNNING){
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Right) {
                            std::cout << "the right button was pressed" << std::endl;
                            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        }
                    }

                    if (event.type == sf::Event::MouseButtonPressed) {
                        int row = ceil((event.mouseButton.y - 80) / 48);
                        int col = ceil((event.mouseButton.x - 175+20) / 48);
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            board.revealField(col, row);
                        } else if (event.mouseButton.button == sf::Mouse::Right) {
                            board.toggleFlag(col, row);
                        }
                    }
                }

            }
            window.clear();
            view.draw(window);
            window.display();
    }
}