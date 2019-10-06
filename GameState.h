#ifndef STATE_H
#define STATE_H

#include <array>

#include <QKeyEvent>

#include "Player.h"
#include "Tile.h"

class IGameStateLogic;

using TileStorage = std::array<Tile, 20>;

struct GameState
{
	GameState(const IGameStateLogic *logic);

	PROPERTY(long, elapsed)

	PROPERTY(Player, player)
	PROPERTY(TileStorage, tiles)

	PROPERTY(const IGameStateLogic *, logic)
};

#endif // STATE_H
