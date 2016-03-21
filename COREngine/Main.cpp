#include "Vector2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "sfwdraw.h"
#include "Window.h"
#include "Input.h"
#include "Time.h"
#include "Factory.h"
#include "RigidbodyDynamics.h"
#include "CollisionDetection.h"
#include "DynamicResolution.h"
#include <iostream>

int main()
{
	auto &window = Window::instance();
	auto &input = Input::instance();
	auto &time = Time::instance();

	COR::Vec2 a = { 600, 300 };
	COR::Vec2 speed = { 100, 0 };
	COR::Mat3 b = { 2, 3, 4, 5, 6, 7, 8, 9, 1 };
	COR::Mat4 r = COR::Mat4::identity();
	
	auto e = Factory::makeBall(a, {0, 0}, 20, 1);
	auto f = Factory::makeBall({ 500, 300 }, { 20, 0 }, 20, 1);

	window.init();
	input.init();
	time.init();

	RigidbodyDynamics rDynamics;
	CollDetection cDetect;
	DynamicResolution dRes;

	while (window.step())
	{
		input.step();
		time.step();
		rDynamics.step();
		cDetect.step();
		dRes.step();

		sfw::drawCircle(e->transform->getPosition().x, e->transform->getPosition().y, e->collider->circle.radius);
		sfw::drawCircle(f->transform->getPosition().x, f->transform->getPosition().y, f->collider->circle.radius);
	}

	time.term();
	input.term();
	window.term();
	return 0;
}