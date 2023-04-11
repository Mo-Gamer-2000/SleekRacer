#ifndef OBSTACLE_H	// include guard to prevent multiple inclusions
#define OBSTACLE_H

class Obstacle {  // base class for all obstacles
public:
	virtual bool isPassed(int distance) const = 0; // virtual function to check if the obstacle is passed
};

class TightTurn : public Obstacle { // derived class for tight turns
public:
	bool isPassed(int distance) const override; // implementation of isPassed function for tight turns
};

class Ramp : public Obstacle { // derived class for ramps
public:
	bool isPassed(int distance) const override; // implementation of isPassed function for ramps
};

#endif // end of include guard