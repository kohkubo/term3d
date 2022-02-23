#include "thread.h"

static void thread_draw_point(t_thread_line *line, int x, int y)
{
	t_object *hit;

	line->data.camera.ray = camera_ray(&line->data.camera, x, y);
	hit = intersect(&line->data);
	if (hit == NULL)
		line->buf[x] = ' ';
	else
		line->buf[x] = shading(&line->data.camera, &line->data.light, hit);
}

static void *thread_draw_line(void *arg)
{
	t_thread_line *line;
	int x;

	line = (t_thread_line *)arg;
	x = 0;
	while (x < line->data.camera.width)
		thread_draw_point(line, x++, line->y);
	return (NULL);
}

void thread_store_canvas(t_data *data)
{
	pthread_t thread[data->camera.height];
	t_thread_line line[data->camera.height];
	int y;

	y = 0;
	while (y < data->camera.height)
	{
		memcpy(&line[y].y, &y, sizeof(y));
		memcpy(&line[y].data, data, sizeof(*data));
		pthread_create(&thread[y], NULL, thread_draw_line, (void *)&line[y]);
		y++;
	}
	y = 0;
	while (y < data->camera.height)
	{
		pthread_join(thread[y], NULL);
		memcpy(&data->canvas[y * data->camera.width], line[y].buf, data->camera.width);
		y++;
	}
}
