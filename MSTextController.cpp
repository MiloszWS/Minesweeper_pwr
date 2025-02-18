//
// Created by pmi03 on 29.03.2023.
//
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include "MSTextController.h"
#include <iostream>

using namespace std;

MSTextController::MSTextController(MinesweeperBoard & board2, MSBoardTextView & v) : board(board2), view(v) {}

void  MSTextController::play()
{
    int menu_choose, row, col;

    while(board.getGameState()==RUNNING){
        view.display();
        cout << endl;
        cout << "Which action do you want to perform?\n";
        cout << "Choose:\n 1. Reveal Field\n 2. Set/Fetch a Flag \n";
        cin >> menu_choose;
        cout << endl;

        if (menu_choose==1){
            cout << "Choose coordinates of th Field: \n";
            cout << "Row: ";
            cin >> row;
            cout << "Col: ";
            cin >> col;

            board.revealField(row, col);
        }
        if (menu_choose==2) {
            cout << "Choose coordinates of th Field: \n";
            cout << "Row: ";
            cin >> row;
            cout << "Col: ";
            cin >> col;

            board.toggleFlag(row, col);
        }

    }
    view.display();
    if (board.getGameState()==FINISHED_LOSS){
        cout << "GAME OVER!\n";
    } else if (board.getGameState()== FINISHED_WIN){
        cout << "YOU WON!\n";
    }
}