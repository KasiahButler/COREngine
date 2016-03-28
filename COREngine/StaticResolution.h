#pragma once
#include "CollisionDetection.h"

class StaticResolution : public CollSystem
{
	bool condition(Collision c)
	{
		return c.first->rigidbody > -1 && c.second->rigidbody < 0 ||
		    	c.first->rigidbody < 0 && c.second->rigidbody > -1;
	}

	void update(Collision c)
	{
		if (c.collision.collision)
		{
			Handle<Entity> staticBody;
			Handle<Entity> dynamicBody;
			COR::Vec2 normal = c.collision.normal;

			if (c.first->rigidbody > -1) { dynamicBody = c.first; }
			else { dynamicBody = c.second; }

			COR::Vec2 mtv = c.collision.depth * normal;
			COR::Vec2 newPos = dynamicBody->transform->getPosition() + mtv;
			dynamicBody->transform->setPosition(newPos);
			dynamicBody->rigidbody->velocity = COR::reflect(dynamicBody->rigidbody->velocity, c.collision.normal);
		}
	}
};