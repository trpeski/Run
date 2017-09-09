// make it global so any module can use it without need to pass it



#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Board.h"


using namespace sf;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, PSTR args, int nCmdShow)
{
	Event event;
	Snake snk;
	RenderWindow win(VideoMode(NUMBER_OF_CELLS * CELL_SIZE, NUMBER_OF_CELLS * CELL_SIZE), "Snake Game");
	Board brd(win, event, snk);
	
	

	Vector2i dir(0, 0);


	while(win.isOpen()){
		while (win.pollEvent(event))
		{

			if (event.type == Event::Closed)win.close();


			if(event.type == Event::KeyPressed){
				switch (event.key.code)
				{
				case Keyboard::Up:
					if (dir != Vector2i(1, 0)) {
						dir = { -1, 0 };
					}
					break;
				case Keyboard::Down:
					if (dir != Vector2i(-1, 0)) {
						dir = { 1, 0 };
					}
					break;
				case Keyboard::Left:
					if (dir != Vector2i(0, 1)) {
						dir = { 0, -1 };
					}
					break;
				case Keyboard::Right:
					if (dir != Vector2i(0, -1)) {
						dir = { 0, 1 };
					}
					break;
				}

			}
		}
		Sleep(20);
		snk.move(dir.x, dir.y);
		brd.update();
		brd.draw();
	}
	return 0;
}

