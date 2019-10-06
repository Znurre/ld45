#include <QtMath>
#include <QDebug>
#include <QImage>
#include <QPainter>

#include "JumpingGameStateLogic.h"
#include "IdleGameStateLogic.h"
#include "PuddleGenerator.h"

void JumpingGameStateLogic::draw(const GameState &state, QPainter &painter) const
{
	Q_UNUSED(state)
	Q_UNUSED(painter)

	static const QImage jumping("jumping.png");
	static const QImage falling("falling.png");

	const QRectF targetRect(state.player.x, state.player.y - 128, 128, 128);
	const QRectF sourceRect(0, 0, 128, 128);

	if (state.player.f > 0.5)
	{
		painter.drawImage(targetRect, falling, sourceRect);
	}
	else
	{
		painter.drawImage(targetRect, jumping, sourceRect);
	}
}

GameState trySpawnPuddles(const GameState &state)
{
	const long tilesToGenerate = long(state.player.target - state.player.source) / 128;

	TileStorage tiles = state.tiles;

	std::rotate(begin(tiles), begin(tiles) + tilesToGenerate, end(tiles));

	for (auto i = end(tiles) - tilesToGenerate
		; i != end(tiles)
		; i++)
	{
		*i = Tile()
			.with_index((i - 1)->index + 1)
			.with_hasPuddle(PuddleGenerator::generate());
	}

	return state
		.with_tiles(tiles);
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
				.with_f(position.y() - state.player.y)
				.with_y(position.y())
			);
	}

	static IdleGameStateLogic logic;

	return trySpawnPuddles(state)
		.with_logic(&logic)
		.with_elapsed(0)
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
