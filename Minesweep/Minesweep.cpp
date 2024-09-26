#include <iostream>
#include "Board.h"
#include "Game.h"


const int ROWS = 10;
const int COLS = 10;
const int MINES = 15;

int main()
{   
    
    
    std::cout << "Welcome to start the minesweep game!\n";
    
    Game game(ROWS, COLS, MINES);
    game.play();

    return 0;
}


