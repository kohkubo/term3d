#include "calc.h"

static t_vect	screen_center(t_camera *camera, t_vect camera_normal)
{
	return (vect_add(camera->pos, vect_scalar_mul(camera_normal, \
FOCUS_DISTANCE)));
}

static t_vect	screen_right(t_vect *right, double pixel_x)
{
	return (vect_scalar_mul(*right, pixel_x));
}

static t_vect	screen_up(t_vect *up, double pixel_y)
{
	return (vect_scalar_mul(*up, pixel_y));
}

t_vect	camera_ray(t_camera *camera, int x, int y)
{
	double	pixel_x;
	double	pixel_y;
	t_vect	ret;

	pixel_x = (double)x / (double)WIDTH - 0.5;
	pixel_y = (double)y / (double)HEIGHT - 0.5;
	ret = vect_add(screen_center(camera, camera->normal), \
vect_add(\
screen_right(&camera->right, pixel_x), \
screen_up(&camera->up, pixel_y)));
	ret = vect_normalize(vect_sub(ret, camera->pos));
	return (ret);
}
