// PowerUp.cpp

#include "PowerUp.h"
#include <iostream>

// SpeedBoost method that overrides the activate method in PowerUp class
void SpeedBoost::activate(SleekRacer& racer)
{
	// Set the speed of the racer to 4 if its distance is greater than or equal to 50, otherwise set it to 3
	racer.setSpeed(racer.getDistance() >= 50 ? 4 : 3);
	std::cout << racer.getCarName() << " activated a speed boost!\n"; // Display message to show that the speed boost has been activated
}