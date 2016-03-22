#pragma once
#include "GlobalData.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "PlayerController.h"

struct Entity : GlobalData<Entity>
{
	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<Collider> collider;
	Handle<PlayerController> controller;

	void onFree()
	{
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider::free(collider.index);
		PlayerController::free(controller.index);
	}
};