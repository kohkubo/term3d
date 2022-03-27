#include "thread.h"

static void	thread_draw_point(t_thread_line *line, int x, int y)
{
	t_object	*hit;
	double		radiance;
	char		c;

	set_camera_ray(&line->camera, &line->data->base_info, x, y);
	hit = intersect(line->data, &line->camera);
	if (hit == NULL)
		line->data->canvas[x + y * line->data->base_info.width] = ' ';
	else
	{
		radiance = shading(&line->camera, &line->data->light, hit);
		c = radiance_to_density(&line->data->config, radiance);
		line->data->canvas[x + y * line->data->base_info.width] = c;
	}
	line->data->canvas[x + 1 + y * line->data->base_info.width] = ' ';
}

static void	*thread_draw_line(void *arg)
{
	t_thread_line	*line;
	int				x;

	line = (t_thread_line *)arg;
	x = 0;
	while (x < line->data->base_info.width){
		thread_draw_point(line, x, line->y);
		x += 2;
	}
	line->data->canvas[line->data->base_info.width - 1 + line->y * line->data->base_info.width] = '\n';
	return (NULL);
}

static void	thread_error(t_thread_line *line, int y)
{
	int	i;

	i = 0;
	while (i < y)
		pthread_join(line[i++].thread, NULL);
	exit_error(NULL);
}

void	thread_store_canvas(t_data *data, t_thread_line *line)
{
	int	y;

	y = 0;
	while (y < data->base_info.height)
	{
		line[y].y = y;
		line[y].data = data;
		memcpy(&line[y].camera, &data->camera, sizeof(t_camera));
		if (pthread_create(\
		&line[y].thread, NULL, thread_draw_line, (void *)&line[y]) != 0)
			thread_error(line, y);
		y++;
	}
	y = 0;
	while (y < data->base_info.height)
		pthread_join(line[y++].thread, NULL);
}
