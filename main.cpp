#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"

int main()
{
    MinesweeperBoard board(10, 10, EASY);
    MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora
    MSSFMLController ctrl(board,view);

    ctrl.play();

    return 0;
}