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
	void toggleFlag(int x, int y);
	void saveGame(const std::string& filename) const;
	void loadGame(const std::string& filename) const;
	bool isValid(int x, int y) const;
	int countMines(int x, int y) const;
	bool revealCell(int x, int y);
	bool isGameWon() const;


};
