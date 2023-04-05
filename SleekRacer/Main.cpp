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
public:
	virtual void activate(WackyRacer& racer) = 0;
};

class SpeedBoost : public PowerUp {
public:
	void activte(WackyRacer& raacer) override
	{
		racer.setSpeed(acer.getdistance() >= 50 ? 4 : 3);
		std::cout << racer.getCarName() << " activated a speed boost!\n";
	}
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