#pragma once
#include "GlobalData.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"

struct Entity : GlobalData<Entity>
{
	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<Collider> collider;

	void onFree()
	{
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider::free(collider.index);
	}
};