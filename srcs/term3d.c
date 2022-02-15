#include "term3d.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static void	init_data(t_data *data)
{
	data->camera_pos = vect_new(0, 0, 10);
	data->light_pos = vect_new(0, 0, 0);
	data->light_range = vect_new(0, 0, 0);
	data->circle = (t_circle *)malloc(sizeof(t_circle));
	data->circle->circle_center = vect_new(0, 0, 10.4);
	data->circle->circle_normal = vect_normalize(vect_new(0, 0, 1));
	data->circle->circle_radius = 1;
	data->torus = (t_torus *)malloc(sizeof(t_torus));
	data->torus->torus_center = vect_new(0, 0, 0);
	data->torus->torus_normal = vect_new(0, 0, 0);
	data->torus->torus_radius = 0;
	data->torus->torus_tube_radius = 0;
}

static void	draw_screen(t_data *data)
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

static void	draw(t_data *data)
{
	while (true)
	{
		draw_screen(data);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("Usage: %s <filename>\n", av[0]);
		return (EXIT_FAILURE);
	}
	init_data(&data);
	draw(&data);
	return (EXIT_SUCCESS);
}
