#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "SquareGame.h"


int main()
{
    srand(static_cast<unsigned int>(time(0))); // set system clock value as start number
    rand(); // discard the first result

    SquareGame game;

    game.play();

    system("pause");
    return 0;
}