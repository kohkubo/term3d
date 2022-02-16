#include "draw.h"

static void	init_data(t_data *data)
{
	data->light = (t_light *)malloc(sizeof(t_light));
	data->light->pos = vect_new(0, 0, 0);
	data->light->range = vect_new(0, 0, 0);
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, -1);
	data->camera->lookat = vect_new(0, 0, 0);
	data->circle = (t_circle *)malloc(sizeof(t_circle));
	data->circle->center = vect_new(0, 0, 0);
	data->circle->normal = vect_new(0, 0, 1);
	data->circle->radius = 1;
	data->torus = (t_torus *)malloc(sizeof(t_torus));
	data->torus->center = vect_new(0, 0, 0);
	data->torus->normal = vect_new(0, 0, 0);
	data->torus->radius = 1;
	data->torus->tube_radius = 1;
}

t_vect camera_ray(t_camera *camera, int x, int y)
{
	t_vect screen_pixel = vect_new(x, y, camera->pos.z + 10);
	return (vect_normalize(vect_sub(screen_pixel, camera->pos)));
}

void	draw_point(t_data *data, int x, int y)
{
	data->camera->ray = camera_ray(data->camera, x, y);
	if (is_intersect_with_circle(data->camera, data->circle))
		printf(O);
	else
		printf(X);
}

static void	draw_loop(t_data *data)
{
	int	x;
	int	y;

	(void)data;
	printf(TOP_LEFT);
	y = TOP;
	while (y >= BOTTOM)
	{
		x = LEFT;
		while (x <= RIGHT)
		{
			draw_point(data, x, y);
			x++;
		}
		printf("\n");
		y--;
	}
	double camera_to_circle = vect_distance(data->camera->pos, data->circle->center);
	printf("camera_to_circle: %f\n", camera_to_circle);
	printf("camera pos");
	vect_print(data->camera->pos);
	printf("circle center");
	vect_print(data->circle->center);

}

void	draw(t_data *data)
{
	t_vect   tmp = vect_normalize(vect_new(0, 1, 0));
	init_data(data);
	while (true)
	{
		draw_loop(data);
		// move_camera(data->camera);
		data->circle->normal = vect_rotate(data->circle->normal, tmp, radian(1));
		vect_print(data->circle->normal);
		usleep(50000);
	}
}
