#include "draw.h"

static void	init_data(t_data *data)
{
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, -15);
	if (data->type == CIRCLE)
	{
		data->intersect = is_intersect_with_circle;
		data->rotate = rotate_circle;
	}
	if (data->type == TRIANGLE)
	{
		data->intersect = is_intersect_with_triangle;
		data->rotate = rotate_triangle;
	}
}

static void	draw_point(t_data *data, int x, int y)
{
	int		i;

	data->camera->ray = camera_ray(data->camera, x, y);
	i = 0;
	while (i < data->count)
	{
		if (data->intersect(data->camera, &data->object[i]))
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
			data->rotate(&data->object[i]);
			i++;
		}
		usleep(50000);
	}
}
