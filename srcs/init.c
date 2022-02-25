#include "init.h"

static t_vect	center_objects(t_data *data)
{
	t_vect	ret;
	int		i;

	i = 0;
	ret = vect_new(0, 0, 0);
	while (i < data->object_count)
	{
		ret = vect_add(ret, data->object[i].pos1);
		ret = vect_add(ret, data->object[i].pos2);
		ret = vect_add(ret, data->object[i].pos3);
		i++;
	}
	ret = vect_scalar_div(&ret, (double)data->object_count * 3);
	return (ret);
}

static void	set_screen_size(t_data *data)
{
	struct winsize	ws;
	int				tmp;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != -1)
	{
		tmp = fmin(ws.ws_col, ws.ws_row) * 0.8;
		data->base_info.width = tmp;
		data->base_info.height = tmp;
	}
}

static void	preprocess_triangle(t_data *data)
{
	int			i;
	t_object	*object;

	i = 0;
	while (i < data->object_count)
	{
		object = &data->object[i];
		object->edge1 = vect_sub(&object->pos2, &object->pos1);
		object->edge2 = vect_sub(&object->pos3, &object->pos1);
		object->edge3 = vect_sub(&object->pos3, &object->pos2);
		object->normal = vect_normalize(\
		vect_cross(object->edge1, object->edge2));
		i++;
	}
}

void	init_base_info(t_data *data)
{
	data->camera.pos = vect_add(\
	vect_new(0, 0, -150), data->base_info.center_object_pos);
	data->base_info.up = vect_new(0, 1, 0);
	data->base_info.right = vect_new(1, 0, 0);
	data->base_info.normal = vect_new(0, 0, 1);
	data->base_info.normal_axis = vect_normalize(vect_new(0, 1, 0));
	data->base_info.rotate_angle = radian(1);
	data->light.pos = vect_new(150, 150, -150);
	data->light.intensity = 1.0;
	data->intersect = intersect_with_triangle_surface;
}

void	init_data(t_data *data)
{
	preprocess_triangle(data);
	set_screen_size(data);
	data->base_info.center_object_pos = center_objects(data);
	init_base_info(data);
	data->canvas = (char *)ft_xcalloc(\
	data->base_info.width * data->base_info.height, sizeof(char));
	receiver(end_handler);
}
