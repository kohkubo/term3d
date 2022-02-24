#include "move.h"

void	camera_rotate_up(t_camera *camera)
{
	camera->normal_axis = vect_normalize(\
	vect_sub(&camera->normal_axis, &camera->right));
}

void	camera_rotate_down(t_camera *camera)
{
	camera->normal_axis = vect_normalize(\
	vect_add(camera->normal_axis, camera->right));
}

void	camera_rotate_left(t_camera *camera)
{
	camera->normal_axis = vect_normalize(\
	vect_sub(&camera->normal_axis, &camera->up));
}

void	camera_rotate_right(t_camera *camera)
{
	camera->normal_axis = vect_normalize(\
	vect_add(camera->normal_axis, camera->up));
}
