#ifndef IDLEGAMESTATELOGIC_H
#define IDLEGAMESTATELOGIC_H

#include "ChargeGameStateLogic.h"
#include "IGameStateLogic.h"

class IdleGameStateLogic : public IGameStateLogic
{
	public:
		void draw(const GameState &state, QPainter &painter) const override;

		GameState update(const GameState &state, long delta) const override;

		GameState keyPressEvent(const GameState &state, QKeyEvent *event) const override;
		GameState keyReleaseEvent(const GameState &state, QKeyEvent *event) const override;

	private:
		ChargeGameStateLogic m_chargeGameStateLogic;
};

#endif // IDLEGAMESTATELOGIC_H
