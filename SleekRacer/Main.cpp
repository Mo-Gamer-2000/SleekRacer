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

private:
	std::string carName;
	int distance;
	int speed;
};

class PowerUp {
public:
	virtual void activate(SleekRacer& racer) = 0;
};

class SpeedBoost : public PowerUp {
public:
	void activte(SleekRacer& racer) override
	{
		racer.setSpeed(racer.getDistance() >= 50 ? 4 : 3);
		std::cout << racer.getCarName() << " activated a speed boost!\n";
	}
};

class Obstacle {
public:
	virtual bool isPassed(int distance) const = 0;
};

class TightTurn : public Obstacle {
public:
	bool isPassed(int distance) const override
	{
		return distance >= 20;
	}
};

class Ramp : public Obstacle {
public:
	bool isPassed(int distance) const override
	{
		return distance >= 40;
	}
};

void progressVisualisation(const std::vector<SleekRacer> &racers, const std::vector<Obstacle *> &obstacles)
{
	std::cout << "\nRace Progress Visualisation:\n";
	for (const auto& racer : racers)
	{
		std::cout << racer.getCarName() << ": ";
		for (int i = 0; i < racer.getDistance() / 5; ++i)
		{
			bool passedObstacle = false;
			for (const auto& obstacle : obstacles)
			{
				if (obstacle->isPassed(i * 5))
				{
					std::cout << "X";
					passedObstacle = true;
					break;
				}
			}
			if (!passedObstacle)
			{
				std::cout << "-";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int main() {
	std::cout << "Sleek Racer" << std::endl;

	return 0;
}