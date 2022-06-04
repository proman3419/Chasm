#include "Player.h"
#include <math.h>

unsigned int Player::getNextLevelExp(unsigned int base, double exponent, unsigned int level)
{
	return floor(base * (pow(level, exponent)));
}

void Player::levelUp()
{
	for (;;)
	{
		unsigned int nextLevelExp = getNextLevelExp();
		if (exp_ >= nextLevelExp)
		{
			++level_;
			exp_ = exp_ - nextLevelExp;
			maxHealth_ = getHealth();
			currHealth_ = maxHealth_;
			attack_ = getAttack();
		}
	}
}
