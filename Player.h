#ifndef PLAYER_H
#define PLAYER_H

#include "Utility.h"

enum State
{
	Idle,
	Charging,
	Jumping
};

struct Player
{
	Player();

	PROPERTY(State, state)

	PROPERTY(double, x)
	PROPERTY(double, y)
	PROPERTY(double, source)
	PROPERTY(double, target)
	PROPERTY(double, f)
};

#endif // PLAYER_H
