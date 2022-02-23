#include "draw.h"

static void	draw_screen(t_data *data, char *canvas)
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
			printf("%c ", canvas[y * data->camera.width + x++]);
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
		thread_store_canvas(data, canvas);
		draw_screen(data, canvas);
		move_camera(&data->camera);
		camera_rotate(&data->camera);
		light_rotate(&data->light, &data->camera);
	}
}
