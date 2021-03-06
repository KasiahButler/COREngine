#pragma once
#include "Shapes.h"

namespace COR
{
	struct CollData
	{
		bool collision;
		float depth;
		Vec2 normal;

		inline Vec2 MTV() { return depth * normal; }
	};

	float rayPlaneDist(const Ray &ray, const Plane &plane);

	CollData CollTest(const Circle &lhs, const Circle &rhs);
	CollData CollTest(const Circle &lhs, const AABB &rhs);
	CollData CollTest(const Circle &lhs, const Plane &rhs);
	CollData CollTest(const Circle &lhs, const Ray &rhs);

	CollData CollTest(const AABB &lhs, const AABB &rhs);
	CollData CollTest(const AABB &lhs, const Plane &rhs);
	CollData CollTest(const AABB &lhs, const Ray &rhs);

	CollData CollTest(const Ray &lhs, const Plane &rhs);

	inline CollData CollTest(const Ray &lhs, const Circle &rhs)
	{
		return CollTest(rhs, lhs);
	}
	inline CollData CollTest(const Ray &lhs, const AABB &rhs)
	{
		return CollTest(rhs, lhs);
	}
	inline CollData CollTest(const AABB &lhs, const Circle &rhs)
	{
		return CollTest(rhs, lhs);
	}
	inline CollData CollTest(const Plane &lhs, const Plane &rhs)
	{
		return CollTest(rhs, lhs);
	}
	inline CollData CollTest(const Plane &lhs, const Ray &rhs)
	{
		return CollTest(rhs, lhs);
	}
	inline CollData CollTest(const Plane &lhs, const AABB &rhs)
	{
		return CollTest(rhs, lhs);
	}
	inline CollData CollTest(const Plane &lhs, const Circle &rhs)
	{
		return CollTest(rhs, lhs);
	}
}