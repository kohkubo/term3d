#include "draw.h"

static void	init_data(t_data *data)
{
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, 10);
	data->camera->lookat = vect_new(0, 0, 0);
}

static void	draw_loop(t_data *data)
{
	int	x;
	int	y;

	(void)data;
	printf(TOP_LEFT);
	y = TOP;
	while (y >= BOTTOM)
	{
		x = LEFT;
		while (x <= RIGHT)
		{
			if (true)
				printf(O);
			else
				printf(X);
			x++;
		}
		printf("%d, %d   ", y, x);
		printf("\n");
		y--;
	}
}

void	draw(t_data *data)
{
	init_data(data);
	while (true)
	{
		draw_loop(data);
		usleep(50000);
	}
}
