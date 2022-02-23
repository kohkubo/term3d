#ifndef DRAW_H
# define DRAW_H

# include "data.h"
# include "vect.h"
# include "calc.h"
# include "move.h"
# include "debug.h"
# include "load.h"
# include "shading.h"
# include "init.h"
# include "thread.h"
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

void	draw(t_data *data);

#endif
