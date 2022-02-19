#include "reader.h"

/*
Valid Format

[] is 3dvector like [x,y,z]

.tri
[pos1] [pos2] [pos3]

.3d (and any other point cloud data.)
[pos1]

*/

/*
How to implement?

1. check file extension.
2. read one line.
3. parse line with spaces.
4. parse vector with comma.
5. store double data into t_data object

*/

void	exit_error(char *errmsg)
{
	if (errmsg)
		fprintf(stderr, "%s\n", errmsg);
	exit(EXIT_FAILURE);
}

static void	is_valid_extension(char *filepath)
{
	char	*ext;

	if (!filepath)
		exit_error("does not filepath.");
	ext = strrchr(filepath, '.');
	if (!ext || strncmp(ext, ".tri", 5))
		exit_error("file extension error.");
}

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

void	str_trichotomy(char *str, char *sep, char **token)
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

t_vect	assign_str_to_vector(char *position)
{
	char	*vec[4];
	double	x;
	double	y;
	double	z;

	str_trichotomy(position, ",", vec);
	x = validatable_strtod(vec[0]);
	y = validatable_strtod(vec[1]);
	z = validatable_strtod(vec[2]);
	return (vect_new(x,y,z));
}

void	read_line(t_object *obj, FILE *file)
{
	char	buf[1025];
	char	*newline;
	char	*position[4];

	if (fgets(buf, sizeof(buf), file) == NULL && !feof(file))
		exit_error("fget error");
	if (feof(file))
		return ;
	newline = strrchr(buf, '\n');
	if (newline)
		*newline = '\0';
	str_trichotomy(buf, " ", position);
	obj->pos1 = assign_str_to_vector(position[0]);
	obj->pos2 = assign_str_to_vector(position[1]);
	obj->pos3 = assign_str_to_vector(position[2]);
}

void	print_all_object(t_data *data)
{
	int	c;

	c = 0;
	printf("object count : %d\n", data->count);
	while (c < data->count)
	{
		printf("%d pos1 : ", c);
		vect_print(data->object[c].pos1);
		printf("%d pos2 : ", c);
		vect_print(data->object[c].pos2);
		printf("%d pos3 : ", c);
		vect_print(data->object[c].pos3);
		c++;
	}
}

void	read_rtfile(t_data *data, char *filepath)
{
	FILE	*file;
	int		c;

	is_valid_extension(filepath);
	file = fopen(filepath, "r");
	if (!file)
		exit_error("file open failed.");
	c = 0;
	while (!feof(file) && c < OBJECT_SIZE_MAX)
		read_line(&data->object[c++], file);
	if (ferror(file))
		exit_error("file error.");
	data->count = (c < OBJECT_SIZE_MAX ? c : OBJECT_SIZE_MAX);
	fclose(file);

	//for debug;
	print_all_object(data);
	exit(0);
}
