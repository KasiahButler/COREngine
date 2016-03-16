#pragma once
#include "sfwdraw.h"

class Window
{
	bool isInit;
	int width, height;
	Window() : isInit(false) {}

public:

	static Window &instance() { static Window instance; return instance; }
	bool init(int Width = 800, int Height = 600, const char *Title = "COREngine");
	bool step();
	void term();

	int getWidth() { return width; }
	int getHeight() { return height; }
	bool isInitialized() { return isInit; }
};