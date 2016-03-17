#pragma once
#include "sfwdraw.h"

class Window
{
private:
	bool isInit;
	unsigned int width, height;
	Window() : isInit(false) {}

public:
	static Window &instance() { static Window instance; return instance; }
	bool init(unsigned int Width = 800, unsigned int Height = 600, const char *Title = "COREngine") { return sfw::initContext(Width, Height, Title); }
	bool step() { return sfw::stepContext(); }
	void term() { sfw::termContext(); isInit = false; }

	int getWidth() { return width; }
	int getHeight() { return height; }
	bool isInitialized() { return isInit; }
};