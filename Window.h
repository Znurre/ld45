#ifndef WINDOW_H
#define WINDOW_H

#include <QRasterWindow>
#include <QList>
#include <QElapsedTimer>

#include "IdleGameStateLogic.h"
#include "Player.h"
#include "Tile.h"
#include "GameState.h"

class Window : public QRasterWindow
{
	public:
		Window();

		// QPaintDeviceWindow interface
	protected:
		void paintEvent(QPaintEvent *event) override;

		void keyPressEvent(QKeyEvent *event) override;
		void keyReleaseEvent(QKeyEvent *event) override;

	private:
		QRectF getSourceRect(const Tile &tile);

		GameState createState() const;

		void drawPlayer(QPainter &painter);
		void drawPuddles(QPainter &painter);

		IdleGameStateLogic m_idleGameStateLogic;

		GameState m_state;

		QList<Tile> m_puddles;

		QElapsedTimer m_timer;

		int m_frames;
		int m_elapsed;
};

#endif // WINDOW_H
