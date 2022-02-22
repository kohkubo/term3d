#include "draw.h"
#include <pthread.h>

void	draw_point(t_canvas *canvas, int x, int y)
{
	t_object	*hit;

	canvas->data.camera.ray = camera_ray(&canvas->data.camera, x, y);
	hit = intersect(&canvas->data);
	if (hit == NULL)
		canvas->line[x] = ' ';
	else
		canvas->line[x] = shading(\
		&canvas->data.camera, &canvas->data.light, hit);
}

void	*draw_line(void *arg)
{
	t_canvas	*canvas;
	int			x;

	canvas = (t_canvas *)arg;
	x = 0;
	while (x < WIDTH)
		draw_point(canvas, x++, canvas->y);
	return (NULL);
}

void	put_canvas(t_data *data)
{
	pthread_t	thread[HEIGHT];
	t_canvas	canvas[HEIGHT];
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		memcpy(&canvas[y].y, &y, sizeof(y));
		memcpy(&canvas[y].data, data, sizeof(*data));
		pthread_create(&thread[y], NULL, draw_line, (void *)&canvas[y]);
		y++;
	}
	y = 0;
	while (y < HEIGHT)
	{
		pthread_join(thread[y], NULL);
		memcpy(data->canvas[y], canvas[y].line, sizeof(canvas[y].line));
		y++;
	}
}

void	draw_screen(t_data *data)
{
	char	buf[BUFSIZ];
	int		x;
	int		y;

	setbuf(stdout, buf);
	printf(TOP_LEFT);
	printf(DISABLE_CURSOR);
	y = HEIGHT - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < WIDTH)
			printf("%c ", data->canvas[y][x++]);
		printf("\n");
		y--;
	}
	print_triangle_info(data);
	fflush(stdout);
}

void	draw(t_data *data)
{
	while (true)
	{
		put_canvas(data);
		draw_screen(data);
		move_camera(&data->camera);
		camera_rotate(&data->camera);
		light_rotate(&data->light, &data->camera);
	}
}
