#pragma once
#include "CollisionDetection.h"

class DynamicResolution : public CollSystem
{
	bool condition(Collision c)
	{
		return c.first->rigidbody > -1 && c.second->rigidbody > -1;
	}

	void update(Collision c)
	{
		COR::Vec2 mtv = c.collision.normal * c.collision.depth;

		COR::Vec2 p1 = c.first->transform->getPosition() - mtv / 2;
		COR::Vec2 p2 = c.second->transform->getPosition() + mtv / 2;

		c.first->transform->setPosition(p1);
		c.second->transform->setPosition(p2);

		std::swap(c.first->rigidbody->velocity, c.second->rigidbody->velocity);
	}
};