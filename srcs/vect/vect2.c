#include "vect.h"

t_vect	vect_mul(t_vect vect1, t_vect vect2)
{
	return (vect_new(vect1.x * vect2.x, vect1.y * vect2.y, vect1.z * vect2.z));
}

t_vect	vect_div(t_vect vect1, t_vect vect2)
{
	return (vect_new(vect1.x / vect2.x, vect1.y / vect2.y, vect1.z / vect2.z));
}

t_vect	vect_scalar_mul(t_vect vect, double scalar)
{
	return (vect_new(vect.x * scalar, vect.y * scalar, vect.z * scalar));
}

t_vect	vect_scalar_div(t_vect vect, double scalar)
{
	return (vect_new(vect.x / scalar, vect.y / scalar, vect.z / scalar));
}
