#include "Board.h"
#include <assert.h>
#include <windows.h>


Board::Board(RenderWindow& window, Event& event, Snake& snake) 
	: window(window), event(event), snake(snake)
{
	int pos_x = 0;
	int pos_y = 0;

	for (int i = 0; i < NUMBER_OF_CELLS; i++) 
	{
		for (int j = 0; j < NUMBER_OF_CELLS; j++) 
		{
			map[i][j].setPosition(pos_x, pos_y);
			map[i][j].setSize(Vector2f(CELL_SIZE, CELL_SIZE));
			map[i][j].setFillColor(Color::Black);
			pos_x += CELL_SIZE;
		}
		pos_x = 0;
		pos_y += CELL_SIZE;
	}

	srand(time(0));

	food.x = rand() % 50;
	food.y = rand() % 50;
}

void Board::setCellColor(int x, int y, Color c)
{
	if (x > 50 || x < 0 || y > 50 || y < 0) 
	{
		this->gameOver();
	}

	map[x][y].setFillColor(c);
}

void Board::update()
{

	// clear
	for (int i = 0; i < NUMBER_OF_CELLS; i++)
	{
		for (int j = 0; j < NUMBER_OF_CELLS; j++)
		{
			this->map[i][j].setFillColor(Color::Black);
		}
	}

	// draw snake
	for (int i = 0; i < this->snake.getBody().size(); i++)
	{
		this->setCellColor(this->snake.getBody()[i].x, this->snake.getBody()[i].y, Color::White);
	}

	// check if snake hamhams it self
	for(int i = 1; i < this->snake.getBody().size(); i++)
	{
		if (snake.getBody()[i] == snake.getHead()) 
		{
			this->gameOver();
		}
	}

	// draw food
	map[food.x][food.y].setFillColor(Color::Red);
	
	// check if snake hamhams the food
	if (this->snake.getHead().x == this->food.x && this->snake.getHead().y == this->food.y) 
	{
		this->snake.grow(food);
		food.x = rand() % 50;
		food.y = rand() % 50;
	}
}

void Board::draw()
{
	this->window.clear();

	for (int i = 0; i < NUMBER_OF_CELLS; i++)
	{
		for (int j = 0; j < NUMBER_OF_CELLS; j++)
		{
			this->window.draw(map[i][j]);
		}
	}
	
	this->window.display();
}

void Board::gameOver()
{
	this->window.setTitle("GAME OVER !");
	Sleep(2000);
	this->window.close();
	exit(0);
}


Board::~Board()
{
}
