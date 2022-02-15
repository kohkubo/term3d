#include "vect.h"

void	vect_print(t_vect vect)
{
	printf("%f, %f, %f\n", vect.x, vect.y, vect.z);
}

t_vect	vect_new(double x, double y, double z)
{
	t_vect	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vect	vect_dup(t_vect vect)
{
	return (vect_new(vect.x, vect.y, vect.z));
}

t_vect	vect_add(t_vect vect1, t_vect vect2)
{
	return (vect_new(vect1.x + vect2.x, vect1.y + vect2.y, vect1.z + vect2.z));
}

t_vect	vect_sub(t_vect vect1, t_vect vect2)
{
	return (vect_new(vect1.x - vect2.x, vect1.y - vect2.y, vect1.z - vect2.z));
}
