#pragma once
#include "Board.h"

class Game
{
public:
    Game(int rows, int cols, int mines);
    ~Game();

    void play();
    

private:
    Board* board;
};

