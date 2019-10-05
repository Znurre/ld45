#ifndef UTILITY_H
#define UTILITY_H

#include <type_traits>
#include <memory>

#include <QPointF>
#include <QtMath>

#define PROPERTY(type, name)\
auto with_##name (type name) const\
{\
	std::decay_t<decltype(*this)> copy(std::move(*this));\
	copy. name = name ;\
\
	return copy;\
}\
\
type name;\

#define ARRAY_PROPERTY(type, name, size)\
auto with_##name (type name [size]) const\
{\
	std::decay_t<decltype(*this)> copy(std::move(*this));\
	copy. name = name ;\
\
	return copy;\
}\
\
type name;\

QPointF bezier(const double x[], const double y[], double u);

int generateOffset();

#endif // UTILITY_H
