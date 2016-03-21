#pragma once
#include "Shapes.h"
#include "Collision.h"
#include "Transform.h"
#include "GlobalData.h"

struct Collider : GlobalData<Collider>
{
	enum SHAPE{e_Circle = 1, e_AABB = 2, e_Ray = 4, e_Plane = 8} shape;
	union
	{
		COR::Circle circle;
		COR::AABB aabb;
		COR::Ray ray;
		COR::Plane plane;
	};

	Collider() : shape(e_Circle), circle{ {0,0}, 1 } {}
};

COR::CollData evalColl(const Transform &lTransform, const Collider &lColl, const Transform &rTransform, const Collider &rColl);