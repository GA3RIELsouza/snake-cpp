#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include "Direction.h"

class Game {
private:
	Snake snake;
	Food food;
	Direction lastDirection = Direction::Right;
	bool isSnakeBitingItself;
	bool isSnakeOnTopOfFood;
	int score = 0;

public:
	Game(Snake snake, Food food);

	int gameLoop();

	void printMap();

	void checkKeyPressed();

	Snake& getSnake();

	Food& getFood();

	void defeat();

	void victory();
};

#endif
