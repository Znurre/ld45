#include <QImage>
#include <QPainter>

#include "IdleGameStateLogic.h"
#include "Resources.h"

void IdleGameStateLogic::draw(const GameState &state, QPainter &painter) const
{
	const int index = (state.elapsed / 300) % 4;

	const QRectF targetRect(state.player.x, state.player.y - 128, 128, 128);
	const QRectF sourceRect(index * 128, 0, 128, 128);

	painter.drawImage(targetRect, Resources::idle(), sourceRect);
}

GameState IdleGameStateLogic::update(const GameState &state, long delta) const
{
	return state
		.with_elapsed(state.elapsed + delta)
		.updateOffset(delta);
}

GameState IdleGameStateLogic::keyPressEvent(const GameState &state, QKeyEvent *event) const
{
	if (event->key() == Qt::Key_Space)
	{
		return state
			.with_logic(&m_chargeGameStateLogic)
			.with_charge(0);
	}

	return state;
}

GameState IdleGameStateLogic::keyReleaseEvent(const GameState &state, QKeyEvent *event) const
{
	Q_UNUSED(event)

	return state;
}
