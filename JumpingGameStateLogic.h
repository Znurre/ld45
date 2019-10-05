#ifndef JUMPINGGAMESTATELOGIC_H
#define JUMPINGGAMESTATELOGIC_H

#include "IGameStateLogic.h"

class Player;

class JumpingGameStateLogic : public IGameStateLogic
{
	public:
		void draw(const GameState &state, QPainter &painter) const override;

		GameState update(const GameState &state, long delta) const override;

		GameState keyPressEvent(const GameState &state, QKeyEvent *event) const override;
		GameState keyReleaseEvent(const GameState &state, QKeyEvent *event) const override;
};

#endif // JUMPINGGAMESTATELOGIC_H
