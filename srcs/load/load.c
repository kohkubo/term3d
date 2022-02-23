#include "load.h"

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

// No distinction is made
// between the presence or absence of a line feed at the end.
bool	read_line(FILE *file, char *buf)
{
	bzero(buf, TERM3D_LINE_SIZE + 1);
	if (fscanf(file, TERM3D_READ_FORMAT, buf) == EOF && !feof(file))
		exit_error("Failed to read file.");
	if (buf[TERM3D_LINE_SIZE - 1] != '\0')
		exit_error("Line is too long.");
	if (feof(file) && buf[0] == '\0')
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
	is_valid_file(filepath);
	store_object_count_from_file(filepath, data);
	store_object_from_file(filepath, data);
}
