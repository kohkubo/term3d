#include "load.h"

static void	store_split_three_or_less(char *str, char *sep, char **token)
{
	char	*leftover;

	if (!str || !sep || !token)
		return ;
	token[0] = strtok(str, sep);
	token[1] = strtok(NULL, sep);
	token[2] = strtok(NULL, sep);
	token[3] = NULL;
	leftover = strtok(NULL, sep);
	if (leftover)
		exit_error("There are four or more strings after the split.");
}

static t_vect	str_to_vector(char *position)
{
	char	*vec[4];
	double	x;
	double	y;
	double	z;

	bzero(vec, 3);
	store_split_three_or_less(position, ",", vec);
	if (!vec[0] || !vec[1] || !vec[2])
		exit_error("Vector elements are missing.");
	x = strtod_wrapper(vec[0]);
	y = strtod_wrapper(vec[1]);
	z = strtod_wrapper(vec[2]);
	return (vect_new(x, y, z));
}

static void	store_object_from_line(char *line, t_object *obj)
{
	char	*position[4];

	bzero(position, 4);
	store_split_three_or_less(line, " ", position);
	obj->pos1 = str_to_vector(position[0]);
	obj->pos2 = str_to_vector(position[1]);
	obj->pos3 = str_to_vector(position[2]);
}

void	store_object_count_from_file(char *filepath, t_data *data)
{
	FILE	*file;
	char	buf[TERM3D_LINE_SIZE + 1];
	int		count;

	file = fopen_wrapper(filepath);
	count = 0;
	while (count < OBJECT_SIZE_MAX && read_line(file, buf))
		count++;
	if (!feof(file))
		exit_error("The number of objects described exceeds INT_MAX");
	fclose(file);
	data->count = count;
}

void	store_object_from_file(char *filepath, t_data *data)
{
	FILE	*file;
	char	buf[TERM3D_LINE_SIZE + 1];
	int		c;

	file = fopen_wrapper(filepath);
	data->object = (t_object *)ft_xcalloc(data->count, sizeof(t_object));
	c = 0;
	while (c < data->count && read_line(file, buf))
		store_object_from_line(buf, &data->object[c++]);
	fclose(file);
}
