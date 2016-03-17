#include "Vector2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "sfwdraw.h"
#include "Window.h"
#include <iostream>

int main()
{
	auto &window = Window::instance();

	COR::Vec2 a = { 400, 30 };
	COR::Vec2 speed = { 100, 100 };
	COR::Mat3 b = { 2, 3, 4, 5, 6, 7, 8, 9, 1 };
	COR::Mat4 r = COR::Mat4::identity();
	
	window.init();

	while (window.step())
	{
		sfw::drawCircle(a.x, a.y, 10, 12U, YELLOW);

		if (sfw::getKey('A'))
		{
			a.x -= speed.x * sfw::getDeltaTime();
		}

		if (sfw::getKey('D'))
		{
			a.x += speed.x * sfw::getDeltaTime();
		}

		if (sfw::getKey('W'))
		{
			a.y += speed.y * sfw::getDeltaTime();
		}

		if (sfw::getKey('S'))
		{
			a.y -= speed.y * sfw::getDeltaTime();
		}
	}

	window.term();
	return 0;
}