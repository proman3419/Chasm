#pragma once
#include "Constants.h"
#include <string>
class GameState
{
public:
	void update();
	void buyDigSpeed();
	void buyDigClickMultiplier();
	void minerClicked();

	unsigned long long depth();
	unsigned long long rocks();

private:
	double exponentFunc(double base, double exponent, unsigned int level);
	void buyIfPossible(unsigned int cost, unsigned int& level, unsigned int& val, const unsigned int newVal);

	unsigned int digSpeed_ = DIG_SPEED_START;
	unsigned int digSpeedLevel_ = 0;

	unsigned int digClickMultiplier_ = 1;
	unsigned int digClickMultiplierLevel_ = 0;

	unsigned long long depth_ = 0;
	unsigned long long rocks_ = 0;
};

