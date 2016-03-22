#include "Rigidbody.h"
#include "Transform.h"

Rigidbody::Rigidbody() : 
	acceleration({ 0,0 }), velocity({ 0,0 }), mass(1), force({ 0,0 }), drag(.5f) {}

void Rigidbody::addForce(const COR::Vec2 &a) { force = a; }

void Rigidbody::addTorque(float a) { torque = a; }

void Rigidbody::integrate(class Transform *object, float deltaT)
{
	acceleration = force / mass;
	velocity += acceleration * deltaT;
	object->setPosition(object->getPosition() + velocity * deltaT);

	velocity -= velocity * drag * deltaT;
	force = {0,0};
}