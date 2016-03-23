#pragma once
#include "GlobalData.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Sprite.h"
#include "PlayerController.h"
#include "Lifespan.h"

struct Entity : GlobalData<Entity>
{
	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<Collider> collider;
	Handle<PlayerController> controller;
	Handle<Sprite> sprite;
	Handle<Lifecycle> lifecycle;

	void onFree()
	{
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider::free(collider.index);
		PlayerController::free(controller.index);
		Sprite::free(sprite.index);
		Lifecycle::free(lifecycle.index);
	}
};