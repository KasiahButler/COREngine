#pragma once
#include "GlobalData.h"
#include "Vector2.h"
#include <string>

class Sprite : public GlobalData<Sprite>
{
public:
	COR::Vec2 offset;
	COR::Vec2 dimensions;
	float angle;

	std::string assetName;

	Sprite() : offset({ 0, 0 }), dimensions({ 1, 1 }), angle(0) {}
};