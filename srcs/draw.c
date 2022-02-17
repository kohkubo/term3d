#include "draw.h"

static void	init_data(t_data *data)
{
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, -24);
	data->camera->lookat = vect_new(0, 0, 0);
	data->triangle[0].vert1 = vect_new(0, 2, 0);
	data->triangle[0].vert2 = vect_new(-2, -2, 0);
	data->triangle[0].vert3 = vect_new(2, -2, 0);
	data->triangle[0].normal = vect_new(0, 0, 1);
	data->circle->radius = 1;
}

static void	draw_point(t_data *data, int x, int y)
{
	int	i;

	data->camera->ray = camera_ray(data->camera, x, y);
	i = 0;
	while (i < data->count)
	{
		if (is_intersect_with_circle(data->camera, &data->circle[i]))
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
}

void	draw(t_data *data)
{
	int		i;

	init_data(data);
	while (true)
	{
		draw_loop(data);
		i = 0;
		while (i < data->count)
		{
			data->circle[i].normal = vect_rotate(\
				data->circle[i].normal, vect_new(0, 1, 0), radian(2));
			i++;
		}
		usleep(50000);
	}
}
