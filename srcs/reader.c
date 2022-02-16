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

static bool	read_identifier(FILE *file)
{
	char	identifier[4];

	if (fscanf(file, "%3s", identifier) != 1)
		return (false);
	if (strncmp(identifier, "tr", 3))
		return (false);
	return (true);
}

static bool	read_triangle(t_triangle *tri, FILE *file)
{
	t_vect	n;
	t_vect	vert[3];
	int		read;

	if (!read_identifier(file))
		return (false);
	read = fscanf(file, " %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf ", \
	&n.x, &n.y, &n.z, \
	&vert[0].x, &vert[0].y, &vert[0].z, \
	&vert[1].x, &vert[1].y, &vert[1].z, \
	&vert[2].x, &vert[2].y, &vert[2].z);
	if (read == EOF && feof(file))
		return (true);
	if (read != 12)
		return (false);
	tri->normal = n;
	tri->vert1 = vert[0];
	tri->vert2 = vert[1];
	tri->vert3 = vert[2];
	return (true);
}

t_triangle	*new_triangle(void)
{
	t_triangle	*tri;

	tri = (t_triangle*)malloc(sizeof(t_triangle));
	if (!tri)
		return (NULL);
	tri->normal = vect_new(0, 0, 0);
	tri->vert1 = vect_new(0, 0, 0);
	tri->vert2 = vect_new(0, 0, 0);
	tri->vert3 = vect_new(0, 0, 0);
	return (tri);
}

static void 	print_triangle(t_triangle *tri) {
  printf("Triangle\n");
  vect_print(tri->normal);
  vect_print(tri->vert1);
  vect_print(tri->vert2);
  vect_print(tri->vert3);
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
	t_triangle	*tri;
	t_list		*add;
	while (success && !feof(file))
	{
		tri = new_triangle();
		success = read_triangle(tri, file);
		add = ft_lstnew(tri);
		if (!add && data->triangle)
			ft_lstclear(&data->triangle, free);
		if (!add && !data->triangle)
			ft_lstclear(&add, free);
		if (data->triangle)
			ft_lstadd_back(&data->triangle, add);
		else
			data->triangle = add;
	}
	fclose(file);
	return (success);
}
