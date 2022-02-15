#include "data.h"

/*
最大制度 DBL_EPSILON
kawadaさんがEPSILONは 0.000001 くらいがいいって言ってた
*/
#define EPSILON 0.000001

bool	is_equal(double a, double b)
{
	return (fabs(a - b) <= EPSILON * fmax(1.0, fmax(fabs(a), fabs(b))));
}

bool	less(double a, double b)
{
	return (a - b < -EPSILON * fmax(1.0, fmax(fabs(a), fabs(b))));
}

bool	less_equal(double a, double b)
{
	return (less(a, b) || is_equal(a, b));
}

double	radian(double degree)
{
	return (degree * M_PI / 180.0);
}
