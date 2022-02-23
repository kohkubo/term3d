#ifndef MOVE_H
# define MOVE_H

# include "data.h"
# include "vect.h"
# include <stdbool.h>
# include <stdio.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MOVE_SCALE 5
# define MOVE_DISTANCE 0.1

void	key_control(t_camera *camera);
void	camera_move_left(t_camera *camera);
void	camera_move_right(t_camera *camera);
void	camera_move_up(t_camera *camera);
void	camera_move_down(t_camera *camera);

#endif
