#include "loader.h"
#include "debug.h"
#include <sys/stat.h>

void	exit_error(char *errmsg)
{
	if (errno != 0)
		perror(errmsg);
	if (errmsg)
		fprintf(stderr, "%s\n", errmsg);
	exit(EXIT_FAILURE);
}

static void	is_valid_file(char *filepath)
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

static bool	read_line(FILE *file, char *buf)
{
	bzero(buf, 1024);
	if (fscanf(file, " %1024[^\n]", buf) == EOF && !feof(file))
		exit_error("Failed to read file.");
	if (feof(file))
		return (false);
	if (ferror(file))
		exit_error("ferror() has occurred.");
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
	char	buf[1025];

	is_valid_file(filepath);
	file = fopen(filepath, "r");
	if (!file)
		exit_error("File open failed.");
	data->count = 0;
	while (data->count < OBJECT_SIZE_MAX && read_line(file, buf))
		assign_line_to_object(buf, &data->object[data->count++]);
	if (!feof(file))
		exit_error("The number of objects described exceeds OBJECT_SIZE_MAX.");
	fclose(file);
}
