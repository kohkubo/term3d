#ifndef THREAD_H
# define THREAD_H

# include "data.h"
# include "shading.h"
# include "ray.h"
# include <pthread.h>

typedef struct s_thread_line
{
	pthread_t	thread;
	t_data		*data;
	t_camera	camera;
	int			y;
}				t_thread_line;

void	thread_store_canvas(t_data *data, t_thread_line *line);

#endif // THREAD_H
