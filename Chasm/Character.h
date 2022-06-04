#pragma once
#include "WorldMapElement.h"
class Character :
    public WorldMapElement
{
protected:
	unsigned int getHealth(unsigned int base, double exponent, unsigned int level);
	unsigned int getAttack(unsigned int base, double exponent, unsigned int level);
};

