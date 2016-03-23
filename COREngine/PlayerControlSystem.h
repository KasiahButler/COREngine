#pragma once
#include "Systems.h"
#include "Input.h"
#include "Time.h"
#include "PlayerController.h"

class PlayerControlSystem : public System
{
	bool condition(Handle<Entity> i)
	{
		return i->rigidbody  > -1 &&
			   i->transform  > -1 &&
			   i->controller > -1;
	}

	void update(Handle<Entity> i)
	{
		auto &input = Input::instance();
		auto &con = *i->controller;
		auto &rB = *i->rigidbody;
		float deltaT = Time::instance().getDeltaTime();

		if (input.getKey(con.RIGHT)) i->rigidbody->addForce({50, 0});

		if (input.getKey(con.LEFT)) i->rigidbody->addForce({ -50, 0 });

		if (input.getKey(con.FORWARD)) i->rigidbody->addForce({ 0, 50 });

		if (input.getKey(con.DOWN)) i->rigidbody->addForce({ 0, -50 });
	}
};