#include "thread.h"

static void	thread_draw_point(t_thread_line *line, int x, int y)
{
	t_object	*hit;

	line->data.camera.ray = camera_ray(&line->data.camera, x, y);
	hit = intersect(&line->data);
	if (hit == NULL)
		line->buf[x] = ' ';
	else
		line->buf[x] = shading(&line->data.camera, &line->data.light, hit);
}

static void	*thread_draw_line(void *arg)
{
	t_thread_line	*line;
	int				x;

	line = (t_thread_line *)arg;
	x = 0;
	while (x < WIDTH)
		thread_draw_point(line, x++, line->y);
	return (NULL);
}

void	thread_store_canvas(t_data *data, char *canvas)
{
	pthread_t		thread[HEIGHT];
	t_thread_line	line[HEIGHT];
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		memcpy(&line[y].y, &y, sizeof(y));
		memcpy(&line[y].data, data, sizeof(*data));
		pthread_create(&thread[y], NULL, thread_draw_line, (void *)&line[y]);
		y++;
	}
	y = 0;
	while (y < HEIGHT)
	{
		pthread_join(thread[y], NULL);
		memcpy(&canvas[y * WIDTH], line[y].buf, sizeof(line[y].buf));
		y++;
	}
}
