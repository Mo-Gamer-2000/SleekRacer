#ifndef SLEEK_RACER_H   // Include guard to prevent multiple includes of this header
#define SLEEK_RACER_H

#include <string>   // Include the string library

class SleekRacer
{
public:
    SleekRacer(std::string name);    // Constructor that takes a string parameter named "name"
    std::string getCarName() const;  // Member function that returns a string
    int getDistance() const;         // Member function that returns an integer
    void setSpeed(int newSpeed);     // Member function that takes an integer parameter named "newSpeed"
    void move();                     // Member function that does not return anything

private:
    std::string carName;  // A private string data member named "carName"
    int distance;         // A private integer data member named "distance"
    int speed;            // A private integer data member named "speed"
};

#endif   // End of include guard
