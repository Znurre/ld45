#include "Resources.h"

QFont Resources::font()
{
	static QFont font("pix PixelFJVerdana12pt", 12);

	return font;
}

QImage Resources::ground()
{
	static QImage image(":/images/resources/ground.png");

	return image;
}

QImage Resources::idle()
{
	static QImage image(":/images/resources/idle.png");

	return image;
}

QImage Resources::charging()
{
	static QImage image(":/images/resources/charge.png");

	return image;
}

QImage Resources::jumping()
{
	static QImage image(":/images/resources/jumping.png");

	return image;
}

QImage Resources::falling()
{
	static QImage image(":/images/resources/falling.png");

	return image;
}
