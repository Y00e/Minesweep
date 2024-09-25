#include "Game.h"
#include <iostream>
#include <limits>



Game::Game(int rows, int cols, int mines) {
    board = new Board(rows, cols);

    board->placeMines(mines);
}

Game::~Game() {
    delete board; // free up the memory
}




void Game::play() {
    while (true) {
        board->printBoard();

        char rowChar;
        int col;
        char action;

        std::cout << "Enter action (r for reveal, f for flag) and row and column (ex, ra3) or (S for save, L for load): ";
        std::cin >> action;
        action = std::toupper(action);

        if (action == 'S' || action =='L') {
            
            if (action == 'S') {
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                if (board->saveGame(filename)) {
                    std::cout << "Game saved to " << filename << std::endl;
                }
                else {
                    std::cout << "Failed to save game to " << filename << std::endl;
                }
            }
            else if (action == 'L') {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::cin >> filename;
                if (board->loadGame(filename)) {
                    std::cout << "Game loaded from " << filename << std::endl;
                }
                else {
                    std::cout << "Failed to load game from " << filename << std::endl;
                }
            }
            continue;

            
        }

      

        std::cin >> rowChar >> col;

        if (std::cin.fail()) {
            std::cin.clear(); // clear the error status.
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Adjust for 0-based indexing
        int x = std::toupper(rowChar) - 'A'; // Convertes rowChar to versal, then subtract ASCII value for 'A'.

        int y = col - 1;


        if (!board->isValid(x, y)) {
            std::cout << "Invalid move! Try again." << std::endl;
            continue;
        }
        
        action = std::toupper(action);
        if (action == 'F') {
            board->toggleFlag(x, y);
        }
        else if (action == 'R') {
            if (board->revealCell(x, y)) {
            std::cout << "Game Over! You stepped on a mine." << std::endl;
            board->printBoard();
            return;
        }
        }
       

        if (board->isGameWon()) {
            std::cout << "Congratulations! You won the game." << std::endl;
            board->printBoard();
            return;
        }
    }
}

