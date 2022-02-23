#include "draw.h"
#include <pthread.h>

void	draw_point(t_thread_line *line, int x, int y)
{
	t_object	*hit;

	line->data.camera.ray = camera_ray(&line->data.camera, x, y);
	hit = intersect(&line->data);
	if (hit == NULL)
		line->buf[x] = ' ';
	else
		line->buf[x] = shading(\
		&line->data.camera, &line->data.light, hit);
}

void	*draw_line(void *arg)
{
	t_thread_line	*line;
	int				x;

	line = (t_thread_line *)arg;
	x = 0;
	while (x < WIDTH)
		draw_point(line, x++, line->y);
	return (NULL);
}

void	put_thread_canvas(t_data *data, char *canvas)
{
	pthread_t		thread[HEIGHT];
	t_thread_line	line[HEIGHT];
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		memcpy(&line[y].y, &y, sizeof(y));
		memcpy(&line[y].data, data, sizeof(*data));
		pthread_create(&thread[y], NULL, draw_line, (void *)&line[y]);
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

void	draw_screen(t_data *data, char *canvas)
{
	char	buf[BUFSIZ];
	int		x;
	int		y;

	setbuf(stdout, buf);
	printf(TOP_LEFT);
	printf(DISABLE_CURSOR);
	y = data->camera.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->camera.width)
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
	char	canvas[HEIGHT * WIDTH];

	while (true)
	{
		put_thread_canvas(data, canvas);
		draw_screen(data, canvas);
		move_camera(&data->camera);
		camera_rotate(&data->camera);
		light_rotate(&data->light, &data->camera);
	}
}
