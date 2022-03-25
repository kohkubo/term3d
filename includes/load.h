#ifndef LOAD_H
# define LOAD_H

# include "data.h"
# include "vect.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>

# define TERM3D_LINE_SIZE 1024
# define TERM3D_READ_FORMAT "%1024[^\n]"

void	load_file(t_data *data, char *filepath);
bool	getline_wrapper(FILE *file, char **buf);
void	store_object_count_from_file(t_data *data, FILE *file);
void	store_object_from_file(t_data *data, FILE *file);
char	**ft_split(char const *s, char c);
char	**free_string_array(char **buf);
double	strtod_wrapper(char *str);

//for gtest
t_vect	str_to_vector(char *position);

#endif
