#ifndef THREAD_H
# define THREAD_H

# include "data.h"
# include "shading.h"
# include "ray.h"
# include <pthread.h>

void	thread_store_canvas(t_data *data, t_thread_line *line);

#endif // THREAD_H
