#include "reader.h"

void	exit_perror(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	exit_error(char *errmsg)
{
	if (errmsg)
		fprintf(stderr, "%s\n", errmsg);
	exit(EXIT_FAILURE);
}

static void	check_extension(char *filepath)
{
	char	*ext;

	if (!filepath)
		exit_error("does not filepath.");
	ext = strrchr(filepath, '.');
	if (!ext || strncmp(ext, ".cir", 5))
		exit_error("file extension error.");
}

void	read_circle(t_circle *circle, FILE *file)
{
	t_vect	nrm;
	t_vect	cnt;
	double	radius;

	if (fscanf(file, "%lf,%lf,%lf %lf,%lf,%lf %lf",
			   &cnt.x, &cnt.y, &cnt.z, &nrm.x, &nrm.y, &nrm.z, &radius) != 7)
		exit_error("read failed");
	circle->center = cnt;
	circle->normal = nrm;
	circle->radius = radius;
}

void	read_rtfile(t_data *data, char *filepath)
{
	FILE	*file;
	int		c;

	check_extension(filepath);
	file = fopen(filepath, "r");
	if (!file)
		exit_perror();
	data->type = CIRCLE;
	if (fscanf(file, "%d", &data->count) != 1)
		exit_error("count read error");
	c = 0;
	while (c < data->count)
		read_circle(&data->circle[c++], file);
	if (!feof(file) || ferror(file))
		exit_error("file error");
	fclose(file);
}
