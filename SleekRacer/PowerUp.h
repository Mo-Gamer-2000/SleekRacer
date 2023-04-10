#ifndef POWER_UP_H
#define POWER_UP_H

#include "SleekRacer.h"

class PowerUp {
public:
	virtual void activate(SleekRacer& racer) = 0;
};

class SpeedBoost : public PowerUp {
public:
	void activate(SleekRacer& racer) override;
};

#endif