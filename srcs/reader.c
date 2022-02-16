#include "reader.h"

static bool	is_valid_ext(char *filepath)
{
	char	*ext;

	if (!filepath)
		return (false);
	ext = strrchr(filepath, '.');
	if (!ext || strncmp(ext, ".rt", 4))
		return (false);
	return (true);
}

static t_list	*read_object(FILE *file)
{
	return (ft_lstnew(read_triangle(file)));
}

static bool	add_object(t_data *data, t_list *add)
{
	if (!add)
		return (false);
	ft_lstadd_back(&data->triangle, add);
	return (true);
}

bool	read_rtfile(t_data *data, char *filepath)
{
	FILE	*file;
	bool	success;

	if (!is_valid_ext(filepath))
		return (false);
	file = fopen(filepath, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Input filepath named \"%s\" not found.\n", \
				filepath);
		return (false);
	}
	success = true;
	while (success && !feof(file))
		success = add_object(data, read_object(file));
	if (!success)
		ft_lstclear(&data->triangle, free);
	fclose(file);
	return (success);
}
