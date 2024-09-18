#include "Cell.h"

Cell::Cell() : mine(false), revealed(false) {}

bool Cell::isMine() const { 
	return mine;  
}

bool Cell::isRevealed() const { 
	return revealed; 
}

bool Cell::isMine() const {
	return mine;
}

void Cell::reveal() {
	revealed = true;
}
// sets Mint to has mine
void Cell::setMine(bool hasMine) {
	mine = hasMine;
}
// get Display char return a character based on the cell conditions
char Cell::getDisplayChar() const {
	if (!isRevealed) {
		return '+';
	} else if (mine) {
		return '*';
	} else {
		return ' ';
	}
}