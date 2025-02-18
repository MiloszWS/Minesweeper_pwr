#include <iostream>
#include "MinesweeperBoard.h"
#include <cstdlib>
#include <cmath>

using std::cout;

//MinesweeperBoard::MinesweeperBoard()
//{
//
//    width = 7;
//    height = 7;
//    for (int i = 0; i < height; ++i)
//    {
//
//        for (int j = 0; j < width; ++j)
//        {
//            board[i][j].hasMine = false;
//            board[i][j].hasFlag = false;
//            board[i][j].isRevealed = false;
//
//        }
//    }
//}


MinesweeperBoard::MinesweeperBoard(int Width, int Height, GameMode mode)
{

    int x, y;
    double help;
    width = Width;
    height = Height;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            board[i][j].hasMine= false;
            board[i][j].hasFlag= false;
            board[i][j].isRevealed= false;
        }
    }

    if (mode == DEBUG )
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i==0) board[i][j].hasMine= true;
                if (j==0)
                {
                    if (i%2==0)board[i][j].hasMine= true;
                }
                if (i==j) board[i][j].hasMine=true;
            }
        }
    }
    else
    {
        if (mode == EASY) help = (width*height)*10;
        if (mode == NORMAL) help = (width*height)*20;
        if (mode == HARD)  help = (width*height)*30;

        for (int i = 1; i <= ceil(help/100); i++)
        {
            x = (rand() % height) ;
            y = (rand() % width) ;
            if (!board[x][y].hasMine)
            {
                board[x][y].hasMine = true;
            }
            else i--;
        }
    }

}


void  MinesweeperBoard::debug_display() const
{
    cout << std::endl;
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){

            if (board[i][j].hasMine) cout << "[M";
            else cout << "[.";

            if (board[i][j].isRevealed) cout << "o";
            else cout << ".";

            if (board[i][j].hasFlag) cout << "f]";
            else { cout << ".]"; }
        }
        cout << std::endl;
    }


}

bool MinesweeperBoard ::insideBoard(int row, int col) const {
    if (row<=height && row>=0 || col<=width && col>=0) return true;
    else return false;
}

int MinesweeperBoard :: getBoardWidth() const
{
    return width;
}

int MinesweeperBoard ::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard :: getMineCount() const
{
    int MineCount=0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j){
            if (board[i][j].hasMine) MineCount++;
        }
    }
    return MineCount;
}


int MinesweeperBoard :: countMines(int row, int col) const
{
    int MineCounter=0;

    if (row > height - 1 || col > width - 1 || !board[row][col].isRevealed) return -1;

    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (insideBoard(row+i,col+j)){
                if (board[row+i][col+j].hasMine) MineCounter++;
            }
        }
    }
    if (board[row][col].hasMine) MineCounter--;

    return MineCounter;
}


bool MinesweeperBoard :: hasFlag(int row, int col) const
{
    if (board[row][col].hasFlag) return true;
    if (!board[row][col].hasFlag) return  false;
    if (row>height && row<0 || col>width && col<0) return false;
    if (board[row][col].isRevealed) return false;
}


void MinesweeperBoard :: toggleFlag(int row, int col)
{
    if (!board[row][col].isRevealed) {

        if (board[row][col].hasFlag) board[row][col].hasFlag = false;
        else board[row][col].hasFlag = true;
    }

    if (row >= height || row < 0 || col >= width || col < 0) {}
    else if (getGameState() == FINISHED_WIN || getGameState() == FINISHED_LOSS) {}
}


bool MinesweeperBoard ::firstMove(){
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (board[i][j].isRevealed) return false;
            if (board[i][j].hasFlag) return false;
        }
    }
    return true;
}


void MinesweeperBoard :: revealField(int row, int col)
{
    if (!board[row][col].isRevealed && !board[row][col].hasMine) {
        board[row][col].isRevealed=true;
        getGameState();
    }
    if (!board[row][col].isRevealed && board[row][col].hasMine)
    {
        if (firstMove())
        {
            int x, y;
            board[row][col].hasMine= false;
            do {
                x = (rand() % width) ;
                y = (rand() % height) ;
            } while (board[x][y].hasMine);
            board[x][y].hasMine = true;
            board[row][col].isRevealed=true;
        }
        else if(!firstMove()) {
            getGameState();
            board[row][col].isRevealed=true;
             allMinesReveal();
        }
    }
}


void MinesweeperBoard::allMinesReveal() {
    if (getGameState()==FINISHED_LOSS) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j].hasMine) board[i][j].isRevealed=true;
            }
        }
    }
}


bool MinesweeperBoard :: isRevealed(int row, int col) const
{
    if (insideBoard(row,col) && board[row][col].isRevealed) return true;
    else return false;
}


GameState MinesweeperBoard :: getGameState() const
{
    int counter=0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
        {
            if (board[i][j].isRevealed && board[i][j].hasMine) return FINISHED_LOSS;
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
        {
            if (!board[i][j].isRevealed) counter++;
        }
    }
    if (getMineCount()==counter) return FINISHED_WIN;
    else return RUNNING;
}


char MinesweeperBoard :: getFieldInfo(int row, int col) const
{
    Field chosenField = board[row][col];

    if (!insideBoard(row, col)) return '#';
    else if (!chosenField.isRevealed && chosenField.hasFlag) return 'F';
    else if (!chosenField.isRevealed && !chosenField.hasFlag) return '_';
    else if (chosenField.isRevealed && chosenField.hasMine) return 'x';
    else if (chosenField.isRevealed && !chosenField.hasMine && countMines(row,col)==0) return ' ';
    else if (chosenField.isRevealed && !chosenField.hasMine && countMines(row,col)!=0) return countMines(row, col)+48;
    else return '?';
}