#include "Window.h"
#include "Algorithms.h"
#include "PuddleGenerator.h"

#include <QPainter>
#include <QDebug>

Window::Window()
	: m_state(createState())
	, m_frames(0)
	, m_elapsed(0)
{
	m_timer.start();
}

void Window::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.fillRect(event->rect(), QColor(24, 20, 37));
	painter.fillRect(0, height() / 2, width(), height() / 2, QColor(234, 212, 170));
	painter.translate(-(m_state.player.x - width() / 3), height() / 2);

	if (m_timer.elapsed())
	{
		const long delta = m_timer.restart();

		m_state = m_state.logic->update(m_state, delta);

		m_frames++;

		if ((m_elapsed += delta)> 1000)
		{
//			qDebug() << m_frames;

			m_frames = 0;
			m_elapsed = 0;
		}
	}

	drawPuddles(painter);

	m_state.logic->draw(m_state, painter);

	update();
}

void Window::keyPressEvent(QKeyEvent *event)
{
	if (event->isAutoRepeat())
	{
		return;
	}

	m_state = m_state.logic->keyPressEvent(m_state, event);
}

void Window::keyReleaseEvent(QKeyEvent *event)
{
	if (event->isAutoRepeat())
	{
		return;
	}

	m_state = m_state.logic->keyReleaseEvent(m_state, event);
}

Tile createPuddle(bool hasPuddle, const Tile &previous)
{
	return Tile()
		.with_index(previous.index + 1)
		.with_hasPuddle(hasPuddle);
}

GameState Window::createState() const
{
	std::array<bool, 20> offsets;
	std::generate(begin(offsets), end(offsets), &PuddleGenerator::generate);

	TileStorage puddles;

	const auto seed = Tile()
		.with_index(-10);

	fold_transform(begin(offsets), end(offsets), begin(puddles), seed, createPuddle);

	return GameState(&m_idleGameStateLogic)
		.with_tiles(puddles);
}

QRectF Window::getSourceRect(const Tile &tile)
{
	if (tile.hasPuddle)
	{
		if (m_state.player.x / 128 == tile.index &&
			m_state.player.y == 0 &&
			m_state.elapsed < 500)
		{
			return QRectF(384, 0, 128, 256);
		}

		return QRectF(256, 0, 128, 256);
	}

	return QRectF(128, 0, 128, 256);
}

void Window::drawPuddles(QPainter &painter)
{
	static const QImage image("ground.png");

	for (size_t i = 0; i < m_state.tiles.size(); i++)
	{
		const Tile &tile = m_state.tiles[i];

		const QRectF targetRect(tile.index * 128, -96, 128, 256);
		const QRectF sourceRect = getSourceRect(tile);

		painter.drawImage(targetRect, image, sourceRect);
	}
}
