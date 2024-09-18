#include "Board.h"
#include <iostream>
#include <vector>

Board::Board(int r, int c) : rows(r), cols(c),
board (r, std::vector<char>(c, '+')) {}


void Board::printBoard() const {
	std::cout << "   ";
	for (int i = 0; i < cols; ++i) {
		std::cout << (i + 1) << " "; // i + 1, means that column start with nr 1. 
	}
	std::cout << std::endl;
	
	for (int i = 0; i < rows; ++i) {
		std::cout << " " << static_cast<char>(97 + i) << " "; // static cast char, 97 is the small leter a, so the row is start with a.
			for (int j = 0; j < cols; ++j) {
				std::cout << board[i][j] << " ";
			}
			std::cout << std::endl;
		}
}

	