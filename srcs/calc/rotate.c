#include "calc.h"

void	camera_rotate(t_camera *camera)
{
	camera->pos = vect_rotate(camera->pos, \
camera->normal_axis, camera->rotate_angle);
	camera->normal = vect_rotate(camera->normal, \
camera->normal_axis, camera->rotate_angle);
	camera->up = vect_rotate(camera->up, \
camera->normal_axis, camera->rotate_angle);
	camera->right = vect_rotate(camera->right, \
camera->normal_axis, camera->rotate_angle);
}
