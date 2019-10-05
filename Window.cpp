#include "Window.h"
#include "Algorithms.h"

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
	painter.fillRect(event->rect(), Qt::black);
	painter.setPen(Qt::red);
	painter.translate(-(m_state.player.x - width() / 3), height() / 2);
	painter.drawLine(0, 0, width(), 0);

	if (m_timer.elapsed())
	{
		const long delta = m_timer.restart();

		m_state = m_state.logic->update(m_state, delta);

		m_frames++;

		if ((m_elapsed += delta)> 1000)
		{
			qDebug() << m_frames;

			m_frames = 0;
			m_elapsed = 0;
		}
	}

	m_state.logic->draw(m_state, painter);

	drawPuddles(painter);
	drawPlayer(painter);

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

Puddle createPuddle(int offset, const Puddle &previous)
{
	return Puddle()
		.with_x(previous.x + 50 + offset);
}

GameState Window::createState() const
{
	std::array<int, 10> offsets;
	std::generate(begin(offsets), end(offsets), generateOffset);

	PuddleStorage puddles;

	fold_transform(begin(offsets), end(offsets), begin(puddles), Puddle(), createPuddle);

	return GameState(&m_idleGameStateLogic)
		.with_puddles(puddles);
}

void Window::drawPlayer(QPainter &painter)
{
	painter.fillRect(m_state.player.x - 10, m_state.player.y - 10, 20, 20, Qt::red);
}

void Window::drawPuddles(QPainter &painter)
{
	for (const Puddle &puddle : m_state.puddles)
	{
		painter.setPen(Qt::blue);
		painter.drawLine(puddle.x, 0, puddle.right(), 0);
	}
}
