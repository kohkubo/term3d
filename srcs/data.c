#include "data.h"

/*
最大制度 DBL_EPSILON
kawadaさんがEPSILONは 0.000001 くらいがいいって言ってた
*/
#define EPSILON 0.000001

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

double	angle(double radian)
{
	return (radian * 180.0 / M_PI);
}
