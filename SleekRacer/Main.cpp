#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class SleekRacer {
public:
	SleekRacer(std::string name) : carName(name), distance(0), speed(0) {}
	std::string getCarName() const
	{
		return carName;
	}
	int getDistance() const
	{
		return distance;
	}
	void setSpeed(int newSpeed)
	{
		speed = newSpeed;
	}
	void move()
	{
		distance += speed;
	}

	private;
	std::string carName;
	int distance;
	int speed;
};

class PowerUp {

};

class SpeedBoost : public PowerUp {

};

class Obstacle {

};

class TightTurn : public Obstacle {

};

class Ramp : public Obstacle {

};


int main() {
	std::cout << "Sleek Racer" << std::endl;

	return 0;
}