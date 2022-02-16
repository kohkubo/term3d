#include "camera.h"

static t_vect	screen_center(t_camera *camera, t_vect camera_normal)
{
	return (vect_add(camera->pos, vect_scalar_mul(camera_normal, \
FOCUS_DISTANCE)));
}

static t_vect	screen_right(double pixel_x)
{
	return (vect_scalar_mul(vect_new(1, 0, 0), pixel_x));
}

static t_vect	screen_up(double pixel_y)
{
	return (vect_scalar_mul(vect_new(0, 1, 0), pixel_y));
}

t_vect	camera_ray(t_camera *camera, int x, int y)
{
	double	pixel_x;
	double	pixel_y;
	t_vect	ret;
	t_vect	camera_normal;

	camera_normal = vect_new(0, 0, 1);
	pixel_x = (double)x / (double)WIDTH - 0.5;
	pixel_y = (double)y / (double)HEIGHT - 0.5;
	ret = vect_add(screen_center(camera, camera_normal), \
vect_add(screen_right(pixel_x), screen_up(pixel_y)));
	return (ret);
}
