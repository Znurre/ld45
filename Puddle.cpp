#include "Puddle.h"

Puddle::Puddle()
	: x(0)
{
}

int Puddle::width() const
{
	return 50;
}

int Puddle::right() const
{
	return x + width();
}
