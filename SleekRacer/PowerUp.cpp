#include "PowerUp.h"

#include <iostream>

void SpeedBoost::activate(SleekRacer& racer)
{
	racer.setSpeed(racer.getDistance() >= 50 ? 4 : 3);
	std::cout << racer.getCarName() << " activated a speed boost!\n";
}