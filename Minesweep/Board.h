#pragma once
#include <vector>
#include "Cell.h"

class Board
{
private:
	std::vector<std::vector<Cell>> board;
	int rows;
	int cols;
	int revealedCount;
	int mineCount;
public:
	Board(int r, int c);
	void printBoard() const;
	void placeMines(int numberOfMines);
	bool isValid(int x, int y) const;
	int countMines(int x, int y) const;
	int countMinesAround(int x, int y) const;
	void revealEmptyCells(int x, int y);
	bool revealCell(int x, int y);
	bool isGameWon() const;


};
