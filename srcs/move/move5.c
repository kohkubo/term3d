#include "move.h"

void	camera_stop(t_camera *camera)
{
	camera->rotate_angle = radian(!camera->rotate_angle);
}

void	camera_reset(t_camera *camera)
{
	camera->pos = \
	vect_add(vect_new(0, 0, -150), camera->center_object_pos);
	camera->up = vect_new(0, 1, 0);
	camera->right = vect_new(1, 0, 0);
	camera->normal = vect_new(0, 0, 1);
	camera->normal_axis = vect_normalize(vect_new(0, 1, 0));
	camera->rotate_angle = radian(1);
}

void	quit(t_camera *camera)
{
	(void)camera;
	exit(EXIT_SUCCESS);
}
