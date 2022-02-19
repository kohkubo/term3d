#include "loader.h"
#include "debug.h"

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

static bool	read_line(FILE *file, char *buf, size_t buf_size)
{
	char	*newline;

	if (feof(file))
		return (false);
	if (fgets(buf, buf_size, file) == NULL && !feof(file))
		exit_error("fget error");
	if (ferror(file))
		exit_error("ferror");
	newline = strrchr(buf, '\n');
	if (newline)
		*newline = '\0';
	return (true);
}

/*
Valid Format

[] is 3dvector like [x,y,z]

.tri
[pos1] [pos2] [pos3]

.3d (and any other point cloud data.)
[pos1]


How to implement?

1. check file extension.
2. read one line.
3. parse line with spaces.
4. parse vector with comma.
5. store vector x,y,z data into t_data.object
*/
void	load_file(t_data *data, char *filepath)
{
	FILE	*file;
	char	buf[1024];

	is_valid_extension(filepath);
	file = fopen(filepath, "r");
	if (!file)
		exit_error("file open failed.");
	data->count = 0;
	while (read_line(file, buf, sizeof(buf)) && data->count < OBJECT_SIZE_MAX)
		assign_line_to_object(buf, &data->object[data->count++]);
	fclose(file);
}
