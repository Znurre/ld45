#include <QtMath>
#include <QPainter>

#include "ChargeGameStateLogic.h"
#include "Player.h"

void ChargeGameStateLogic::draw(const GameState &state, QPainter &painter) const
{
	Q_UNUSED(state)
	Q_UNUSED(painter)

//	const double distance = state.player.x;
//	const double target = distance + state.elapsed;

//	painter.setPen(Qt::red);

//	const double x[4] = { distance, distance, target, target };
//	const double y[4] = { 0, -200, -100, 0 };

//	for(double u = 0.0; u <= 1.0; u += 0.0001)
//	{
//		const QPointF &position = bezier(x, y, u);

//		painter.drawPoint(position);
//	}
}

GameState ChargeGameStateLogic::update(const GameState &state, long delta) const
{
	if (state.elapsed > 400)
	{
		return jump(state);
	}

	return state
		.with_elapsed(state.elapsed + delta);
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
	return state
		.with_logic(&m_jumpingGameStateLogic)
		.with_player(state.player
			.with_target(state.player.x + state.elapsed)
			.with_source(state.player.x)
		);
}
