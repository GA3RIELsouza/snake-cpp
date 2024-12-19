#include "Snake.h"
#include "Consts.h"

Snake::Snake() {
    int coordinates[2] = {1, 1};

    this->head = BodyPart(coordinates);
}

void Snake::moveBody(Direction direction) {
    int newCoordinates[2] = {this->head.getCoordinates()[0],
                            this->head.getCoordinates()[1]};
    

    switch (direction) {
    case Direction::Up:
        if (newCoordinates[0] == 0) {
            newCoordinates[0] = (mapSize - 1);
        } else {
            newCoordinates[0] -= 1;
        }
        break;

    case Direction::Down:
        if (newCoordinates[0] == (mapSize - 1)) {
            newCoordinates[0] = 0;
        } else {
            newCoordinates[0] += 1;
        }
        break;

    case Direction::Left:
        if (newCoordinates[1] == 0) {
            newCoordinates[1] = (mapSize - 1);
        } else {
            newCoordinates[1] -= 1;
        }
        break;

    case Direction::Right:
        if (newCoordinates[1] == (mapSize - 1)) {
            newCoordinates[1] = 0;
        } else {
            newCoordinates[1] += 1;
        }
        break;
    }

    this->head.move(newCoordinates);
}

bool Snake::isSnakeInCoordinates(int coordinates[2]) {
    return this->head.isInCoordinates(coordinates);
}

void Snake::die() {
    this->alive = false;
}

bool Snake::isAlive() const {
    return this->alive;
}

BodyPart& Snake::getHead() {
    return this->head;
}
