#pragma once
class Cell
{
private:
	bool mine;
	bool revealed;
public:
	Cell();
	bool isRevealed() const;
	bool isMine() const;

};

