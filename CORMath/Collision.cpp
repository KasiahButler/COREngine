#include "Collision.h"
#include "Defines.h"
#include "FMath.h"
#include <utility>
#include <cmath>

namespace COR
{
	float rayPlaneDist(const Ray &ray, const Plane &plane)
	{
		return (dot(plane.normal, (ray.position - plane.position)) / -dot(plane.normal, ray.direction));
	}

	inline CollData DSAT(float amin, float amax, float bmin, float bmax, Vec2 axis)
	{
		float pDr = amax - bmin;
		float pDl = bmax - amin;

		float pD = std::fminf(pDr, pDl);

		float H = std::copysignf(1, pDr - pDl);


		return{ pD > 0, pD, axis*H };
	}

	CollData CollTest(const Circle &lhs, const Circle &rhs)
	{
		CollData cd;

		cd.normal = (rhs.position - lhs.position).normal();
		cd.depth = (rhs.radius + lhs.radius) - (rhs.position - lhs.position).magnitude();
		cd.collision = cd.depth > 0;

		return cd;
	}

	CollData CollTest(const Circle &circle, const AABB &rect)
	{
		CollData cd{ false };

		auto mm = rect.min();
		auto mx = rect.max();

		auto xc = fclamp(circle.position.x, mm.x, mx.x);

		Vec2 point = { xc , fclamp(circle.position.y, mm.y, mx.y) };
		const float dist = (point - circle.position).magnitude();

		Vec2 normal = { 0.0f, 0.0f };
		if (point.x == rect.min().x) { cd.normal.x = -1.0f; }
		else if (point.x == rect.max().x) { cd.normal.x == 1.0f; }

		if (point.y == rect.min().y) { cd.normal.y = -1.0f; }
		else if (point.y == rect.max().y) { cd.normal.y = 1.0; }

		cd.depth = circle.radius - dist;
		cd.collision = (cd.depth >= 0.0f);

		return cd;
	}

	CollData CollTest(const Circle &lhs, const Plane &rhs)
	{
		float cDot = dot(rhs.normal, (lhs.position - rhs.position));
		CollData cd{ false, (lhs.radius - cDot), rhs.normal };
		if (cDot <= lhs.radius)
		{
			cd.collision = true;
		}
		return cd;
	}

	CollData CollTest(const Circle &lhs, const Ray &rhs)
	{
		CollData cd = { false, 0, 0 };
		float cD = dot(lhs.position, rhs.position);
		float clPoint = fclamp(cD, 0, rhs.length);
		Vec2 closePoint = rhs.position + rhs.direction * clPoint;

		float cTest = dot((lhs.position - closePoint), (lhs.position - closePoint));

		if (cTest <= lhs.radius * lhs.radius)
		{
			//Need to determine Collision Normal and Penetration Depth.
			cd = { true, 0, 0 };
		}
		return cd;
	}

	CollData CollTest(const AABB &a, const AABB &b)
	{
		auto cdx = DSAT(a.min().x, a.max().x, b.min().x, b.max().x, { 1, 0 });
		auto cdy = DSAT(a.min().y, a.max().y, b.min().y, b.max().y, { 0, 1 });

		return cdx.depth < cdy.depth ? cdx : cdy;
	}

	CollData CollTest(const AABB &lhs, const Plane &rhs)
	{
		CollData cd{ false, 0, 0 };

		Vec2 localDis = lhs.position - rhs.position;

		float rectPlaneTest = lhs.halfextents.x * abs(dot(rhs.normal, RIGHT)) + lhs.halfextents.y * abs(dot(rhs.normal, UP));
		float penTest = rectPlaneTest - dot(rhs.normal, localDis);

		if (dot(rhs.normal, localDis) <= rectPlaneTest) cd = { true, penTest, rhs.normal };
		else cd = { false, penTest, rhs.normal };

		return cd;
	}

	CollData CollTest(const AABB &lhs, const Ray &rhs)
	{
		CollData cd = { false };

		// Min/Max along the X-Axis
		Plane s1p1 = Plane{ lhs.max(), RIGHT };
		Plane s1p2 = Plane{ lhs.min(), LEFT };
		float t11 = rayPlaneDist(rhs, s1p1); // Right
		float t12 = rayPlaneDist(rhs, s1p2); // Left
		float t1min = std::fminf(t11, t12);
		float t1max = std::fmaxf(t11, t12);
		Vec2  n1 = (t11 < t12) ? Vec2 RIGHT : Vec2 LEFT;

		// Min/Max along the Y-Axis
		Plane s2p1 = Plane{ lhs.max(), UP };
		Plane s2p2 = Plane{ lhs.min(), DOWN };
		float t21 = rayPlaneDist(rhs, s2p1);
		float t22 = rayPlaneDist(rhs, s2p2);
		float t2min = std::fminf(t21, t22);
		float t2max = std::fmaxf(t21, t22);
		Vec2  n2 = (t21 < t22) ? Vec2 UP : Vec2 DOWN;

		float tmin = std::fmaxf(t2min, t1min);
		float tmax = std::fminf(t2max, t1max);

		cd.depth = rhs.length - tmin;
		cd.collision = cd.depth >= 0 && tmin <= tmax && tmin > 0;
		cd.normal = (t1min > t2min) ? n1 : n2;

		return cd;
	}

	CollData CollTest(const Ray &lhs, const Plane &rhs)
	{
		CollData cd{ false, 0, 0 };
		Vec2 rLength = lhs.length * lhs.direction;
		Vec2 localDist = lhs.position - rhs.position;
		float rayPlaneTest = (dot(rhs.normal, localDist) / dot(rhs.normal, rLength) * -1);

		if(rayPlaneTest >= 0 && rayPlaneTest <= lhs.length)
		{
			return cd = { true, lhs.length - rayPlaneTest, lhs.direction.normal() * -1 };
		}
		else { return cd; }
	}
}