#pragma once
#include "Window.h"
#include "sfwdraw.h"

class Input
{
	bool isInit;
	float keyRelease[400];
	float keyPress[400];
	bool keyState[400];

	float mouseRelease[20];
	float mousePress[20];
	bool mouseState[20];

	Input::Input() : isInit(false) {}

	float mouseX, mouseY;
public:
	static Input &instance() { static Input instance; return instance; }

	bool init();
	bool step();
	void term() {}

	bool getKey(unsigned);
	bool getKeyPress(unsigned);
	bool getKeyRelease(unsigned);

	bool getMouseButton(unsigned);
	bool getMouseButtonPress(unsigned);
	bool getMouseButtonRelease(unsigned);

	float keyDelta(unsigned); //Time between last press and release of a key

	inline float getMouseX() { return sfw::getMouseX(); }
	inline float getMouseY() { return sfw::getMouseY(); }

	bool isInitialized() { return isInit; }
};