#include "vect.h"

t_vect	vect_inv(t_vect vect)
{
	return (vect_new(-vect.x, -vect.y, -vect.z));
}

t_vect	vect_rotate(t_vect vect, t_vect axis, double angle)
{
	t_vect	ret;
	double	x_rot;
	double	y_rot;
	double	z_rot;

	x_rot = axis.x * axis.x * (1 - cos(angle)) + cos(angle);
	y_rot = axis.x * axis.y * (1 - cos(angle)) - axis.z * sin(angle);
	z_rot = axis.z * axis.x * (1 - cos(angle)) + axis.y * sin(angle);
	ret.x = x_rot * vect.x + y_rot * vect.y + z_rot * vect.z;
	x_rot = axis.y * axis.x * (1 - cos(angle)) + axis.z * sin(angle);
	y_rot = axis.y * axis.y * (1 - cos(angle)) + cos(angle);
	z_rot = axis.y * axis.z * (1 - cos(angle)) - axis.x * sin(angle);
	ret.y = x_rot * vect.x + y_rot * vect.y + z_rot * vect.z;
	x_rot = axis.z * axis.x * (1 - cos(angle)) - axis.y * sin(angle);
	y_rot = axis.z * axis.y * (1 - cos(angle)) + axis.x * sin(angle);
	z_rot = axis.z * axis.z * (1 - cos(angle)) + cos(angle);
	ret.z = x_rot * vect.x + y_rot * vect.y + z_rot * vect.z;
	return (ret);
}

double	vect_det(t_vect vect1, t_vect vect2, t_vect vect3)
{
	double	tmp;

	tmp = (vect1.x * vect2.y * vect3.z + vect1.y * vect2.z * vect3.x + vect1.z
			* vect2.x * vect3.y);
	tmp -= (vect1.x * vect2.z * vect3.y + vect1.y * vect2.x * vect3.z + vect1.z
			* vect2.y * vect3.x);
	return (tmp);
}

double	vect_angle(t_vect vect1, t_vect vect2)
{
	double	tmp;

	tmp = vect_len(vect1) * vect_len(vect2);
	if (tmp == 0)
		return (0);
	return (acos(vect_dot(vect1, vect2) / tmp));
}

bool	is_right_angle(t_vect vect1, t_vect vect2)
{
	return (is_equal(vect_dot(vect1, vect2), 0));
}
