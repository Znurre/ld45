#ifndef TILE_H
#define TILE_H

#include "Utility.h"

struct Tile
{
	Tile();

	PROPERTY(bool, hasPuddle)
	PROPERTY(int, index)
};

#endif // TILE_H
