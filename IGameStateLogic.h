#ifndef IGAMESTATELOGIC_H
#define IGAMESTATELOGIC_H

#include <QKeyEvent>

#include "GameState.h"

class IGameStateLogic
{
	public:
		virtual ~IGameStateLogic() = default;

		virtual void draw(const GameState &state, QPainter &painter) const = 0;

		virtual GameState update(const GameState &state, long delta) const = 0;

		virtual GameState keyPressEvent(const GameState &state, QKeyEvent *event) const = 0;
		virtual GameState keyReleaseEvent(const GameState &state, QKeyEvent *event) const = 0;
};

#endif // IGAMESTATELOGIC_H
