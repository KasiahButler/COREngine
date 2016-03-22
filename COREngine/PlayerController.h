#pragma once
#include "GlobalData.h"

class PlayerController : public GlobalData<PlayerController>
{
public:
	unsigned LEFT, RIGHT, FORWARD, DOWN;
	float speed, turnspeed;

	PlayerController() : LEFT(263), RIGHT(262), FORWARD(265), DOWN(264),
		                 speed(60), turnspeed(1) {}
};