#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class SleekRacer
{
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

class PowerUp
{
public:
    virtual void activate(SleekRacer& racer) = 0;
};

class SpeedBoost : public PowerUp
{
public:
    void activate(SleekRacer& racer) override
    {
        racer.setSpeed(racer.getDistance() >= 50 ? 4 : 3);
        std::cout << racer.getCarName() << " activated a speed boost!\n";
    }
};

class Obstacle
{
public:
    virtual bool isPassed(int distance) const = 0;
};

class TightTurn : public Obstacle
{
public:
    bool isPassed(int distance) const override
    {
        return distance >= 20;
    }
};

class Ramp : public Obstacle
{
public:
    bool isPassed(int distance) const override
    {
        return distance >= 40;
    }
};

void progressVisualization(const std::vector<SleekRacer>& racers, const std::vector<Obstacle*>& obstacles)
{
    std::cout << "\nRace Progress Visualization:\n";
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

int main()
{
    std::srand(std::time(nullptr));

    std::vector<SleekRacer> racers = { SleekRacer("Rahmath"), SleekRacer("Friad"), SleekRacer("Moeez") };
    std::vector<PowerUp*> powerUps = { new SpeedBoost(), new SpeedBoost(), new SpeedBoost() };
    std::vector<Obstacle*> obstacles = { new TightTurn(), new TightTurn(), new TightTurn(), new Ramp() };
    

    bool gameFinished = false;
    SleekRacer* winner = nullptr;
    while (!gameFinished)
    {
        SleekRacer* farthestRacer = nullptr;
        for (auto& racer : racers)
        {
            racer.move();

            for (const auto& obstacle : obstacles)
            {
                if (obstacle->isPassed(racer.getDistance()))
                {
                    std::cout << racer.getCarName() << " hit an obstacle and slowed down!\n";
                    racer.setSpeed(1);
                    break;
                }
            }

            if (racer.getDistance() >= 100)
            {
                std::cout << racer.getCarName() << " has won the race!\n";
                farthestRacer = &racer;
                break;
            }

            for (const auto& powerUp : powerUps)
            {
                if (std::rand() % 100 < 25)
                {
                    powerUp->activate(racer);
                }
            }

            if (farthestRacer == nullptr || racer.getDistance() > farthestRacer->getDistance())
            {
                farthestRacer = &racer;
            }
        }

        progressVisualization(racers, obstacles);

        std::cout << "Press Enter to continue the race...";
        std::cin.ignore();

        if (farthestRacer != nullptr && farthestRacer->getDistance() >= 100)
        {
            std::cout << farthestRacer->getCarName() << " has won the race!\n";
            gameFinished = true;
        }
    }

    for (const auto& powerUp : powerUps)
    {
        delete powerUp;
    }
    for (const auto& obstacle : obstacles)
    {
        delete obstacle;
    }

    return 0;
}
