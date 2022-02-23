#include "vect.h"

void	vect_print(const t_vect vect)
{
	printf("%16f, %16f, %16f\n", vect.x, vect.y, vect.z);
}

t_vect	vect_new(double x, double y, double z)
{
	t_vect	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vect	vect_add(const t_vect a, const t_vect b)
{
	return (vect_new(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vect	vect_sub(const t_vect *a, const t_vect *b)
{
	return (vect_new(a->x - b->x, a->y - b->y, a->z - b->z));
}
