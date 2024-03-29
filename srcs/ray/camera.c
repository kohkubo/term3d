#include "ray.h"

static t_vect	screen_center(t_vect *camera_pos, t_vect *camera_normal)
{
	return (vect_add(*camera_pos, vect_scalar_mul(camera_normal, \
FOCUS_DISTANCE)));
}

static t_vect	screen_right(t_vect *right, double pixel_x)
{
	return (vect_scalar_mul(right, pixel_x));
}

static t_vect	screen_up(t_vect *up, double pixel_y)
{
	return (vect_scalar_mul(up, pixel_y));
}

void	set_camera_ray(t_camera *camera, t_base_info *base_info, int x, int y)
{
	double	pixel_x;
	double	pixel_y;

	pixel_x = (double)x / (double)base_info->width - 0.5;
	pixel_y = (double)y / (double)base_info->height - 0.5;
	camera->ray_dir_normal = \
	vect_add(screen_center(&camera->pos, &base_info->normal), vect_add(\
	screen_right(&base_info->right, pixel_x), \
	screen_up(&base_info->up, pixel_y)));
	camera->ray_dir_normal = \
	vect_normalize(vect_sub(&camera->ray_dir_normal, &camera->pos));
}
