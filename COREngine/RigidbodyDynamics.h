#pragma once
#include "Entity.h"
#include "Systems.h"
#include "Time.h"

class RigidbodyDynamics : public System
{
	bool condition(Handle<Entity> i)
	{
		return i->transform > -1 && i->rigidbody > -1;
	}

	void update(Handle<Entity> i)
	{
		i->rigidbody->integrate(&i->transform,
			Time::instance().getDeltaTime());
	}
};