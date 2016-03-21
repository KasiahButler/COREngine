#include "Rigidbody.h"
#include "Transform.h"

Rigidbody::Rigidbody() : 
	acceleration({ 0,0 }), velocity({ 0,0 }), mass(1), force({ 0,0 }), drag(0) {}

void Rigidbody::addForce(const COR::Vec2 &a) { force += a; }

void Rigidbody::integrate(class Transform *object, float deltaT)
{
	velocity += acceleration * deltaT;

	object->setPosition(object->getPosition() + velocity * deltaT);
}