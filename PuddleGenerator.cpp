#include <QtMath>

#include "PuddleGenerator.h"

bool PuddleGenerator::generate()
{
	return generate_impl(false);
}

bool PuddleGenerator::generate_impl(bool force)
{
	static int tilesSincePuddle;

	const bool puddle = qrand() % 2;

	if (puddle)
	{
		if (force)
		{
			tilesSincePuddle = 0;

			return true;
		}

		if (tilesSincePuddle < 2)
		{
			return generate_impl(true);
		}

		tilesSincePuddle = 0;

		return true;
	}

	if (tilesSincePuddle > 2)
	{
		tilesSincePuddle = 0;

		return true;
	}

	tilesSincePuddle++;

	return false;
}
