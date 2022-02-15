#include "reader.h"

static bool	is_valid_ext(char *filepath) {
	char	*ext;

	if (!filepath)
		return (false);
	ext = strrchr(filepath, '.');
	if (!ext || strncmp(ext, ".rt", 4))
		return (false);
	return (true);
}

static bool	read_identifier(FILE *file) {
	char identifier[4];

	if (fscanf(file, "%3s", identifier) != 1)
		return (false);
	if (strncmp(identifier, "tr", 3))
		return (false);
	return (true);
}

static bool	read_triangle(t_triangle *tri, FILE *file)
{
	t_vect n;
	t_vect v1;
	t_vect v2;
	t_vect v3;
	int read;

	if (!read_identifier(file))
		return (false);
	read = fscanf(file, " %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf ",
	&n.x, &n.y, &n.z   ,
	&v1.x, &v1.y, &v1.z,
	&v2.x, &v2.y, &v2.z,
	&v3.x, &v3.y, &v3.z);
	if (read == EOF && feof(file))
		return (true);
	if (read != 12)
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
	while (success && !feof(file))
		success = read_triangle(data->triangle, file);
	fclose(file);
	return (success);
}
