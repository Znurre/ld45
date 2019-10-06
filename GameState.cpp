#include "GameState.h"
#include "IGameStateLogic.h"

GameState::GameState(const IGameStateLogic *logic)
	: elapsed(0)
	, charge(0)
	, score(0)
	, speed(1)
	, offset(-256)
	, logic(logic)
{
}

GameState GameState::updateOffset(long delta) const
{
	return with_offset(offset + (delta / 8.0) + speed / 50);
}
