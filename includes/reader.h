#ifndef READER_H
# define READER_H

# include "data.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

bool		read_rtfile(t_data *data, char *filepath);
t_triangle	*new_triangle();

#endif
