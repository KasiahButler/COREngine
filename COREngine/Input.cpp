#include "Input.h"
#include <cstring>

bool Input::init()
{
	memset(keyRelease, 0, 400);
	memset(keyPress, 0, 400);
	memset(mouseRelease, 0, 20);
	memset(mousePress, 0, 20);
	mouseX = mouseY = 0;

	return isInit = Window::instance().isInitialized();
}

bool Input::step()
{
	for (unsigned int i = 0; i < 400; ++i)
	{
		keyState[i] = keyPress[i] > keyRelease[i];

		if (sfw::getKey(i)) keyPress[i] = sfw::getTime();
		else keyRelease[i] = sfw::getTime();

		if (i < 20)
		{
			mouseState[i] = mousePress[i] > mouseRelease[i];
			if (sfw::getMouseButton(i)) mousePress[i] = sfw::getTime();
			else mouseRelease[i] = sfw::getTime();
		}
	}

	mouseX = sfw::getMouseX();
	mouseY = sfw::getMouseY();
	return false;
}

bool Input::getKey(unsigned key)
{
	return keyPress[key] > keyRelease[key];
}

bool Input::getKeyPress(unsigned key)
{
	return getKey(key) && !keyState[key];
}

bool Input::getKeyRelease(unsigned key)
{
	return !getKey(key) && keyState[key];
}

bool Input::getMouseButton(unsigned key)
{
	return mousePress[key] > mouseRelease[key];
}

bool Input::getMouseButtonPress(unsigned key)
{
	return getMouseButton(key) && !mouseState[key];
}

bool Input::getMouseButtonRelease(unsigned key)
{
	return !getMouseButton(key) && mouseState[key];
}

float Input::keyDelta(unsigned key)
{
	return keyPress[key] - keyPress[key];
}