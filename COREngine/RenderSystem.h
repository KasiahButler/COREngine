#pragma once
#include "Systems.h"
#include "Assets.h"

class RenderSystem : public System
{
	bool condition(Handle<Entity> i)
	{
		return i->sprite > -1 && i->transform > -1;
	}

	void update(Handle<Entity> i)
	{
		COR::Mat3 m = i->transform->getGlobalTransform()
			*COR::translate(i->sprite->offset)
			*COR::scale(i->sprite->dimensions)
			*COR::rotate(i->sprite->angle);

		Asset::instance().drawTexture(i->sprite->assetName, m);
	}
};