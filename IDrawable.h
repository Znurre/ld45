#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <QPainter>

class IDrawable
{
	public:
		virtual void draw(QPainter &painter) const = 0;
};

#endif // IDRAWABLE_H
