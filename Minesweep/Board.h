#pragma once
#include <vector>

class Board
{
private:
	std::vector<std::vector<char>> grid;
	int rows;
	int cols;
public:
	Board(int r, int c);
	void printBoard() const;


};

