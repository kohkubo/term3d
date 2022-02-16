#include "draw.h"

static void	init_data(t_data *data)
{
	data->light = (t_light *)malloc(sizeof(t_light));
	data->light->pos = vect_new(0, 0, 0);
	data->light->range = vect_new(0, 0, 0);
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	data->camera->pos = vect_new(0, 0, -15);
	data->camera->lookat = vect_new(0, 0, 0);
	data->circle = (t_circle *)malloc(sizeof(t_circle));
	data->circle->center = vect_new(0, 0, 0);
	data->circle->normal = vect_new(0, 0, 1);
	data->circle->radius = 1;
	data->torus = (t_torus *)malloc(sizeof(t_torus));
	data->torus->center = vect_new(0, 0, 0);
	data->torus->normal = vect_new(0, 0, 0);
	data->torus->radius = 1;
	data->torus->tube_radius = 1;
}

t_vect camera_ray(t_camera *camera, int x, int y)
{
	double pixel_x = (double)x / (double)WIDTH - 0.5;
	double pixel_y = (double)y / (double)HEIGHT - 0.5;
	// カメラの方向
	t_vect camera_normal = vect_new(0, 0, 1);
	// 焦点距離は定数
	double focus_distance = 10;
	t_vect screen_center = vect_add(camera->pos, vect_scalar_mul(camera_normal, focus_distance));
	t_vect right = vect_new(1, 0, 0);
	t_vect up = vect_new(0, 1, 0);
	t_vect screen_right = vect_scalar_mul(right, pixel_x);
	t_vect screen_up = vect_scalar_mul(up, pixel_y);
	t_vect ret;
	ret = vect_add(screen_center, vect_scalar_mul(camera_normal, focus_distance));
	ret = vect_add(ret, vect_add(screen_right, screen_up));
	return (ret);
}

void	draw_point(t_data *data, int x, int y)
{
	data->camera->ray = camera_ray(data->camera, x, y);
	if (is_intersect_with_circle(data->camera, data->circle))
		printf(O);
	else
		printf(X);
}

static void	draw_loop(t_data *data)
{
	int	x;
	int	y;

	(void)data;
	printf(TOP_LEFT);
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			draw_point(data, x, y);
			// vect_print(data->camera->lookat);
			x++;
		}
		printf("\n");
		y++;
	}
	double camera_to_circle = vect_distance(data->camera->pos, data->circle->center);
	printf("camera_to_circle: %f\n", camera_to_circle);
	printf("camera pos");
	vect_print(data->camera->pos);
	printf("circle center");
	vect_print(data->circle->center);

}

void	draw(t_data *data)
{
	init_data(data);
	while (true)
	{
		draw_loop(data);
		// move_camera(data->camera);
		data->circle->normal = vect_rotate(data->circle->normal, vect_new(0, 1, 0), radian(2));
		double a = vect_angle(data->circle->normal, vect_new(0, 0, 1));
		printf("angle: %f\n", angle(a));
		printf("circle normal ");
		vect_print(data->circle->normal);
		usleep(50000);
	}
}
