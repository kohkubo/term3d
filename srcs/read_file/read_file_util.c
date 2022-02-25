#include "read_file.h"

size_t	char_count(char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

size_t	arraylen(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_split(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

ssize_t	getline_wrapper(char **linep, size_t *linecapp, FILE *stream)
{
	ssize_t	ret;

	if (!linep || !linecapp || !stream)
		exit_error("getline: Invalid arguments.");
	if (!*linep)
	{
		*linep = (char *)ft_xmalloc(TERM3D_LINE_SIZE + 1);
		*linecapp = TERM3D_LINE_SIZE;
	}
	ret = getline(linep, linecapp, stream);
	if (ret == -1)
	{
		free(*linep);
		*linep = NULL;
		*linecapp = 0;
		if (ferror(stream))
			exit_error("getline: Error reading file.");
		if (feof(stream))
			return (0);
	}
	if (ret != 0 && (*linep)[ret - 1] == '\n')
		(*linep)[ret - 1] = '\0';
	return (ret);
}

t_vect	get_vect(char *str)
{
	t_vect	vect;
	char	**split;

	if (char_count(str, ',') != 2)
	{
		exit_error("Invalid vector format.");
	}
	split = ft_split(str, ',');
	vect.x = strtod_wrapper(split[0]);
	vect.y = strtod_wrapper(split[1]);
	vect.z = strtod_wrapper(split[2]);
	free_split(split);
	return (vect);
}
