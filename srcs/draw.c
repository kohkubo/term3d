#include "draw.h"

static void	init_data(t_data *data)
{
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, -24);
	data->camera->lookat = vect_new(0, 0, 0);
	data->circle[0].center = vect_new(0, 0, 0);
	data->circle[0].normal = vect_new(0, 0, 1);
	data->triangle[0].vert1 = vect_new(0, 2, 0);
	data->triangle[0].vert2 = vect_new(-2, -2, 0);
	data->triangle[0].vert3 = vect_new(2, -2, 0);
	data->triangle[0].normal = vect_new(0, 0, 1);
	data->circle->radius = 1;
}

static void	draw_point(t_data *data, int x, int y)
{
	data->camera->ray = camera_ray(data->camera, x, y);
	if (is_intersect_with_triangle(data->camera, data->triangle))
		printf(O);
	else
		printf(X);
}

static void	draw_loop(t_data *data)
{
	int		x;
	int		y;

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
	print_triangle_info(data);
}

void	draw(t_data *data)
{
	init_data(data);
	while (true)
	{
		draw_loop(data);
		rotate_triangle(data);
		usleep(50000);
	}
}
