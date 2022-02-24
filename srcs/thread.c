#include "thread.h"

static void	thread_draw_point(t_thread_line *line, int x, int y)
{
	t_object	*hit;
	double		radiance;
	char		c;

	line->data.camera.ray = camera_ray(&line->data.camera, x, y);
	hit = intersect(&line->data);
	if (hit == NULL)
		line->data.canvas[x + y * line->data.camera.width] = ' ';
	else
	{
		radiance = shading(&line->data.camera, &line->data.light, hit);
		c = radiance_to_density(&line->data.config, radiance);
		line->data.canvas[x + y * line->data.camera.width] = c;
	}
}

static void	*thread_draw_line(void *arg)
{
	t_thread_line	*line;
	int				x;

	line = (t_thread_line *)arg;
	x = 0;
	while (x < line->data.camera.width)
		thread_draw_point(line, x++, line->y);
	return (NULL);
}

void	thread_store_canvas(t_data *data, t_thread_line *line)
{
	int	y;

	y = 0;
	while (y < data->camera.height)
	{
		memcpy(&line[y].y, &y, sizeof(y));
		memcpy(&line[y].data, data, sizeof(*data));
		pthread_create(\
		&line[y].thread, NULL, thread_draw_line, (void *)&line[y]);
		y++;
	}
	y = 0;
	while (y < data->camera.height)
	{
		pthread_join(line[y].thread, NULL);
		y++;
	}
}
