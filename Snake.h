#ifndef SNAKE_H
#define SNAKE_H

#include "BodyPart.h"

class Snake {
private:
	BodyPart head;
	bool alive = true;

public:
	Snake();

	void moveBody(Direction direction);

	bool isSnakeInCoordinates(int coordinates[2]);

	void die();

	bool isAlive() const;

	BodyPart& getHead();
};

#endif
