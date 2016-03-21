#include "Collider.h"

COR::CollData evalColl(const Transform &lTransform, const Collider &lColl, const Transform &rTransform, const Collider &rColl)
{
	Transform lTran = lTransform;
	Transform rTran = rTransform;
	Collider lC = lColl;
	Collider rC = rColl;

	if (lC.shape > rC.shape)
	{
		std::swap(lTran, rTran);
		std::swap(lC, rC);
	}

	COR::CollData cd;

	switch (lC.shape | rC.shape)
	{
	case Collider::e_Circle | Collider::e_Circle:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.circle, rTran.getGlobalTransform() * rC.circle);
		break;

	case Collider::e_Circle | Collider::e_AABB:
		cd = COR::CollTest(lTransform.getGlobalTransform() * lColl.circle, rTransform.getGlobalTransform() * rColl.aabb);
		break;

	case Collider::e_Circle | Collider::e_Ray:
		cd = COR::CollTest(lTransform.getGlobalTransform() * lColl.circle, rTransform.getGlobalTransform() * rColl.ray);
		break;

	case Collider::e_Circle | Collider::e_Plane:
		cd = COR::CollTest(lTransform.getGlobalTransform() * lColl.circle, rTransform.getGlobalTransform() * rColl.plane);
		break;

	case Collider::e_AABB | Collider::e_AABB:
		cd = COR::CollTest(lTransform.getGlobalTransform() * lColl.aabb, rTransform.getGlobalTransform() * rColl.aabb);
		break;

	case Collider::e_AABB | Collider::e_Ray:
		cd = COR::CollTest(lTransform.getGlobalTransform() * lColl.aabb, rTransform.getGlobalTransform() * rColl.ray);
		break;

	case Collider::e_AABB | Collider::e_Plane:
		cd = COR::CollTest(lTransform.getGlobalTransform() * lColl.aabb, rTransform.getGlobalTransform() * rColl.plane);
		break;

	case Collider::e_Plane | Collider::e_Ray:
		cd = COR::CollTest(lTransform.getGlobalTransform() * lColl.plane, rTransform.getGlobalTransform() * rColl.ray);
		break;
	}

	return cd;
}