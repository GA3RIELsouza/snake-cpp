#include "BodyPart.h"
#include <algorithm>

#include <iostream> // debug

BodyPart::BodyPart() {}
BodyPart::BodyPart(int coordinates[2]) {
	this->coordinates[0] = coordinates[0];
	this->coordinates[1] = coordinates[1];
	this->lastCoordinates[0] = coordinates[0];
	this->lastCoordinates[1] = coordinates[1];
	this->son = nullptr;
}

int* BodyPart::getCoordinates() {
	return this->coordinates;
}

bool BodyPart::isInCoordinates(int coordinates[2]) {
	if (this->coordinates[0] == coordinates[0] && this->coordinates[1] == coordinates[1]) {
		return true;
	} else if (this->son != nullptr) {
		return this->son->isInCoordinates(coordinates);
	} else {
		return false;
	}
}

void BodyPart::move(int newCoordinates[2]) {
	this->lastCoordinates[0] = this->coordinates[0];
	this->lastCoordinates[1] = this->coordinates[1];
	this->coordinates[0] = newCoordinates[0];
	this->coordinates[1] = newCoordinates[1];

	if (this->son != nullptr) {
		this->son->move(this->lastCoordinates);
	}
}

void BodyPart::createSon() {
	if (this->son == nullptr) {
		this->son = new BodyPart(this->lastCoordinates);
	} else {
		this->son->createSon();
	}
}

BodyPart* BodyPart::getSon() {
	return this->son;
}
