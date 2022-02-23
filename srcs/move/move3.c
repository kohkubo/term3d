#include "move.h"

void	camera_rotate_right(t_camera *camera)
{
	camera->rotate_angle -= ROTATE_SPEED;
}

void	camera_rotate_up(t_camera *camera)
{
	camera->normal_axis = vect_normalize(\
	vect_add(camera->normal_axis, camera->right));
}

void	camera_rotate_down(t_camera *camera)
{
	camera->normal_axis = vect_normalize(\
	vect_sub(&camera->normal_axis, &camera->right));
}

void	camera_stop(t_camera *camera)
{
	camera->rotate_angle = 0;
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
