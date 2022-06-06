#pragma once
#include "Constants.h"
#include <string>
class GameState
{
public:
	void minerCycleEnded();
	void buyDigSpeed();
	void buyDigClickMultiplier();
	bool buyDynamite();
	void buyDynamitePower();
	void minerClicked();
	size_t getDepthLayer();

	unsigned int digSpeedNextLevelValue() { return digSpeed_ + DIG_SPEED_INCREMENT_VAL; }
	unsigned int digSpeedNextLevelCost() { return exponentFunc(DIG_SPEED_COST_BASE, DIG_SPEED_COST_EXPONENT, digSpeedLevel_); }
	unsigned int digClickMultiplierNextLevelValue() { return digClickMultiplier_ * DIG_CLICK_MULTIPLIER_VAL; }
	unsigned int digClickMultiplierNextLevelCost() { return exponentFunc(DIG_SPEED_COST_BASE, DIG_SPEED_COST_EXPONENT, digClickMultiplierLevel_); }
	unsigned int dynamiteCost() { return exponentFunc(DYNAMITE_COST_BASE, DYNAMITE_COST_EXPONENT, dynamitesBought_+1); } // +1 not to worry about 0 as starting value
	unsigned int dynamitePowerNextLevelValue() { return dynamitePower_ * DYNAMITE_POWER_MULTIPLIER_VAL; }
	unsigned int dynamitePowerNextLevelCost() { return exponentFunc(DYNAMITE_POWER_COST_BASE, DYNAMITE_POWER_COST_EXPONENT, dynamitePowerLevel_); }

	unsigned int digSpeed() { return digSpeed_; }
	unsigned int digSpeedLevel() { return digSpeedLevel_; }
	unsigned int digClickMultiplier() { return digClickMultiplier_; }
	unsigned int digClickMultiplierLevel() { return digClickMultiplierLevel_; }
	unsigned int dynamitesBought() { return dynamitesBought_;  }
	unsigned int dynamitePower() { return dynamitePower_; }
	unsigned int dynamitePowerLevel() { return dynamitePowerLevel_; }
	unsigned long long depth() { return depth_; }
	unsigned long long rocks() { return rocks_; }

private:
	double exponentFunc(double base, double exponent, unsigned int level);
	int logFunc(double base, double x);
	void buyIfPossible(unsigned int cost, unsigned int& level, unsigned int& val, const unsigned int newVal);

	unsigned int digSpeed_ = DIG_SPEED_START;
	unsigned int digSpeedLevel_ = 1;

	unsigned int digClickMultiplier_ = 1;
	unsigned int digClickMultiplierLevel_ = 1;

	unsigned int dynamitesBought_ = 0;
	unsigned int dynamitePower_ = DYNAMITE_POWER_START;
	unsigned int dynamitePowerLevel_ = 1;

	unsigned long long depth_ = DEPTH_START;
	unsigned long long rocks_ = ROCKS_START;
};

