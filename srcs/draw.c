#include "draw.h"

static void	init_data(t_data *data)
{
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, -15);
	data->camera->lookat = vect_new(0, 0, 0);
}

static void	draw_point(t_data *data, int x, int y)
{
	int	i;

	data->camera->ray = camera_ray(data->camera, x, y);
	i = 0;
	while (i < data->count)
	{
		if (is_intersect_with_circle(data->camera, &data->circle[i]))
			break ;
		i++;
	}
	if (i != data->count)
		printf(O);
	else
		printf(X);
}

static void	draw_loop(t_data *data)
{
	int		x;
	int		y;

	printf(TOP_LEFT);
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
	printf("camera pos");
	vect_print(data->camera->pos);
	printf("circle center");
	vect_print(data->circle->center);
}

void	draw(t_data *data)
{
	int		i;
	double	a;
	double	camera_to_circle;

	init_data(data);
	while (true)
	{
		draw_loop(data);
		i = 0;
		while (i < data->count)
		{
			data->circle[i].normal = vect_rotate(\
				data->circle[i].normal, vect_new(0,1,0), radian(2));
			camera_to_circle = vect_distance(\
				data->camera->pos, data->circle[i].center);
			printf("camera_to_circle: %f\n", camera_to_circle);
			a = vect_angle(data->circle[i].normal, vect_new(0, 0, 1));
			printf("angle: %f\n", degree(a));
			printf("circle normal ");
			vect_print(data->circle[i].normal);
			i++;
		}
		usleep(50000);
	}
}
