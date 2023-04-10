#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "SleekRacer.h"
#include "PowerUp.h"
#include "Obstacle.h"

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
