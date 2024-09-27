#include "Cell.h"

// initializes constructor with standard values, no mine, no adjacent mines, ni flag and no reveals.
Cell::Cell() : mine(false), revealed(false),
	adjacentMines(0) {}

// get metods, added const so we can not modify the object.
bool Cell::isMine() const { 
	return mine;  
}



void Cell::reveal() {
	revealed = true;
}

// set metods 
void Cell::setMine(bool hasMine) {
	mine = hasMine;
}

void Cell::setDisplayChar(char character) {
	displayChar = character;

}

void Cell::setAdjacentMines(int count) {
	adjacentMines = count;
}

int Cell::getAdjacentMines() const {
	return adjacentMines;
}


// get Display char return a character based on the cell conditions
char Cell::getDisplayChar() const {
	return displayChar;
}

