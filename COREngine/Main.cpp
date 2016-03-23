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
#include "PlayerControlSystem.h"
#include "DebugDraw.h"
#include "RenderSystem.h"
#include "LifetimeSystem.h"
#include <iostream>

int main()
{
	auto &window = Window::instance();
	auto &input = Input::instance();
	auto &time = Time::instance();

	auto e = Factory::makeBall({ 300, 300 }, { 0, 0 }, 20, 1);
	auto f = Factory::makeSquare({ 600, 300 }, { -20, 0 }, {20, 20}, 1);

	e->controller = PlayerController::make();

	window.init();
	input.init();
	time.init();

	e->rigidbody->addDrag(0);

	
	RigidbodyDynamics rDynamics;
	CollDetection cDetect;
	DynamicResolution dRes;
	PlayerControlSystem pCon;
	LifetimeSystem lSystem;
	RenderSystem rendSystem;
	DebugDraw dBDraw;

	while (window.step())
	{
		input.step();
		time.step();

		dBDraw.step();
		pCon.step();

		rDynamics.step();
		lSystem.step();

		cDetect.step();
		dRes.step();
		rendSystem.step();
	}

	time.term();
	input.term();
	window.term();
	return 0;
}