#pragma once
class Cell
{
private:
	bool mine;
	bool revealed;
	bool flagged;
	int adjacentMines;
public:
	Cell();
	bool isRevealed() const;
	bool isMine() const;
	bool isFlagged() const;
	void setMine(bool hasMine);
	void setFlag(bool flag);
	void reveal();
	void setAdjacentMines(int count);
	char getDisplayChar() const;
	int getAdjacentMines() const;
	

};

