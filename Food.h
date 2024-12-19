#ifndef FOOD_H
#define FOOD_H

class Food {
private:
	int coordinates[2];
	bool eaten;

public:
	Food();

	bool isInCoordinates(int coordinates[2]);

	int* getCoordinates();

	void teste();
};

#endif
