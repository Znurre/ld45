#ifndef CHARGEGAMESTATELOGIC_H
#define CHARGEGAMESTATELOGIC_H

#include "IGameStateLogic.h"
#include "JumpingGameStateLogic.h"

class Player;

class ChargeGameStateLogic : public IGameStateLogic
{
	public:
		void draw(const GameState &state, QPainter &painter) const override;

		GameState update(const GameState &state, long delta) const override;

		GameState keyPressEvent(const GameState &state, QKeyEvent *event) const override;
		GameState keyReleaseEvent(const GameState &state, QKeyEvent *event) const override;

	private:
		GameState jump(const GameState &state) const;

		JumpingGameStateLogic m_jumpingGameStateLogic;
};

#endif // CHARGEGAMESTATELOGIC_H
