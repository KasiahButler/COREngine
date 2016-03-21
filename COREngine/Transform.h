#pragma once
#include <list>
#include "GlobalData.h"
#include "Vector2.h"
#include "Matrix3.h"

class Transform : public GlobalData<Transform>
{
	Transform *parent;
	std::list<Transform*> children;
	COR::Vec2 position, scale;
	float angle;

public:
	Transform();
	~Transform();

	COR::Mat3 getGlobalTransform() const;

	void setParent(class Transform* nParent);
	void setPosition(const COR::Vec2 &nPosition) { position = nPosition; }
	void setScale(const COR::Vec2 &nScale) { scale = nScale; }
	void setAngle(float nAngle) { angle = nAngle; }

	COR::Vec2 getPosition() const { return position; }
	COR::Vec2 getScale()     const { return scale; }
	float getAngle()         const { return angle; }

	COR::Vec2 getRight() const { return COR::fromAngle(angle); }
	COR::Vec2 getUp()    const { return (COR::fromAngle(angle)).perpendicular(); }
};