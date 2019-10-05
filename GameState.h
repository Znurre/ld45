#ifndef STATE_H
#define STATE_H

#include <array>

#include <QKeyEvent>

#include "Player.h"
#include "Puddle.h"

class IGameStateLogic;

using PuddleStorage = std::array<Puddle, 10>;

struct GameState
{
	GameState(const IGameStateLogic *logic);

	PROPERTY(long, elapsed)

	PROPERTY(Player, player)
	PROPERTY(PuddleStorage, puddles)

	PROPERTY(const IGameStateLogic *, logic)
};

#endif // STATE_H
