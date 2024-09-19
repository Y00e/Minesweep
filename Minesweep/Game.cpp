#include "Game.h"
#include <iostream>


Game::Game(int rows, int cols, int mines) : board(rows, cols) {
    board.placeMines(mines);
}



void Game::play() {
    while (true) {
        board.printBoard();
        
        char rowChar;
        int col;
        std::cout << "Enter the row and column (e.g., a 3): ";
        std::cin >> rowChar >> col;

        // Adjust for 0-based indexing
        int x = rowChar - 'a';

        int y = col - 1;

        if (!board.isValid(x, y)) {
            std::cout << "Invalid move! Try again." << std::endl;
            continue;
        }

        if (board.revealCell(x, y)) {
            std::cout << "Game Over! You stepped on a mine." << std::endl;
            board.printBoard();
            return;
        }

        if (board.isGameWon()) {
            std::cout << "Congratulations! You won the game." << std::endl;
            board.printBoard();
            return;
        }
    }
}

