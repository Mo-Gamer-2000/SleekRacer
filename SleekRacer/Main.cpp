// Include necessary header files
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// Include user-defined classes
#include "SleekRacer.h"
#include "PowerUp.h"
#include "Obstacle.h"

// Include user-defined classes
void progressVisualization(const std::vector<SleekRacer>& racers, const std::vector<Obstacle*>& obstacles)
{
    std::cout << "\nRace Progress Visualization:\n";
    // Loop over all racers and display their progress
    for (const auto& racer : racers)
    {
        std::cout << racer.getCarName() << ": ";
        // Divide the distance by 5 to display progress in 20 steps
        for (int i = 0; i < racer.getDistance() / 5; ++i)
        {
            bool passedObstacle = false;
            //Check if an obstacle is present at this step
            for (const auto& obstacle : obstacles)
            {
                if (obstacle->isPassed(i * 5))
                {
                    std::cout << "X"; // Display 'X' if the obstacle is passed
                    passedObstacle = true;
                    break;
                }
            }
            if (!passedObstacle)
            {
                std::cout << "-"; // Display '-' if there are no obstacles
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Main function
int main()
{
    std::srand(std::time(nullptr));

    // Create a vector of SleekRacer objects
    std::vector<SleekRacer> racers = { SleekRacer("Rahmath"), SleekRacer("Friad"), SleekRacer("Moeez") };

    // Create a vector of PowerUp pointers and initialize them to SpeedBoost objects
    std::vector<PowerUp*> powerUps = { new SpeedBoost(), new SpeedBoost(), new SpeedBoost() };

    // Create a vector of Obstacle pointers and initialize them to TightTurn and Ramp objects
    std::vector<Obstacle*> obstacles = { new TightTurn(), new TightTurn(), new TightTurn(), new Ramp() };
    

    bool gameFinished = false;
    SleekRacer* winner = nullptr;

    // Game loop
    while (!gameFinished)
    {
        SleekRacer* farthestRacer = nullptr;

        // Loop over all racers and update their progress and speed
        for (auto& racer : racers)
        {
            racer.move();

            for (const auto& obstacle : obstacles)
            {
                if (obstacle->isPassed(racer.getDistance()))
                {
                    std::cout << racer.getCarName() << " hit an obstacle and slowed down!\n";
                    racer.setSpeed(1); // Set the speed of the racer to 1 if an obstacle is hit
                    break;
                }
            }

            // Check if the racer has reached the finish line
            if (racer.getDistance() >= 100)
            {
                std::cout << racer.getCarName() << " has won the race!\n";
                farthestRacer = &racer;
                break;
            }

            for (const auto& powerUp : powerUps)
            {
                if (std::rand() % 100 < 25) // 25% chance of activating the power-up
                {
                    powerUp->activate(racer); // activate the power-up for the current racer
                }
            }

            if (farthestRacer == nullptr || racer.getDistance() > farthestRacer->getDistance())
            {
                farthestRacer = &racer; // set the current racer as the farthest racer so far
            }
        }

        progressVisualization(racers, obstacles); // Visualize the race progress

        std::cout << "Press Enter to continue the race...";
        std::cin.ignore();

        if (farthestRacer != nullptr && farthestRacer->getDistance() >= 100) // If a racer has completed the race
        {
            std::cout << farthestRacer->getCarName() << " has won the race!\n"; // Announce the winner
            gameFinished = true; // Set the game finished flag to true
        }
    }

    // Deallocate the memory for powerUps and obstacles
    for (const auto& powerUp : powerUps)
    {
        delete powerUp;
    }
    for (const auto& obstacle : obstacles)
    {
        delete obstacle;
    }

    return 0; // End the program and return 0 to indicate success
}
