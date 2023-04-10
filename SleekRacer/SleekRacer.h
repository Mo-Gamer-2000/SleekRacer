#ifndef SLEEK_RACER_H
#define SLEEK_RACER_H

#include <string>

class SleekRacer
{
public:
    SleekRacer(std::string name);
    std::string getCarName() const;
    int getDistance() const;
    void setSpeed(int newSpeed);
    void move();

private:
    std::string carName;
    int distance;
    int speed;
};

#endif
