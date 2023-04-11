//SleekRacer.cpp

#include "SleekRacer.h"

// Constructor for SleekRacer
SleekRacer::SleekRacer(std::string name) : carName(name), distance(0), speed(0) {}

// Get the name of the racer
std::string SleekRacer::getCarName() const
{
	return carName;
}

// Get the distance traveled by the racer
int SleekRacer::getDistance() const
{
	return distance;
}

// Set the speed of the racer to newSpeed
void SleekRacer::setSpeed(int newSpeed)
{
	speed = newSpeed;
}

// Move the racer by adding speed to the distance traveled
void SleekRacer::move()
{
	distance += speed;
}