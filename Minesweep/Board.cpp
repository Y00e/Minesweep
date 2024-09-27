#include "Board.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Cell.h"
#include <fstream>


// contructor initializes the board with given dimensions.
Board::Board(int r, int c) : rows(r), cols(c),
board (r, std::vector<Cell>(c)),
revealedCount(0), mineCount(0) {
	std::srand(std::time(nullptr)); // sets up the random number generator
}

// prints out the board using letters for rows and numbers for columns.
void Board::printBoard() const {
	std::cout << "   ";
	for (int i = 0; i < cols; ++i) {
		std::cout << (i + 1) << " "; // i + 1, means that column start with nr 1. 
	}
	std::cout << std::endl << "  ";

	for (int i = 0; i < cols; ++i) {
		std::cout << "==";
	}
	std::cout << std::endl;
	
	
	for (int i = 0; i < rows; ++i) {
		std::cout << " " << static_cast<char>(97 + i) << " "; // static cast char, 97 is the small leter a, so the row is start with a.
			for (int j = 0; j < cols; ++j) {
				std::cout << board[i][j].getDisplayChar() << " ";
			}
			std::cout << std::endl;
		}
}


// This metod randomly places the number of mines of board. 
void Board::placeMines(int numberOfMines) {
	mineCount = numberOfMines;
	int placedMines = 0;
	while (placedMines < numberOfMines) {
		int x = std::rand() % rows;
		int y = std::rand() % cols;
		if (!board[x][y].isMine()) {
			board[x][y].setMine(true);

			placedMines++;
		}
	}
}

// controlling the coordinates x, y are inside the playboard.
bool Board::isValid(int x, int y) const {
	return (x >= 0 && x < rows && y >= 0 && y < cols);  
}

// count mines that surrounding a given cell, it count 8 cells.
int Board::countMines(int x, int y) const {
	int count = 0;
	for (int i = x - 1; i <= x + 1; ++i) {
		for (int j = y - 1; j <= y + 1; ++j) {
			if (isValid(i, j) && board[i][j].isMine()) {
				++count;
			}
		}
	}
	return count;
}

// it revells a cell, if its mine '*', if its emtyp '0' or if its adjacent Mines it need to be bigger than 0.
bool Board::revealCell(int x, int y) {
	if (!isValid(x, y) || board[x][y].getDisplayChar() != '+') {
		return false;
	}
	if (board[x][y].isMine()) {
		board[x][y].reveal();
		board[x][y].setDisplayChar('*');

		return true;
	}

	int adjacentMines = countMines(x, y);
	char displayChar = '0' + adjacentMines;
	board[x][y].setDisplayChar(displayChar);
	
	board[x][y].reveal();
	++revealedCount;



	if (adjacentMines == 0) {
		for (int i = x - 1; i <= x + 1; ++i) {
			for (int j = y - 1; j <= y + 1; ++j) {
				if (isValid(i, j) && board[i][j].getDisplayChar() == '+') {
					revealCell(i, j);  // Recursively reveal adjacent cells
				}
			}
		}
	}

	return false;
}

// Toggles a flag on a cell if its not revealed.
void Board::toggleFlag(int x, int y) {
	if (isValid(x, y) && !board[x][y].getDisplayChar() == '+') {
		board[x][y].setDisplayChar('F');
	}
}

// Handling the saving to a file.
bool Board::saveGame(const std::string& filename) const {
	std::ofstream outFile(filename);

	if (!outFile) {
		std::cerr << " Cannot open the file" << filename << std::endl;
		return false;
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			const Cell& cell = board[i][j];
			outFile << cell.isMine() << " "
				<< cell.getDisplayChar() << " "
				<< "\n";
		}
		outFile << '\n';
	}
	outFile.close();
	return true;
}

// loading a file that was saved.
bool Board::loadGame(const std::string& filename) {
	std::ifstream inFile(filename);

	if (!inFile) {
		std::cerr << "Cannot open the file" << filename << std::endl;
		return false;
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			bool isMine;
			char displayChar;

			inFile >> isMine >> displayChar;

			/*inFile >> isMine >> displayChar;*/

			board[i][j].setMine(isMine);
			board[i][j].setDisplayChar(displayChar);
		}
	}

	inFile.close();
	return true;
}



// checks if game is won by comparing the nr of revealed cells with nr of non mine cells.
bool Board::isGameWon() const {
	return revealedCount == rows * cols - mineCount;
}