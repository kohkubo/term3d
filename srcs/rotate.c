#include "rotate.h"

#ifndef BENCH

static void	camera_rotate(t_data *data)
{
	data->camera.pos = vect_rotate(&data->camera.pos, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.normal = vect_rotate(&data->base_info.normal, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.up = vect_rotate(&data->base_info.up, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.right = vect_rotate(&data->base_info.right, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
}

#else

extern bool	g_draw_flg;

static void	camera_rotate(t_data *data)
{
	static int	rotate_count = 0;

	data->camera.pos = vect_rotate(&data->camera.pos, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.normal = vect_rotate(&data->base_info.normal, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.up = vect_rotate(&data->base_info.up, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.right = vect_rotate(&data->base_info.right, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	rotate_count++;
	if (rotate_count == 360)
	{
		g_draw_flg = false;
	}
}

#endif

void	rotate(t_data *data)
{
	if (data->base_info.rotate_angle == 0)
		return ;
	camera_rotate(data);
}
