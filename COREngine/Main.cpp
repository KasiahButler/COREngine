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
#include <iostream>

void drawSquare(const COR::AABB draw)
{
	sfw::drawLine(draw.position.x + draw.halfextents.x, draw.position.y + draw.halfextents.y, draw.position.x - draw.halfextents.x, draw.position.y + draw.halfextents.y);
	sfw::drawLine(draw.position.x + draw.halfextents.x, draw.position.y - draw.halfextents.y, draw.position.x - draw.halfextents.x, draw.position.y - draw.halfextents.y);
	sfw::drawLine(draw.position.x - draw.halfextents.x, draw.position.y - draw.halfextents.y, draw.position.x - draw.halfextents.x, draw.position.y + draw.halfextents.y);
	sfw::drawLine(draw.position.x + draw.halfextents.x, draw.position.y + draw.halfextents.y, draw.position.x + draw.halfextents.x, draw.position.y - draw.halfextents.y);
}

void dSquare(const Handle<Entity> draw)
{
	auto d = draw->transform->getPosition();
	sfw::drawLine(d.x + 20, d.y + 20, d.x - 20, d.y + 20);
	sfw::drawLine(d.x + 20, d.y - 20, d.x - 20, d.y - 20);
	sfw::drawLine(d.x - 20, d.y - 20, d.x - 20, d.y + 20);
	sfw::drawLine(d.x + 20, d.y + 20, d.x + 20, d.y - 20);
}

void dCircle(const COR::Circle draw)
{
	sfw::drawCircle(draw.position.x, draw.position.y, draw.radius);
}

int main()
{
	auto &window = Window::instance();
	auto &input = Input::instance();
	auto &time = Time::instance();

	auto e = Factory::makeBall({ 300, 300 }, { 0, 0 }, 20, 1);
	auto f = Factory::makeBall({ 600, 300 }, { -20, 0 }, 20, 1);

	e->controller = PlayerController::make();

	window.init();
	input.init();
	time.init();

	e->rigidbody->addDrag(0);

	RigidbodyDynamics rDynamics;
	CollDetection cDetect;
	DynamicResolution dRes;
	PlayerControlSystem pCon;

	while (window.step())
	{
		input.step();
		time.step();

		pCon.step();

		rDynamics.step();

		cDetect.step();
		dRes.step();

		COR::Circle tCircle = { e->transform->getPosition(), 20 };
		COR::Circle kCircle = { f->transform->getPosition(), 20 };
		dCircle(tCircle);
		dCircle(kCircle);

		dCircle(e->collider->circle);
		dCircle(f->collider->circle);
	}

	time.term();
	input.term();
	window.term();
	return 0;
}