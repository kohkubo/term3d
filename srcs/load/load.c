#include "load.h"

/*
Valid Format

[] is 3dvector like [x,y,z]

.tri
[pos1] [pos2] [pos3]

How to implement?

1. check file extension.
2. read one line.
3. parse line with spaces.
4. parse vector with comma.
5. store vector x,y,z data into t_data.object
*/

static void	valid_file_check(char *filepath)
{
	struct stat	st;
	char		*ext;

	if (!filepath)
		exit_error("Filepath is NULL");
	if (stat(filepath, &st) != 0)
		exit_error("File does not exist");
	if (!S_ISREG(st.st_mode))
		exit_error("It's not a file");
	if (st.st_size == 0)
		exit_error("File is empty");
	ext = strrchr(filepath, '.');
	if (!ext || strncmp(ext, ".tri", 5))
		exit_error("Invalid file extension. valid : .tri");
}

bool	getline_wrapper(FILE *file, char **buf)
{
	size_t	len;

	len = 0;
	if ((getline(buf, &len, file) == EOF && !feof(file)) || ferror(file))
	{
		free(*buf);
		exit_error("Failed to read file");
	}
	len = strlen(*buf);
	if (feof(file) || len == 0)
		return (false);
	if ((*buf)[len - 1] == '\n')
		(*buf)[len - 1] = '\0';
	return (true);
}

static FILE	*fopen_wrapper(char *filepath)
{
	FILE	*file;

	file = fopen(filepath, "r");
	if (!file)
		exit_error("fopen: File open failed");
	return (file);
}

void	load_file(t_data *data, char *filepath)
{
	FILE	*file;

	valid_file_check(filepath);
	file = fopen_wrapper(filepath);
	store_object_count_from_file(data, file);
	store_object_from_file(data, file);
	fclose(file);
}
