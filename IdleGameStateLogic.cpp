#include "IdleGameStateLogic.h"

void IdleGameStateLogic::draw(const GameState &state, QPainter &painter) const
{
	Q_UNUSED(state)
	Q_UNUSED(painter)
}

GameState IdleGameStateLogic::update(const GameState &state, long delta) const
{
	Q_UNUSED(delta)

	return state;
}

GameState IdleGameStateLogic::keyPressEvent(const GameState &state, QKeyEvent *event) const
{
	Q_UNUSED(event)

	if (event->key() == Qt::Key_Space)
	{
		return state
			.with_logic(&m_chargeGameStateLogic)
			.with_elapsed(0);
	}

	return state;
}

GameState IdleGameStateLogic::keyReleaseEvent(const GameState &state, QKeyEvent *event) const
{
	Q_UNUSED(event)

	return state;
}
