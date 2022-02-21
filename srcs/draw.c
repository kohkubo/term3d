#include "draw.h"

static void	draw_point(t_data *data, int x, int y)
{
	int		i;

	data->camera.ray = camera_ray(&data->camera, x, y);
	i = 0;
	while (i < data->count)
	{
		if (data->intersect(&data->camera, &data->object[i]))
			break ;
		i++;
	}
	if (i != data->count)
		printf(O);
	else
		printf(X);
}

static void	draw_screen(t_data *data)
{
	int		x;
	int		y;
	char	buf[BUFSIZ];

	setbuf(stdout, buf);
	printf(TOP_LEFT);
	printf(DISABLE_CURSOR);
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			draw_point(data, x, y);
			x++;
		}
		printf("\n");
		y++;
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
		usleep(5000);
	}
}
