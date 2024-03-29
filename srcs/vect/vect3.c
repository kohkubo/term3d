#include "vect.h"

double	vect_dot(const t_vect *vect1, const t_vect *vect2)
{
	return (vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z);
}

t_vect	vect_cross(const t_vect vect1, const t_vect vect2)
{
	return (vect_new(vect1.y * vect2.z - vect1.z * vect2.y, vect1.z * vect2.x \
				- vect1.x * vect2.z, vect1.x * vect2.y - vect1.y * vect2.x));
}

double	vect_len(const t_vect *vect)
{
	double	len;

	len = sqrt(vect_dot(vect, vect));
	if (isnan(len))
		return (0);
	return (len);
}

t_vect	vect_normalize(const t_vect vect)
{
	double	len;

	len = vect_len(&vect);
	return (vect_scalar_div(&vect, len));
}

double	vect_distance(const t_vect *vect1, const t_vect *vect2)
{
	t_vect	vect;

	vect = vect_sub(vect1, vect2);
	return (vect_len(&vect));
}
