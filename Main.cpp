#include "Game.h"
#include <iostream>

const int mapSize = 20;
const char backgroundChar = ':';
const char snakeChar = 'O';
const int gameTickMs = 500;

int main(int argc, char** argv) {
	Game game = Game(Snake(), Food());

	return game.gameLoop();
}
