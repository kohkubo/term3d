#include "draw.h"

static void	init_data(t_data *data)
{
	data->camera.pos = vect_new(0, 0, -150);
	data->camera.up = vect_new(0, 1, 0);
	data->camera.right = vect_new(1, 0, 0);
	data->camera.normal = vect_new(0, 0, -1);
	data->camera.normal_axis = vect_normalize(vect_new(1, 1, 1));
	data->camera.rotate_angle = radian(1);
	data->light.pos = vect_new(15, 15, -150);
	data->light.intensity = 1.0;
	data->intersect = is_intersect_with_triangle;
}

static int	intersect(t_data *data, int x, int y)
{
	int	i;

	data->camera.ray = camera_ray(&data->camera, x, y);
	i = 0;
	while (i < data->count)
	{
		if (data->intersect(&data->camera, &data->object[i]))
			return (i);
		i++;
	}
	return (-1);
}

static void	draw_point(t_data *data, int x, int y)
{
	int	c;

	c = intersect(data, x, y);
	if (c == -1)
		printf(X);
	else
		printf("%c ", shading(data, &data->object[c]));
}

static void	draw_screen(t_data *data)
{
	int		x;
	int		y;
	char	buf[BUFSIZ];

	setbuf(stdout, buf);
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
	fflush(stdout);
}

void	draw(t_data *data)
{
	init_data(data);
	while (true)
	{
		draw_screen(data);
		move_camera(&data->camera);
		camera_rotate(&data->camera);
		usleep(5000);
	}
}
