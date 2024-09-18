#include "Board.h"
#include <iostream>

Board::Board(int r, int c) : rows(r), cols(c) {}


void Board::printBoard() const {
	std::cout << "   ";
	for (int i = 0; i < cols; ++i) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	for (int i = 0; i < rows; ++i) {
			std::cout << " " << i << " ";
			for (int j = 0; j < cols; ++j) {
				std::cout << grid[i][j] << " ";
			}
			std::cout << std::endl;
		}
}

	