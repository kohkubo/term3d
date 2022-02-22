#include "draw.h"

static t_object	*intersect(t_data *data)
{
	int			i;
	double		shortest;
	double		t;
	t_object	*hit;

	t = DBL_MAX;
	hit = NULL;
	i = 0;
	while (i < data->count)
	{
		shortest = t;
		t = update_t(t, data->intersect(&data->camera, &data->object[i]));
		if (t < shortest)
			hit = &data->object[i];
		i++;
	}
	data->camera.lookat = vect_add(\
	data->camera.pos, vect_scalar_mul(&data->camera.ray, t));
	return (hit);
}

static void	draw_point(t_data *data, int x, int y)
{
	t_object	*hit;

	data->camera.ray = camera_ray(&data->camera, x, y);
	hit = intersect(data);
	if (hit == NULL)
		printf(X);
	else
		printf("%c ", shading(&data->camera, &data->light, hit));
}

static void	draw_screen(t_data *data)
{
	int		x;
	int		y;
	char	buf[BUFSIZ];

	setbuf(stdout, buf);
	printf(TOP_LEFT);
	printf(DISABLE_CURSOR);
	y = data->camera.height;
	while (y >= 0)
	{
		x = 0;
		while (x <= data->camera.width)
		{
			draw_point(data, x, y);
			x++;
		}
		printf("\n");
		y--;
	}
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
		light_rotate(&data->light, &data->camera);
		usleep(5000);
	}
}
