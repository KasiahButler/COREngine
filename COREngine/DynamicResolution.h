#pragma once
#include "CollisionDetection.h"

#include <iostream>

class DynamicResolution : public CollSystem
{
	bool condition(Collision c)
	{
		return c.first->rigidbody > -1 && c.second->rigidbody > -1;
	}

	void update(Collision c)
	{
		COR::Vec2 mtv = c.collision.normal * c.collision.depth;

		std::cout << c.collision.depth << " cd" << std::endl;
		std::cout << c.collision.normal.x << "," << c.collision.normal.y << " norm" << std::endl;

		COR::Vec2 p1 = c.first->transform->getPosition() + mtv / 2;
		COR::Vec2 p2 = c.second->transform->getPosition() - mtv / 2;

		c.first->transform->setPosition(p1);
		c.second->transform->setPosition(p2);

		switch (c.first->collider->shape)
		{
		default:
			break;
		case Collider::SHAPE::e_Circle:
			c.first->rigidbody->velocity = COR::reflect(c.first->rigidbody->velocity, c.collision.normal);
			break;
		case Collider::SHAPE::e_AABB:
			c.first->rigidbody->velocity = -(c.first->rigidbody->velocity) / 4;
			c.first->rigidbody->force = {0,0};
			break;
		case Collider::SHAPE::e_Plane:
			break;
		case Collider::SHAPE::e_Ray:
			break;
		}

		switch (c.second->collider->shape)
		{
		default:
			break;
		case Collider::SHAPE::e_Circle:
			c.second->rigidbody->velocity = COR::reflect(c.second->rigidbody->velocity, c.collision.normal);
			break;
		case Collider::SHAPE::e_AABB:
			c.second->rigidbody->velocity = -(c.second->rigidbody->velocity) / 4;
			c.second->rigidbody->force = { 0,0 };
			break;
		case Collider::SHAPE::e_Plane:
			break;
		case Collider::SHAPE::e_Ray:
			break;
		}
	}
};