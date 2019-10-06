#include <QtMath>
#include <QPainter>

#include "ChargeGameStateLogic.h"
#include "Player.h"
#include "Resources.h"

void ChargeGameStateLogic::draw(const GameState &state, QPainter &painter) const
{
	const int index = (state.charge / 100) % 5;

	const QRectF targetRect(state.player.x, state.player.y - 128, 128, 128);
	const QRectF sourceRect(index * 128, 0, 128, 128);

	painter.drawImage(targetRect, Resources::charging(), sourceRect);
}

GameState ChargeGameStateLogic::update(const GameState &state, long delta) const
{
	if (state.charge > 512)
	{
		return jump(state);
	}

	return state
		.with_elapsed(state.elapsed + delta)
		.with_charge(state.charge + delta)
		.updateOffset(delta);
}

GameState ChargeGameStateLogic::keyPressEvent(const GameState &state, QKeyEvent *event) const
{
	Q_UNUSED(event)

	return state;
}

GameState ChargeGameStateLogic::keyReleaseEvent(const GameState &state, QKeyEvent *event) const
{
	if (event->key() == Qt::Key_Space)
	{
		return jump(state);
	}

	return state;
}

GameState ChargeGameStateLogic::jump(const GameState &state) const
{
	const double target  = floor((state.player.x + qMax(128l, state.charge)) / 128) * 128;

	return state
		.with_logic(&m_jumpingGameStateLogic)
		.with_player(state.player
			.with_target(target)
			.with_source(state.player.x)
		);
}
