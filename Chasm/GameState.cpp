#include "GameState.h"
#include "Constants.h"
#include <math.h>
#include <iostream>

void GameState::minerCycleEnded()
{
	depth_ += digSpeed_;
	rocks_ += digSpeed_ * ROCK_DEPTH_RATIO;
}

void GameState::minerClicked()
{
	depth_ += DIG_CLICK_START * digClickMultiplier_;
	rocks_ += DIG_CLICK_START * digClickMultiplier_ * ROCK_DEPTH_RATIO;
}

double GameState::exponentFunc(double base, double exponent, unsigned int level)
{
	return floor(base * (pow(level, exponent)));
}

int GameState::logFunc(double base, double x)
{
	return static_cast<int>(log(x) / log(base));
}

void GameState::buyIfPossible(unsigned int cost, unsigned int& level, unsigned int& val, const unsigned int newVal)
{
	if (cost <= rocks_)
	{
		rocks_ -= cost;
		++level;
		val = newVal;
	}
}

void GameState::buyDigSpeed()
{
	buyIfPossible(digSpeedNextLevelCost(), digSpeedLevel_, 
		digSpeed_, digSpeedNextLevelValue());
}

void GameState::buyDigClickMultiplier()
{
	buyIfPossible(digClickMultiplierNextLevelCost(), digClickMultiplierLevel_, 
		digClickMultiplier_, digClickMultiplierNextLevelValue());
}

size_t GameState::getDepthLayer()
{
	return std::min(std::max(0, logFunc(DEPTH_LAYER_BASE, depth_)), MINER_BACKGROUNDS_CNT-1);
}
