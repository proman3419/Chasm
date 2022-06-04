#include "Character.h"
#include <math.h>

unsigned int Character::getHealth(unsigned int base, double exponent, unsigned int level)
{
	return floor(base * (pow(level, exponent)));
}

unsigned int Character::getAttack(unsigned int base, double exponent, unsigned int level)
{
	return floor(base * (pow(level, exponent)));
}
