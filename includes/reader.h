#ifndef READER_H
# define READER_H

# include "data.h"
# include "vect.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>

void	read_rtfile(t_data *data, char *filepath);
void	read_circle(t_object *circle, FILE *file);
void	read_triangle(t_object *triangle, FILE *file);
void	exit_error(char *errmsg);

#endif
