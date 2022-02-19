#include "loader.h"

static double	validatable_strtod(char *str)
{
	char	*entptr;
	double	d;

	errno = 0;
	d = strtod(str, &entptr);
	if (errno == ERANGE)
		exit_error("number out of range.");
	if (*entptr != '\0')
		exit_error("number out of range.");
	if (d == HUGE_VAL)
		exit_error("huge val");
	return (d);
}

static void	str_trichotomy(char *str, char *sep, char **token)
{
	char	*leftover;

	if (!str || !sep || !token)
		return ;
	printf("%s\n", str);
	token[0] = strtok(str, sep);
	token[1] = strtok(NULL, sep);
	token[2] = strtok(NULL, sep);
	token[3] = NULL;
	leftover = strtok(NULL, sep);
	if (leftover)
		exit_error("leftover");
	printf("%s\n%s\n%s\n\n", token[0], token[1], token[2]);
}

static t_vect	assign_str_to_vector(char *position)
{
	char	*vec[4];
	double	x;
	double	y;
	double	z;

	if (!position)
		return (vect_new(0, 0, 0));
	str_trichotomy(position, ",", vec);
	x = validatable_strtod(vec[0]);
	y = validatable_strtod(vec[1]);
	z = validatable_strtod(vec[2]);
	return (vect_new(x, y, z));
}

void	assign_line_to_object(char *line, t_object *obj)
{
	char	*position[4];

	str_trichotomy(line, " ", position);
	obj->pos1 = assign_str_to_vector(position[0]);
	obj->pos2 = assign_str_to_vector(position[1]);
	obj->pos3 = assign_str_to_vector(position[2]);
}
