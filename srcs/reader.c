#include "reader.h"

static bool	read_identifier(FILE *file) {
	char identifier[4];

	if (fscanf(file, "%3s", identifier) != 1)
		return (false);
	if (strncmp(identifier, "tr", 3))
		return (false);
	return (true);
}

static bool	read_vector(t_vect *vect, FILE *file)
{
	return (fscanf(file, " %lf,%lf,%lf ", &vect->x, &vect->y, &vect->z) == 3);
}

static bool	is_valid_ext(char *filepath) {
	char	*ext;

	if (!filepath)
		return (false);
	ext = strrchr(filepath, '.');
	if (!ext || strncmp(ext, ".rt", 4))
		return (false);
	return (true);
}

static bool	read_triangle(t_triangle *tri, FILE *file)
{
	t_vect n;
	t_vect v1;
	t_vect v2;
	t_vect v3;

	if (fscanf(file, "tr %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf ",
	&n.x, &n.y, &n.z   ,
	&v1.x, &v1.y, &v1.z,
	&v2.x, &v2.y, &v2.z,
	&v3.x, &v3.y, &v3.z) != 12)
		return (false);
	tri->normal = n;
	tri->vert1 = v1;
	tri->vert2 = v2;
	tri->vert3 = v3;
	return (true);
}

bool	read_rtfile(t_data *data, char *filepath) {
	FILE	*file;
	bool	success;

	if (!is_valid_ext(filepath))
		return (false);
	file = fopen(filepath, "r");
	if (!file) {
		fprintf(stderr, "Error: Input filepath named \"%s\" not found.\n", filepath);
		return (false);
	}
	success = true;
	while (success)
		success = read_triangle(data->triangle, file);
	success &= feof(file);
	fclose(file);
	return (success);
}
