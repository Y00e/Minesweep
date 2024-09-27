#pragma once
class Cell
{
private:
	bool mine;
	bool revealed;
	int adjacentMines;
	char displayChar = '+';
public:
	Cell();
	bool isMine() const;
	void setMine(bool hasMine);
	void setDisplayChar(char character);
	void reveal();
	void setAdjacentMines(int count);
	char getDisplayChar() const;
	int getAdjacentMines() const;
	

};

