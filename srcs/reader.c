#include "reader.h"

void	exit_error(char *errmsg)
{
	if (errmsg)
		fprintf(stderr, "%s\n", errmsg);
	exit(EXIT_FAILURE);
}

static void	check_extension(t_data *data, char *filepath)
{
	char	*ext;

	if (!filepath)
		exit_error("does not filepath.");
	ext = strrchr(filepath, '.');
	if (!ext)
		exit_error("file extension error.");
	if (!strncmp(ext, ".cir", 5))
		data->type = CIRCLE;
	else if (!strncmp(ext, ".tri", 5))
		data->type = TRIANGLE;
	else
		exit_error("file extension error.");
}

void	read_rtfile(t_data *data, char *filepath)
{
	FILE	*file;
	int		c;
	void	(*read_object)(t_object *, FILE *);

	check_extension(data, filepath);
	file = fopen(filepath, "r");
	if (!file)
		exit_error("file open failed.");
	if (fscanf(file, "%d", &data->count) != 1 || data->count <= 0)
		exit_error("count read error.");
	if (data->type == CIRCLE)
		read_object = read_circle;
	if (data->type == TRIANGLE)
		read_object = read_triangle;
	c = 0;
	while (c < data->count)
		read_object(&data->object[c++], file);
	if (ferror(file))
		exit_error("file error.");
	fclose(file);
}
