#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Board_Defines.h"

using namespace sf;


class Snake
{
public:
	Snake();
	void grow(Vector2i food_po);
	void move(int x, int y);
	std::vector<Vector2i> getBody();
	Vector2i getHead();
	int getScore();
	~Snake();
private:
	Vector2i head;
	std::vector<Vector2i> body;
	int score_int = 0;
};

