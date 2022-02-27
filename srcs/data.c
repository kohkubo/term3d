#include "data.h"

bool	is_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

double	radian(double degree)
{
	return (degree * M_PI / 180.0);
}

double	degree(double radian)
{
	return (radian * 180.0 / M_PI);
}
