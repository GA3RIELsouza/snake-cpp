#ifndef BODYPART_H
#define BODYPART_H

#include "Direction.h"

class BodyPart {
private:
	int coordinates[2];
	int lastCoordinates[2];
	BodyPart* son;
	bool head;

public:
	BodyPart();
	BodyPart(int coordinates[2]);

	int* getCoordinates();

	bool isInCoordinates(int coordinates[2]);

	void move(int newCoordinates[2]);

	void createSon();

	BodyPart* getSon();
};

#endif
