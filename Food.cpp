#include "Food.h"
#include "Consts.h"
#include <cstdlib>
#include <ctime>

Food::Food() {
	srand(static_cast<unsigned int>(time(0)));

	this->coordinates[0] = rand() % mapSize;
	this->coordinates[1] = rand() % mapSize;
}

bool Food::isInCoordinates(int coordinates[2]) {
	if (this->coordinates[0] == coordinates[0] && this->coordinates[1] == coordinates[1]) {
		return true;
	}

	return false;
}

int* Food::getCoordinates() {
	return this->coordinates;
}
