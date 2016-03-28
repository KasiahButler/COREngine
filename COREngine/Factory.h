#pragma once
#include "Entity.h"

class Factory
{
public:
	static Handle<Entity> makeBall(COR::Vec2 pos, COR::Vec2 vel, float radius, float mass)
	{
		auto e = Entity::make();
		e->collider = Collider::make();
		e->transform = Transform::make();
		e->rigidbody = Rigidbody::make();

		e->collider->circle.radius = radius;
		e->collider->shape = Collider::e_Circle;
		e->transform->setPosition(pos);
		e->rigidbody->velocity = vel;
		e->rigidbody->mass = mass;

		return e;
	}

	static Handle<Entity> makeSquare(COR::Vec2 pos, COR::Vec2 vel, COR::Vec2 halfextents, float mass)
	{
		auto e = Entity::make();
		e->collider = Collider::make();
		e->transform = Transform::make();
		e->rigidbody = Rigidbody::make();

		e->collider->shape = Collider::e_AABB;
		e->collider->aabb.halfextents = halfextents;
		e->transform->setPosition(pos);
		e->rigidbody->velocity = vel;
		e->rigidbody->mass = mass;

		return e;
	}

	static Handle<Entity> makePlane(COR::Vec2 pos, COR::Vec2 normal)
	{
		auto e = Entity::make();
		e->collider = Collider::make();
		e->transform = Transform::make();

		e->transform->setAngle(normal.angle());

		e->collider->plane.normal = COR::Vec2{ 1, 0 };
		e->collider->shape = Collider::e_Plane;
		e->transform->setPosition(pos);

		return e;
	}
};