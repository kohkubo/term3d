#include "load.h"

static double	strtod_wrapper(char *str)
{
	char	*endptr;
	double	d;

	if (!str)
		return (0);
	errno = 0;
	d = strtod(str, &endptr);
	if (isnan(d))
		exit_error("strtod: Nan is invalid.");
	if (errno == ERANGE)
		exit_error(NULL);
	if (*endptr != '\0')
		exit_error("strtod: Contains characters that cannot be converted.");
	if (d == HUGE_VAL)
		exit_error("strtod: An overflow has occurred.");
	return (d);
}

t_vect	str_to_vector(char *position)
{
	t_vect	vect;
	char	**split;

	if (char_count(position, ',') != 2)
		exit_error("Invalid vector format.");
	split = ft_split(position, ',');
	vect.x = strtod_wrapper(split[0]);
	vect.y = strtod_wrapper(split[1]);
	vect.z = strtod_wrapper(split[2]);
	free_string_array(split);
	return (vect);
}

static void	store_object_from_line(char *line, t_object *obj)
{
	char	**position;

	position = ft_split(line, ' ');
	if (arraylen(position) != 3)
		exit_error("Position are missing.");
	obj->pos1 = str_to_vector(position[0]);
	obj->pos2 = str_to_vector(position[1]);
	obj->pos3 = str_to_vector(position[2]);
	free_string_array(position);
}

void	store_object_count_from_file(t_data *data, FILE *file)
{
	char	line[TERM3D_LINE_SIZE + 1];

	data->count = 0;
	while (data->count < OBJECT_SIZE_MAX && read_line(file, line))
		data->count++;
	if (!feof(file))
		exit_error("The number of objects described exceeds INT_MAX");
	if (data->count == 0)
		exit_error("No objects found.");
	rewind(file);
}

void	store_object_from_file(t_data *data, FILE *file)
{
	char	line[TERM3D_LINE_SIZE + 1];
	int		c;

	data->object = (t_object *)ft_xcalloc(data->count, sizeof(t_object));
	c = 0;
	while (c < data->count && read_line(file, line))
		store_object_from_line(line, &data->object[c++]);
	rewind(file);
}
