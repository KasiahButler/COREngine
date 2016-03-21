#pragma once
#include "Window.h"

class Time
{
	bool isInit;
	Time() : isInit(false) {}

public:
	static Time &instance() { static Time instance; return instance; }

	bool init() { return isInit = Window::instance().isInitialized(); }
	bool step() { return true; }
	void term() { }

	bool isInitialised() { return isInit; }

	inline float getTime() { return sfw::getTime(); }
	inline float getDeltaTime() { return sfw::getDeltaTime(); }
};