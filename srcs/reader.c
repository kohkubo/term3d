#include "reader.h"

void exit_error(char *errmsg)
{
	if (errmsg)
		fprintf(stderr, "%s\n", errmsg);
	exit(EXIT_FAILURE);
}

static void check_extension(t_data *data, char *filepath)
{
	char *ext;

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

double	wrap_strtod(char *str)
{
	char	*entptr;
	double	d;

	errno = 0;
	d = strtod(str, &entptr);
	if (errno == ERANGE)
		exit_error("number out of range.");
	if (*entptr != '\0')
		exit_error("number out of range");
	if (d == HUGE_VAL)
		exit_error("huge val");
	return (d);
}

void read_circle(t_object *circle, FILE *file)
{
	char	cnt[3][10];
	char	nrm[3][10];
	char	rad[10];

	if (fscanf(file, " %10s,%10s,%10s %10s,%10s,%10s %10s ",
	cnt[0], cnt[1], cnt[2], nrm[0], nrm[1], nrm[2], rad) != 7)
		exit_error("circle object read failed.");
	circle->pos1 = vect_new(wrap_strtod(cnt[0]), wrap_strtod(cnt[1]), wrap_strtod(cnt[2]));
	circle->normal = vect_new(wrap_strtod(nrm[0]), wrap_strtod(nrm[1]), wrap_strtod(nrm[2]));
	circle->radius = wrap_strtod(rad);
}

void read_triangle(t_object *triangle, FILE *file)
{
	char	v1[3][10];
	char	v2[3][10];
	char	v3[3][10];

	if (fscanf(file, " %10s,%10s,%10s %10s,%10s,%10s %10s,%10s,%10s ",
	v1[0], v1[1], v1[2], v2[0], v2[1], v2[2], v3[0], v3[1], v3[2]) != 9)
		exit_error("triangle object read failed.");
	triangle->pos1 = vect_new(wrap_strtod(v1[0]), wrap_strtod(v1[1]), wrap_strtod(v1[2]));
	triangle->pos2 = vect_new(wrap_strtod(v2[0]), wrap_strtod(v2[1]), wrap_strtod(v2[2]));
	triangle->pos3 = vect_new(wrap_strtod(v3[0]), wrap_strtod(v3[1]), wrap_strtod(v3[2]));
}

void read_rtfile(t_data *data, char *filepath)
{
	FILE *file;
	int c;

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
			read_circle(&data->object[c], file);
		if (data->type == TRIANGLE)
			read_triangle(&data->object[c], file);
		c++;
	}
	if (ferror(file))
		exit_error("file error.");
	fclose(file);
}
