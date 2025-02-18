//
// Created by c on 3/8/23.
//

#ifndef UNTITLED_MINESWEEPERBOARD_H
#define UNTITLED_MINESWEEPERBOARD_H

struct Field
{
    bool hasMine; //Czy pole zawiera mine 1-tak
    bool hasFlag; //Czy pole zawiera flage 1-tak
    bool isRevealed; //Czy pole jest odkryte 1-tak
};

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class MinesweeperBoard
{

    Field board[100][100];// tablica 2D

    int width;                // rzeczywista szeroko�� planszy
    int height;               // rzeczywista wysoko�� planszy

public:
    //MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);//You can't reach width and height larger than 100
    void debug_display() const;
    int getBoardWidth() const; //zwraca szerokosc planszy
    int getBoardHeight() const; //zwraca wysokosc planszy
    int getMineCount() const; //zwraca ilosc min
    bool firstMove();
    int countMines(int row, int col) const; //zwraca ilosc min wokol zadanego pola
    bool hasFlag(int row, int col) const; //true - zadane pole mialo flage, false - bez flagi, flaga juz byla, poza plansza
    void toggleFlag(int row, int col);//jak pole nieodkryte to zmienic status flagi dla tego pola, inaczej nic nie rob+poza+gra skonczona
    void revealField(int row, int col);//odkryj pole, nic-juz bylo odkryte, poza, gra skonczona, flaga. jezeli mina to 1 tura, przenies ja, kazda kolejna koniec gry
    bool isRevealed(int row, int col) const;//zwraca true jezeli pole bylo odkryte
    GameState getGameState() const;//zwraca aktualny stan gry (- FINISHED_LOSS -- FINISHED_WIN  -- RUNNING  -
    char getFieldInfo(int row, int col) const;
    bool insideBoard(int row, int col) const;
    void allMinesReveal();

};

#endif //UNTITLED_MINESWEEPERBOARD_HH