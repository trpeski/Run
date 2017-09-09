#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include <time.h>
#include <stdlib.h>

using namespace sf;


class Board
{
public:
	Board(RenderWindow& window, Event& event, Snake& snake);
	void setCellColor(int x, int y, Color c);
	void update();
	void draw();
	void gameOver();
	~Board();
private:
	RectangleShape map[NUMBER_OF_CELLS + 2][NUMBER_OF_CELLS + 2];
	Snake& snake;
	RenderWindow& window;
	Event& event;
	Vector2i food;
};

