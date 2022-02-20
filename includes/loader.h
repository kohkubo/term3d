#ifndef LOADER_H
# define LOADER_H

# include "data.h"
# include "vect.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>

# define LINE_MAX 1024
# define FORMAT " %1024[^\n]"

void	load_file(t_data *data, char *filepath);
void	assign_line_to_object(char *line, t_object *obj);
void	exit_error(char *errmsg);

#endif
