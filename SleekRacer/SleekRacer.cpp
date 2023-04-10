#include "SleekRacer.h"

SleekRacer::SleekRacer(std::string name) : carName(name), distance(0), speed(0) {}

std::string SleekRacer::getCarName() const
{
    return carName;
}

int SleekRacer::getDistance() const
{
    return distance;
}

void SleekRacer::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

void SleekRacer::move()
{
    distance += speed;
}
