// Obstacle.cpp

#include "Obstacle.h"

// Returns true if the obstacle has been passed
// Distance parameter is the distance covered by the racer
bool TightTurn::isPassed(int distance) const
{
	return distance >= 20;
}

// Returns true if the obstacle has been passed
// Distance parameter is the distance covered by the racer
bool Ramp::isPassed(int distance) const
{
	return distance >= 40;
}