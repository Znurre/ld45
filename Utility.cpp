#include "Utility.h"

QPointF bezier(const double x[], const double y[], double u)
{
	const double xu = pow(1 - u, 3) * x[0] + 3 * u * pow(1 - u, 2) * x[1] + 3 * pow(u, 2) * (1 - u) * x[2] + pow(u,3) * x[3];
	const double yu = pow(1 - u, 3) * y[0] + 3 * u * pow(1 - u, 2) * y[1] + 3 * pow(u, 2) * (1 - u) * y[2] + pow(u,3) * y[3];

	return QPointF(xu, yu);
}

int generateOffset()
{
	return qrand() % 400;
}
