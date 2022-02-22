#include "init.h"

static t_vect	center_objects(t_data *data)
{
	t_vect	ret;
	int		i;

	i = 0;
	ret = vect_new(0, 0, 0);
	while (i < data->count)
	{
		ret = vect_add(ret, data->object[i].pos1);
		ret = vect_add(ret, data->object[i].pos2);
		ret = vect_add(ret, data->object[i].pos3);
		i++;
	}
	ret = vect_scalar_div(ret, (double)data->count * 3);
	return (ret);
}

static void	set_screen_size(t_data *data)
{
	struct winsize	ws;
	int				tmp;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != -1)
	{
		tmp = fmin(ws.ws_col, ws.ws_row) * 0.8;
		data->camera.width = tmp;
		data->camera.height = tmp;
	}
}

void	init_data(t_data *data)
{
	set_screen_size(data);
	data->camera.pos = vect_add(vect_new(0, 0, -150), center_objects(data));
	data->camera.up = vect_new(0, 1, 0);
	data->camera.right = vect_new(1, 0, 0);
	data->camera.normal = vect_new(0, 0, 1);
	data->camera.normal_axis = vect_normalize(vect_new(0, 1, 0));
	data->camera.rotate_angle = radian(1);
	data->light.pos = vect_new(150, 150, -150);
	data->light.intensity = 1.0;
	data->intersect = intersect_with_triangle_surface;
}
