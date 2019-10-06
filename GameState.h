#ifndef STATE_H
#define STATE_H

#include <array>

#include <QKeyEvent>

#include "Player.h"
#include "Tile.h"

class IGameStateLogic;

using TileStorage = std::array<Tile, 40>;

struct GameState
{
	GameState(const IGameStateLogic *logic);

	GameState updateOffset(long delta) const;

	PROPERTY(long, elapsed)
	PROPERTY(long, charge)
	PROPERTY(long, score)

	PROPERTY(double, speed)
	PROPERTY(double, offset)

	PROPERTY(Player, player)
	PROPERTY(TileStorage, tiles)

	PROPERTY(const IGameStateLogic *, logic)
};

#endif // STATE_H
