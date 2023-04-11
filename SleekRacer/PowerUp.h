// Header guard to prevent multiple includes of the same header
#ifndef POWER_UP_H
#define POWER_UP_H

// Include necessary header files
#include "SleekRacer.h"

// Declare the base class for power-ups
class PowerUp {
public:
	// Declare a pure virtual function to activate the power-up on a SleekRacer
	virtual void activate(SleekRacer& racer) = 0;
};

// Declare a derived class for the SpeedBoost power-up
class SpeedBoost : public PowerUp {
public:
	// Override the activate() function to set the racer's speed and print a message
	void activate(SleekRacer& racer) override;
};

// End the header guard
#endif
