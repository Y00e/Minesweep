#include "Cell.h"

// initializes constructor with standard values, no mine, no adjacent mines, ni flag and no reveals.
Cell::Cell() : mine(false), revealed(false), 
flagged(false), adjacentMines(0) {}

// get metods, added const so we can not modify the object.
bool Cell::isMine() const { 
	return mine;  
}


bool Cell::isRevealed() const { 
	return revealed; 
}

bool Cell::isFlagged() const {
	return flagged;
}


void Cell::reveal() {
	revealed = true;
}
// set metods 
void Cell::setMine(bool hasMine) {
	mine = hasMine;
}

void Cell::setFlag(bool flag) {
	flagged = flag;
}

void Cell::setAdjacentMines(int count) {
	adjacentMines = count;
}

int Cell::getAdjacentMines() const {
	return adjacentMines;
}


// get Display char return a character based on the cell conditions
char Cell::getDisplayChar() const {
	if (flagged) {
		return 'F';
	} else if (!revealed) {
		return '+';
	} else if (mine) {
		return '*';
	} else if (adjacentMines > 0) {
		return '0' + adjacentMines; 
	} else {
		return '0';
	}
}

