#include "Collider.h"

COR::CollData evalColl(const Transform &lTransform, const Collider &lColl, const Transform &rTransform, const Collider &rColl)
{
	Transform lTran = lTransform;
	Transform rTran = rTransform;
	Collider lC = lColl;
	Collider rC = rColl;

	COR::CollData cd;

	switch (lC.shape | rC.shape)
	{
	case Collider::e_Circle | Collider::e_Circle:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.circle, rTran.getGlobalTransform() * rC.circle);
		break;

	case Collider::e_Circle | Collider::e_AABB:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.circle, rTran.getGlobalTransform() * rC.aabb);
		break;

	case Collider::e_Circle | Collider::e_Ray:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.circle, rTran.getGlobalTransform() * rC.ray);
		break;

	case Collider::e_Circle | Collider::e_Plane:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.circle, rTran.getGlobalTransform() * rC.plane);
		break;

	case Collider::e_AABB | Collider::e_AABB:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.aabb, rTran.getGlobalTransform() * rC.aabb);
		break;

	case Collider::e_AABB | Collider::e_Ray:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.aabb, rTran.getGlobalTransform() * rC.ray);
		break;

	case Collider::e_AABB | Collider::e_Plane:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.aabb, rTran.getGlobalTransform() * rC.plane);
		break;

	case Collider::e_Plane | Collider::e_Ray:
		cd = COR::CollTest(lTran.getGlobalTransform() * lC.plane, rTran.getGlobalTransform() * rC.ray);
		break;
	}

	return cd;
}