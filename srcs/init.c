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

void	init_data(t_data *data)
{
	data->camera.pos = vect_add(vect_new(0, 0, -150), center_objects(data));
	data->camera.up = vect_new(0, 1, 0);
	data->camera.right = vect_new(1, 0, 0);
	data->camera.normal = vect_new(0, 0, 1);
	data->camera.normal_axis = vect_normalize(vect_new(1, 1, 1));
	data->camera.rotate_angle = radian(1);
	data->light.pos = vect_new(15, 15, -150);
	data->light.intensity = 1.0;
	data->intersect = intersect_with_triangle;
}
