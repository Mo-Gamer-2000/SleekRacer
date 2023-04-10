#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle {
public:
	virtual bool isPassed(int distance) const = 0;
};

class TightTurn : public Obstacle {
public:
	bool isPassed(int distance) const override;
};

class Ramp : public Obstacle {
public:
	bool isPassed(int distance) const override;
};

#endif