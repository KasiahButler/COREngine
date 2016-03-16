#include "Window.h"

bool Window::init(int Width, int Height, const char *Title)
{
	return sfw::initContext(Width, Height, Title);
}

bool Window::step() { return sfw::stepContext(); }

void Window::term() { sfw::termContext(); isInit = false; }