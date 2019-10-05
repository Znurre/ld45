#include <QtMath>
#include <QDebug>

#include "JumpingGameStateLogic.h"
#include "IdleGameStateLogic.h"

void JumpingGameStateLogic::draw(const GameState &state, QPainter &painter) const
{
	Q_UNUSED(state)
	Q_UNUSED(painter)
}

GameState trySpawnPuddles(const GameState &state)
{
	if (state.puddles[0].x < (state.player.x - 1000))
	{
		PuddleStorage puddles = state.puddles;

		std::rotate(begin(puddles), begin(puddles) + 1, end(puddles));

		puddles[9] = Puddle()
			.with_x(puddles[8].right() + generateOffset());

		return state
			.with_puddles(puddles);
	}

	return state;
}

GameState JumpingGameStateLogic::update(const GameState &state, long delta) const
{
	if (state.player.x < state.player.target)
	{
		const auto source = state.player.source;
		const auto target = state.player.target;
		const auto distance = target  - source;

		const double x[4] = { source, source, target, target };
		const double y[4] = { 0, -200, -100, 0 };

		const auto position = bezier(x, y, (state.player.x - source) / distance);
		const auto adjustedDelta = delta * distance / (distance + 700);

		return state
			.with_player(state.player
				.with_x(qMin(target, state.player.x + adjustedDelta))
				.with_y(position.y())
			);
	}

	static IdleGameStateLogic logic;

	return trySpawnPuddles(state)
		.with_logic(&logic)
		.with_player(state.player
			.with_y(0)
		);
}

GameState JumpingGameStateLogic::keyPressEvent(const GameState &state, QKeyEvent *event) const
{
	Q_UNUSED(event)

	return state;
}

GameState JumpingGameStateLogic::keyReleaseEvent(const GameState &state, QKeyEvent *event) const
{
	Q_UNUSED(event)

	return state;
}
