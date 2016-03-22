#pragma once
#include "GlobalData.h"
#include "Vector2.h"

class Rigidbody : public GlobalData<Rigidbody>
{
public:
	float mass, drag, torque;
	COR::Vec2 velocity, acceleration, force;

	Rigidbody();

	void addForce(const COR::Vec2 &a);
	void addTorque(float a);
	void addDrag(float a) { drag = a; }
	void integrate(class Transform *object, float deltaT);
};