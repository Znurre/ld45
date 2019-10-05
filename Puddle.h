#ifndef PUDDLE_H
#define PUDDLE_H

#include "Utility.h"

struct Puddle
{
	Puddle();

	int width() const;
	int right() const;

	PROPERTY(int, x)
};

#endif // PUDDLE_H
