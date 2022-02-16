#include "draw.h"

static void	init_data(t_data *data)
{
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, -15);
	data->camera->lookat = vect_new(0, 0, 0);
	data->circle[0].center = vect_new(0, 0, 0);
	data->circle[0].normal = vect_new(0, 0, 1);
	data->circle->radius = 1;
}

static void	draw_point(t_data *data, int x, int y)
{
	data->camera->ray = camera_ray(data->camera, x, y);
	if (is_intersect_with_circle(data->camera, data->circle))
		printf(O);
	else
		printf(X);
}

static void	draw_loop(t_data *data)
{
	int		x;
	int		y;
	double	camera_to_circle;

	printf(TOP_LEFT);
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			draw_point(data, x, y);
			x++;
		}
		printf("\n");
		y++;
	}
	camera_to_circle = vect_distance(data->camera->pos, data->circle->center);
	printf("camera_to_circle: %f\n", camera_to_circle);
	printf("camera pos");
	vect_print(data->camera->pos);
	printf("circle center");
	vect_print(data->circle->center);
}

void	draw(t_data *data)
{
	double	a;

	init_data(data);
	while (true)
	{
		draw_loop(data);
		data->circle->normal = vect_rotate(data->circle->normal, vect_new(0, 1,
					0), radian(2));
		a = vect_angle(data->circle->normal, vect_new(0, 0, 1));
		printf("angle: %f\n", degree(a));
		printf("circle normal ");
		vect_print(data->circle->normal);
		usleep(50000);
	}
}
