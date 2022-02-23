#include "draw.h"

static void	draw_screen(t_data *data)
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
			printf("%c ", data->canvas[y * data->camera.width + x++]);
		printf("\n");
		y--;
	}
	fflush(stdout);
}

void	draw(t_data *data)
{
	while (true)
	{
		thread_store_canvas(data);
		draw_screen(data);
		move_camera(&data->camera);
		camera_rotate(&data->camera);
		light_rotate(&data->light, &data->camera);
	}
}
