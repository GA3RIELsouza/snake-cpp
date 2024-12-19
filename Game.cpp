#include "Game.h"
#include "Consts.h"
#include <iostream>
#include <string>
#include <windows.h>

Game::Game(Snake snake, Food food) {
	this->snake = snake;
	this->food = food;
}

int Game::gameLoop() {
	checkKeyPressed();
	this->getSnake().moveBody(lastDirection);

	printMap();

	this->isSnakeBitingItself = false;

	if (this->snake.getHead().getSon() != nullptr && this->snake.getHead().getSon() != NULL) {
		this->isSnakeBitingItself = this->snake.getHead().getSon()->isInCoordinates(this->snake.getHead().getCoordinates());
	}

	if (this->isSnakeBitingItself) {
		system("cls");
		std::cout << "You lose!" << '\n';
		this->defeat();
		return 1;
	}

	this->isSnakeOnTopOfFood = this->getSnake().getHead().getCoordinates()[0] == this->getFood().getCoordinates()[0] &&
		this->getSnake().getHead().getCoordinates()[1] == this->getFood().getCoordinates()[1];

	if (this->isSnakeOnTopOfFood) {
		this->getSnake().getHead().createSon();
		this->score++;

		do {
			food = Food();
		} while (this->getSnake().isSnakeInCoordinates(this->food.getCoordinates()));
	}

	if (score == mapSize * mapSize) {
		system("cls");
		std::cout << "You win!" << '\n';
		this->victory();
		return 0;
	}

	Sleep(gameTickMs);
	system("cls");

	this->gameLoop();
}

void Game::printMap() {
	std::string map = "";
	int coordinates[2];

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			coordinates[0] = i;
			coordinates[1] = j;

			if (this->snake.isSnakeInCoordinates(coordinates)) {
				map += snakeChar;
			} else if  (this->food.isInCoordinates(coordinates)) {
				map += foodChar;
			} else {
				map += backgroundChar;
			}
			map += ' ';
		}
		map += '\n';
	}
	std::cout << map << '\n' << "Score: " << this->score;
}	

void Game::checkKeyPressed() {
	if ((GetAsyncKeyState(VK_UP) & 0x8000) && lastDirection != Direction::Down) {
		this->lastDirection = Direction::Up;
		return;
	}

	if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && lastDirection != Direction::Up) {
		this->lastDirection = Direction::Down;
		return;
	}

	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && lastDirection != Direction::Right) {
		this->lastDirection = Direction::Left;
		return;
	}

	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && lastDirection != Direction::Left) {
		this->lastDirection = Direction::Right;
		return;
	}
}

Snake& Game::getSnake() {
	return this->snake;
}

Food& Game::getFood() {
	return this->food;
}

void Game::defeat() {
	Beep(250, 400);
	Beep(200, 500);
	Beep(150, 1000);
}

void Game::victory() {
	Beep(300, 300);
	Beep(400, 200);
	Beep(500, 1000);
}
