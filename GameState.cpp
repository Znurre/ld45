#include "GameState.h"
#include "IGameStateLogic.h"

GameState::GameState(const IGameStateLogic *logic)
	: elapsed(0)
	, logic(logic)
{
}
