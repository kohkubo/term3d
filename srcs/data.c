#include "data.h"

bool	is_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

bool	less(double a, double b)
{
	if (a < b - EPSILON)
		return (true);
	return (false);
}

bool	less_equal(double a, double b)
{
	return (less(a, b) || is_equal(a, b));
}

double	radian(double degree)
{
	return (degree * M_PI / 180.0);
}

double	degree(double radian)
{
	return (radian * 180.0 / M_PI);
}
