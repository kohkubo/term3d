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

void	read_circle(t_circle *circle, FILE *file)
{
	t_vect	cnt;
	t_vect	nrm;
	double	radius;

	if (fscanf(file, "%lf,%lf,%lf %lf,%lf,%lf %lf", \
	&cnt.x, &cnt.y, &cnt.z, \
	&nrm.x, &nrm.y, &nrm.z, \
	&radius) != 7)
		exit_error("circle object read failed.");
	circle->center = cnt;
	circle->normal = nrm;
	circle->radius = radius;
}

void	read_triangle(t_triangle *triangle, FILE *file)
{
	t_vect	v1;
	t_vect	v2;
	t_vect	v3;
	t_vect	nrm;

	if (fscanf(file, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf", \
	&v1.x, &v1.y, &v1.z, \
	&v2.x, &v2.y, &v2.z, \
	&v3.x, &v3.y, &v3.z, \
	&nrm.x, &nrm.y, &nrm.z) != 12)
		exit_error("triangle object read failed.");
	triangle->vert1 = v1;
	triangle->vert2 = v2;
	triangle->vert3 = v3;
	triangle->normal = nrm;
}

void	read_rtfile(t_data *data, char *filepath)
{
	FILE	*file;
	int		c;

	check_extension(data, filepath);
	file = fopen(filepath, "r");
	if (!file)
		exit_error("file open failed.");
	if (fscanf(file, "%d", &data->count) != 1 || data->count <= 0)
		exit_error("count read error.");
	c = 0;
	while (c < data->count)
	{
		if (data->type == CIRCLE)
			read_circle(&data->circle[c], file);
		if (data->type == TRIANGLE)
			read_triangle(&data->triangle[c], file);
		c++;
	}
	if (ferror(file))
		exit_error("file error.");
	fclose(file);
}
