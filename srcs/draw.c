#include "draw.h"

static void	init_data(t_data *data)
{
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, -15);
	data->camera->lookat = vect_new(0, 0, 0);
}

static void	draw_point(t_data *data, int x, int y)
{
	int	i;

	data->camera->ray = camera_ray(data->camera, x, y);
	i = 0;
	while (i < data->count)
	{
		if (data->type == CIRCLE)
			if (is_intersect_with_circle(data->camera, &data->circle[i]))
				break ;
		if (data->type == TRIANGLE)
			if (is_intersect_with_triangle(data->camera, &data->triangle[i]))
				break ;
		i++;
	}
	if (i != data->count)
		printf(O);
	else
		printf(X);
}

static void	draw_loop(t_data *data)
{
	int	x;
	int	y;

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
}

void	draw(t_data *data)
{
	int	i;

	init_data(data);
	while (true)
	{
		draw_loop(data);
		i = 0;
		while (i < data->count)
		{
			if (data->type == CIRCLE)
				rotate_circle(&data->circle[i]);
			if (data->type == TRIANGLE)
				rotate_triangle(&data->triangle[i]);
			i++;
		}
		usleep(50000);
	}
}
