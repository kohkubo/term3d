#include "read_file.h"

static void	valid_file_check(char *filepath)
{
	struct stat	st;
	char		*ext;

	if (!filepath)
		exit_error("Filepath is NULL");
	if (stat(filepath, &st) != 0)
		exit_error("File does not exist.");
	if (!S_ISREG(st.st_mode))
		exit_error("It's not a file.");
	if (st.st_size == 0)
		exit_error("File is empty.");
	ext = strrchr(filepath, '.');
	if (!ext || strncmp(ext, ".tri", 5))
		exit_error("Invalid file extension. valid : .tri .");
}

static void	set_object_from_line(t_object *object, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (arraylen(split) != 3)
	{
		exit_error("Invalid object format.");
	}
	object->pos1 = get_vect(split[0]);
	object->pos2 = get_vect(split[1]);
	object->pos3 = get_vect(split[2]);
	free_split(split);
}

static void	set_object_count_from_file(t_data *data, FILE *file)
{
	char		*line;
	size_t		linecap;

	linecap = 0;
	line = NULL;
	data->count = 0;
	while (getline_wrapper(&line, &linecap, file) > 0)
	{
		if (line[0] == '\0')
			continue ;
		data->count++;
	}
	if (data->count == 0)
		exit_error("No objects found.");
	rewind(file);
}

static void	set_object_from_file(t_data *data, FILE *file)
{
	char		*line;
	size_t		linecap;
	int			i;

	linecap = 0;
	line = NULL;
	data->object = (t_object *)ft_xmalloc(sizeof(t_object) * data->count);
	i = 0;
	while (getline_wrapper(&line, &linecap, file) > 0)
	{
		if (line[0] == '\0')
			continue ;
		set_object_from_line(&data->object[i], line);
		i++;
	}
	rewind(file);
}

void	read_file(t_data *data, char *filepath)
{
	FILE	*opend_file;

	valid_file_check(filepath);
	opend_file = fopen_wrapper(filepath);
	set_object_count_from_file(data, opend_file);
	set_object_from_file(data, opend_file);
}
