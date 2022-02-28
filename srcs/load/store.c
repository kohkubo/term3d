#include "load.h"

double	strtod_wrapper(char *str)
{
	char	*endptr;
	double	ret;

	if (!str)
		exit_error("strtod_wrapper: str is NULL");
	errno = 0;
	endptr = NULL;
	ret = strtod(str, &endptr);
	if (endptr == str)
		exit_error("strtod: No digits were found");
	if (*endptr != '\0')
		exit_error("strtod: Trailing characters after number");
	if (errno)
		exit_error("strtod: Conversion error");
	if (isnan(ret) || isinf(ret))
		exit_error("strtod: NAN or INF");
	return (ret);
}

t_vect	str_to_vector(char *position)
{
	t_vect	vect;
	char	**split;

	if (char_count(position, ',') != 2)
		exit_error("Invalid vector format");
	split = ft_split(position, ',');
	vect.x = strtod_wrapper(split[0]);
	vect.y = strtod_wrapper(split[1]);
	vect.z = strtod_wrapper(split[2]);
	free_string_array(split);
	return (vect);
}

static void	store_object_from_line(char *buf, t_object *obj)
{
	char	**position;

	position = ft_split(buf, ' ');
	if (arraylen(position) != 3)
		exit_error("Position are missing");
	obj->pos1 = str_to_vector(position[0]);
	obj->pos2 = str_to_vector(position[1]);
	obj->pos3 = str_to_vector(position[2]);
	free_string_array(position);
}

void	store_object_count_from_file(t_data *data, FILE *file)
{
	char	buf[TERM3D_LINE_SIZE + 1];

	data->object_count = 0;
	while (data->object_count < OBJECT_SIZE_MAX && read_line(file, buf))
		data->object_count++;
	if (!feof(file))
		exit_error("The number of objects described exceeds INT_MAX");
	if (data->object_count == 0)
		exit_error("No objects found");
	rewind(file);
}

void	store_object_from_file(t_data *data, FILE *file)
{
	char	buf[TERM3D_LINE_SIZE + 1];
	int		c;

	data->object = (t_object *)ft_xcalloc(data->object_count, sizeof(t_object));
	c = 0;
	while (c < data->object_count && read_line(file, buf))
		store_object_from_line(buf, &data->object[c++]);
	rewind(file);
}
