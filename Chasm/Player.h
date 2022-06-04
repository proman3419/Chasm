#pragma once
#include "Character.h"
#include "Constants.h"
class Player :
	public Character
{
public:
	void levelUp();

private:
	unsigned int getNextLevelExp(unsigned int base, double exponent, unsigned int level);

private:
	unsigned int level_ = PLAYER_BASE_LEVEL;
	unsigned int exp_ = PLAYER_BASE_EXP;
	unsigned int maxHealth_ = PLAYER_BASE_HEALTH;
	unsigned int currHealth_ = maxHealth_;
	unsigned int attack_ = PLAYER_BASE_ATTACK;
};

