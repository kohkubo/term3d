#ifndef READ_FILE_H
# define READ_FILE_H

# include <stdio.h>
# include <sys/stat.h>
# include <string.h>
# include "libft.h"
# include "data.h"
# include "vect.h"

# define TERM3D_LINE_SIZE 1024

size_t	char_count(char *str, char c);
size_t	arraylen(char **array);
ssize_t	getline_wrapper(char **linep, size_t *linecapp, FILE *stream);
t_vect	get_vect(char *str);
void	free_split(char **array);
void	read_file(t_data *data, char *filepath);

#endif
