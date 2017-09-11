#include "Snake.h"



Snake::Snake()
{
	this->head.x = 25;
	this->head.y = 25;
	this->body.push_back(Vector2i(25,26));
	
}

void Snake::grow(Vector2i food_pos)
{
	this->score_int += 5;
	this->body.push_back(food_pos);
}

void Snake::move(int x, int y)
{


	for (int i = body.size() - 1; i > 0; i--) 
	{
		body[i] = body[i - 1];
	}

	this->head.x += x;
	this->head.y += y;

	body[0].x = head.x;
	body[0].y = head.y;
	
}

std::vector<Vector2i> Snake::getBody()
{
	return this->body;
}

Vector2i Snake::getHead()
{
	return this->head;
}

int Snake::getScore()
{
	return this->score_int;
}


Snake::~Snake()
{
}
