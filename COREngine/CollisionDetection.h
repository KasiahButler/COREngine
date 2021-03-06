#pragma once
#include <vector>
#include "Entity.h"
#include "Systems.h"
#include "Collision.h"

struct Collision
{
public:
	Handle<Entity> first, second;
	COR::CollData collision;

	static std::vector<Collision> &getData()
	{
		static std::vector<Collision> data;
		return data;
	}
};

class CollSystem
{
	virtual bool condition(Collision coll) = 0;
	virtual void update(Collision coll) = 0;
	virtual void onStep() {}

public:
	void step()
	{
		onStep();
		for each(Collision coll in Collision::getData())
		{
			if(condition(coll))
			update(coll);
		}
	}
};

class CollDetection : public BinarySystem
{
	void onStep() { Collision::getData().clear(); }

	bool condition(Handle<Entity> i) { return i->transform > -1 && i->collider > -1; }

	void update(Handle<Entity> lhs, Handle<Entity> rhs)
	{
		Transform lTran = *lhs->transform;
		Transform rTran = *rhs->transform;
		Collider lC = *lhs->collider;
		Collider rC = *rhs->collider;

		if (lC.shape > rC.shape)
		{
			std::swap(lTran, rTran);
			std::swap(lC, rC);
		}

		auto cd = evalColl(lTran, lC, rTran, rC);

		if (cd.collision)
			Collision::getData().push_back(Collision{ lhs, rhs, cd });
	}
};