#include <iostream>
#include "Board.h"
#include "Game.h"


const int ROWS = 10;
const int COLS = 10;
const int MINES = 15;

int main()
{   
    
    
    std::cout << "Minesweep Start Game!\n";
    
    Game game(ROWS, COLS, MINES);
    game.play();

    return 0;
}

