#include "Game.h"
#include <iostream>
#include <limits>


Game::Game(int rows, int cols, int mines) : board(rows, cols) {
    board.placeMines(mines);
}



void Game::play() {
    while (true) {
        board.printBoard();

        char rowChar;
        int col;
        char action;

        std::cout << "Enter action (R for reveal, F for flag), row and column (ex, R a 3): ";
        std::cin >> action >> rowChar >> col;

        if (std::cin.fail()) {
            std::cin.clear(); // clear the error status
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Adjust for 0-based indexing
        int x = std::toupper(rowChar) - 'A';

        int y = col - 1;


        if (!board.isValid(x, y)) {
            std::cout << "Invalid move! Try again." << std::endl;
            continue;
        }

        
        action = std::toupper(action);
        if (action == 'F') {
            board.toggleFlag(x, y);
        }
        else if (action == 'R') {
            if (board.revealCell(x, y)) {
            std::cout << "Game Over! You stepped on a mine." << std::endl;
            board.printBoard();
            return;
        }
        }
       

        if (board.isGameWon()) {
            std::cout << "Congratulations! You won the game." << std::endl;
            board.printBoard();
            return;
        }
    }
}

