#include "init.h"

static t_vect	center_objects(t_data *data)
{
	t_vect	ret;
	int		i;

	i = 0;
	ret = vect_new(0, 0, 0);
	while (i < data->count)
	{
		ret.x += data->object[i].pos1.x;
		ret.y += data->object[i].pos1.y;
		ret.z += data->object[i].pos1.z;
		ret.x += data->object[i].pos2.x;
		ret.y += data->object[i].pos2.y;
		ret.z += data->object[i].pos2.z;
		ret.x += data->object[i].pos3.x;
		ret.y += data->object[i].pos3.y;
		ret.z += data->object[i].pos3.z;
		i++;
	}
	ret.x /= (data->count * 3);
	ret.y /= (data->count * 3);
	ret.z /= (data->count * 3);
	return (ret);
}

void	init_data(t_data *data)
{
	data->camera.pos = vect_add(vect_new(0, 0, -150), center_objects(data));
	data->camera.up = vect_new(0, 1, 0);
	data->camera.right = vect_new(1, 0, 0);
	data->camera.normal = vect_new(0, 0, -1);
	data->camera.normal_axis = vect_normalize(vect_new(1, 1, 1));
	data->camera.rotate_angle = radian(1);
	data->intersect = is_intersect_with_triangle;
}
