#include "calc.h"

void	light_rotate(t_light *light, t_camera *camera)
{
	light->pos = vect_rotate(\
	light->pos, camera->normal_axis, camera->rotate_angle);
}

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
