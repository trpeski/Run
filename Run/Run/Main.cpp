#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace sf;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, PSTR args, int nCmdShow)
{
	Window win(VideoMode(500,500), "dsf");

	for (;;) 
	{
		win.pollEvent(Event());

	}
	return 0;
}

