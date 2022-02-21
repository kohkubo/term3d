#include "draw.h"
#include <pthread.h>

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
	data->camera.pos, vect_scalar_mul(data->camera.ray, t));
	return (hit);
}

static void	draw_point(t_data *data, int x, int y)
{
	t_object	*hit;

	data->camera.ray = camera_ray(&data->camera, x, y);
	hit = intersect(data);
	if (hit == NULL)
		data->canvas[y][x] = ' ';
	else
		data->canvas[y][x] = shading(&data->camera, &data->light, hit);
}

static void *draw_line(void *arg)
{
	t_data *data = (t_data *)arg;

	for (int x = 0; x < WIDTH; x++)
		draw_point(data, x, data->y);
	return (NULL);
}

static void	draw_screen(t_data *data)
{
	char		buf[BUFSIZ];
	pthread_t	thread[HEIGHT];

	setbuf(stdout, buf);
	printf(TOP_LEFT);
	printf(DISABLE_CURSOR);
	for (int y = 0; y < HEIGHT; y++)
	{
		data->y = y;
		pthread_create(&thread[y], NULL, draw_line, (void *)data);
	}
	for (int y = 0; y < HEIGHT; y++)
		pthread_join(thread[y], NULL);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
			printf("%c ", data->canvas[y][x]);
		printf("\n");
	}
	print_triangle_info(data);
	fflush(stdout);
}

void	draw(t_data *data)
{
	while (true)
	{
		draw_screen(data);
		move_camera(&data->camera);
		camera_rotate(&data->camera);
		light_rotate(&data->light, &data->camera);
	}
}
