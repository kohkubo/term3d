#include "draw.h"

static void	init_data(t_data *data)
{
	data->light = (t_light *)malloc(sizeof(t_light));
	data->light->pos = vect_new(0, 0, 0);
	data->light->range = vect_new(0, 0, 0);
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, 10);
	data->camera->normal = vect_new(0, 0, -1);
	data->camera->up = vect_new(0, 1, 0);
	data->camera->right = vect_new(1, 0, 0);
	data->camera->lookat = vect_new(0, 0, 0);
	data->camera->screen_dist = 10;
	data->camera->screen_center = vect_new(0, 0, 0);
	data->circle = (t_circle *)malloc(sizeof(t_circle));
	data->circle->normal = vect_new(0, 0, 1);
	data->circle->radius = 1;
	data->torus = (t_torus *)malloc(sizeof(t_torus));
	data->torus->center = vect_new(0, 0, 0);
	data->torus->normal = vect_new(0, 0, 0);
	data->torus->radius = 1;
	data->torus->tube_radius = 1;
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
