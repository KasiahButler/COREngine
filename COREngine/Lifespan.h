#pragma once
#include "GlobalData.h"

class Lifecycle : public GlobalData<Lifecycle>
{
public:
	float lifetime;
	float lifespan;

	Lifecycle() : lifetime(0), lifespan(10) {}
};