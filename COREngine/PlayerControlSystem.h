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

		if (input.getKey(262)) i->rigidbody->addForce({50, 0});

		if (input.getKey(263)) i->rigidbody->addForce({ -50, 0 });

		if (input.getKey(265)) i->rigidbody->addForce({ 0, 50 });

		if (input.getKey(264)) i->rigidbody->addForce({ 0, -50 });
	}
};