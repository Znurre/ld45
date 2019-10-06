#include "Window.h"

#include <QFontDatabase>
#include <QGuiApplication>

int main(int argc, char **argv)
{
	QGuiApplication application(argc, argv);

	QFontDatabase fontDatabase;
	fontDatabase.addApplicationFont(":/fonts/resources/font.ttf");

	Window window;
	window.setMaximumSize(QSize(1280, 720));
	window.setMinimumSize(QSize(1280, 720));
	window.show();

	return application.exec();
}
