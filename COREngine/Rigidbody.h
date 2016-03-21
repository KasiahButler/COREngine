#pragma once
#include "GlobalData.h"
#include "Vector2.h"

class Rigidbody : public GlobalData<Rigidbody>
{
public:
	float mass, drag;

	COR::Vec2 velocity, acceleration, force;

	Rigidbody();

	void addForce(const COR::Vec2 &a);
	void integrate(class Transform *object, float deltaT);
};