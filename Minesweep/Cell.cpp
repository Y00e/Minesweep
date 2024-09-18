#include "Cell.h"

Cell::Cell() : mine(false), revealed(false) {}

bool Cell::isMine() const { 
	return mine;  
}

bool Cell::isRevealed() const { 
	return revealed; 
}

