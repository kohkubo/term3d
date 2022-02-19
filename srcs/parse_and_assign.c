#include "loader.h"

static double	validatable_strtod(char *str)
{
	char	*endptr;
	double	d;

	if (!str)
		return (0);
	errno = 0;
	d = strtod(str, &endptr);
	if (errno == ERANGE)
		exit_error(NULL);
	if (*endptr != '\0')
		exit_error("Contains characters that cannot be converted.");
	if (d == HUGE_VAL)
		exit_error("An overflow has occurred.");
	return (d);
}

static void	str_trichotomy(char *str, char *sep, char **token)
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

static t_vect	assign_str_to_vector(char *position)
{
	char	*vec[4];
	double	x;
	double	y;
	double	z;

	bzero(vec, 3);
	str_trichotomy(position, ",", vec);
	if (!vec[0] || !vec[1] || !vec[2])
		exit_error("Vector elements are missing.");
	x = validatable_strtod(vec[0]);
	y = validatable_strtod(vec[1]);
	z = validatable_strtod(vec[2]);
	return (vect_new(x, y, z));
}

void	assign_line_to_object(char *line, t_object *obj)
{
	char	*position[4];

	bzero(position, 4);
	str_trichotomy(line, " ", position);
	obj->pos1 = assign_str_to_vector(position[0]);
	obj->pos2 = assign_str_to_vector(position[1]);
	obj->pos3 = assign_str_to_vector(position[2]);
}
