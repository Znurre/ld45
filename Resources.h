#ifndef RESOURCES_H
#define RESOURCES_H

#include <QImage>
#include <QFont>

class Resources
{
	public:
		static QFont font();

		static QImage ground();
		static QImage idle();
		static QImage charging();
		static QImage jumping();
		static QImage falling();
};

#endif // RESOURCES_H
