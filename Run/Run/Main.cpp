#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Board.h"
#include <thread>

using namespace std;
using namespace sf;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, PSTR args, int nCmdShow)
{
	int score_int = 0;
	Text score(String(score_int));

	Event event;
	Snake snk;
	RenderWindow win(VideoMode(NUMBER_OF_CELLS * CELL_SIZE, NUMBER_OF_CELLS * CELL_SIZE), "Snake Game");
	Board brd(win, event, snk);

	Vector2i dir(0, 0);

	bool control = false;

	Clock dt;

	while (win.isOpen()) {
		while (win.pollEvent(event))
		{

			if (event.type == Event::Closed)win.close();


			if (event.type == Event::KeyPressed) {
				switch (event.key.code)
				{
				case Keyboard::G:
					if (event.key.control)
						snk.grow(Vector2i(0, 0));
					break;
				case Keyboard::Up:
					if (dir != Vector2i(1, 0)) {
						dir = { -1, 0 };
						snk.move(dir.x, dir.y);
						control = true;
					}
					break;
				case Keyboard::Down:
					if (dir != Vector2i(-1, 0)) {
						dir = { 1, 0 };
						snk.move(dir.x, dir.y);
						control = true;
					}
					break;
				case Keyboard::Left:
					if (dir != Vector2i(0, 1)) {
						dir = { 0, -1 };
						snk.move(dir.x, dir.y);
						control = true;
					}
					break;
				case Keyboard::Right:
					if (dir != Vector2i(0, -1)) {
						dir = { 0, 1 };
						snk.move(dir.x, dir.y);
						control = true;
					}
					break;
				}
			}
		}

		dt.restart();
		if (!control)
		{
			snk.move(dir.x, dir.y);
		}
		control = false;
		brd.update();
		brd.draw();
		Time t = dt.getElapsedTime();
		if (t.asMilliseconds() < 60) 
		{
			Sleep(60 - t.asMilliseconds());
		}

	}
	return 0;
}

