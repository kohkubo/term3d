#ifndef READER_H
# define READER_H

# include "data.h"
# include "init.h"
# include <stdio.h>
# include <string.h>

bool		read_rtfile(t_data *data, char *filepath);
t_triangle	*read_triangle(FILE *file);
//t_circle	*read_circle(FILE *file);
//t_torus		*read_torus(FILE *file);

#endif
