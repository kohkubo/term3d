#include "vect.h"

t_vect	vect_inv(t_vect vect)
{
	return (vect_new(-vect.x, -vect.y, -vect.z));
}

t_vect	vect_rotate(t_vect vect, t_vect axis, double radian)
{
	t_vect	ret;
	double	x_rot;
	double	y_rot;
	double	z_rot;

	x_rot = axis.x * axis.x * (1 - cos(radian)) + cos(radian);
	y_rot = axis.x * axis.y * (1 - cos(radian)) - axis.z * sin(radian);
	z_rot = axis.z * axis.x * (1 - cos(radian)) + axis.y * sin(radian);
	ret.x = x_rot * vect.x + y_rot * vect.y + z_rot * vect.z;
	x_rot = axis.y * axis.x * (1 - cos(radian)) + axis.z * sin(radian);
	y_rot = axis.y * axis.y * (1 - cos(radian)) + cos(radian);
	z_rot = axis.y * axis.z * (1 - cos(radian)) - axis.x * sin(radian);
	ret.y = x_rot * vect.x + y_rot * vect.y + z_rot * vect.z;
	x_rot = axis.z * axis.x * (1 - cos(radian)) - axis.y * sin(radian);
	y_rot = axis.z * axis.y * (1 - cos(radian)) + axis.x * sin(radian);
	z_rot = axis.z * axis.z * (1 - cos(radian)) + cos(radian);
	ret.z = x_rot * vect.x + y_rot * vect.y + z_rot * vect.z;
	return (ret);
}

double	vect_det(t_vect a, t_vect b, t_vect c)
{
	double	tmp;

	tmp = ((a.x * b.y * c.z) + (a.y * b.z * c.x) + (a.z * b.x * c.y));
	tmp -= ((a.x * b.z * c.y) + (a.y * b.x * c.z) + (a.z * b.y * c.x));
	return (tmp);
}

double	vect_angle_radian(t_vect vect1, t_vect vect2)
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
