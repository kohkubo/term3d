#include "reader.h"

static double	wrap_strtod(char *str)
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

void	read_circle(t_object *circle, FILE *file)
{
	char	cnt[3][10];
	char	nrm[3][10];
	char	rad[10];

	if (fscanf(file, " %9[-.0123456789],%9[-.0123456789],%9[-.0123456789] \
					   %9[-.0123456789],%9[-.0123456789],%9[-.0123456789] \
					   %9[-.0123456789] ", \
	cnt[0], cnt[1], cnt[2], nrm[0], nrm[1], nrm[2], rad) != 7)
		exit_error("circle object read failed.");
	circle->pos1 = vect_new(\
	wrap_strtod(cnt[0]), wrap_strtod(cnt[1]), wrap_strtod(cnt[2]));
	circle->normal = vect_new(\
	wrap_strtod(nrm[0]), wrap_strtod(nrm[1]), wrap_strtod(nrm[2]));
	circle->radius = wrap_strtod(rad);
}

void	read_triangle(t_object *triangle, FILE *file)
{
	char	v1[3][10];
	char	v2[3][10];
	char	v3[3][10];

	if (fscanf(file, " %9[-.0123456789],%9[-.0123456789],%9[-.0123456789] \
					   %9[-.0123456789],%9[-.0123456789],%9[-.0123456789] \
					   %9[-.0123456789],%9[-.0123456789],%9[-.0123456789] ", \
	v1[0], v1[1], v1[2], v2[0], v2[1], v2[2], v3[0], v3[1], v3[2]) != 9)
		exit_error("triangle object read failed.");
	triangle->pos1 = vect_new(\
	wrap_strtod(v1[0]), wrap_strtod(v1[1]), wrap_strtod(v1[2]));
	triangle->pos2 = vect_new(\
	wrap_strtod(v2[0]), wrap_strtod(v2[1]), wrap_strtod(v2[2]));
	triangle->pos3 = vect_new(\
	wrap_strtod(v3[0]), wrap_strtod(v3[1]), wrap_strtod(v3[2]));
}
