#ifndef PLAYER_H
#define PLAYER_H

#include "Utility.h"

struct Player
{
	Player();

	PROPERTY(double, x)
	PROPERTY(double, y)
	PROPERTY(double, source)
	PROPERTY(double, target)
};

#endif // PLAYER_H
