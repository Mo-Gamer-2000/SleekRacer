// Obstacle.cpp

#include "Obstacle.h"

bool TightTurn::isPassed(int distance) const
{
	return distance >= 20;
}

bool Ramp::isPassed(int distance) const
{
	return distance >= 40;
}