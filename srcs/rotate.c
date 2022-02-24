#include "ray.h"

static void	light_rotate(t_camera *camera, t_light *light)
{
	light->pos = vect_rotate(\
	&light->pos, &camera->normal_axis, camera->rotate_angle);
}

static void	camera_rotate(t_camera *camera)
{
	camera->pos = vect_rotate(&camera->pos, \
&camera->normal_axis, camera->rotate_angle);
	camera->normal = vect_rotate(&camera->normal, \
&camera->normal_axis, camera->rotate_angle);
	camera->up = vect_rotate(&camera->up, \
&camera->normal_axis, camera->rotate_angle);
	camera->right = vect_rotate(&camera->right, \
&camera->normal_axis, camera->rotate_angle);
}

void	rotate(t_data *data)
{
	if (data->camera.rotate_angle == 0)
		return ;
	camera_rotate(&data->camera);
	light_rotate(&data->camera, &data->light);
}
