#ifndef LOAD_H
# define LOAD_H

# include "data.h"
# include "vect.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>

# define TERM3D_LINE_SIZE 1024
# define TERM3D_READ_FORMAT " %1024[^\n]"

void	load_file(t_data *data, char *filepath);
bool	read_line(FILE *file, char *buf);
void	store_object_count_from_file(char *filepath, t_data *data);
void	store_object_from_file(char *filepath, t_data *data);

#endif
