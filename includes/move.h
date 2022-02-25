#ifndef MOVE_H
# define MOVE_H

# include "data.h"
# include "vect.h"
# include "init.h"
# include <stdbool.h>
# include <stdio.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MOVE_SCALE 5
# define MOVE_DISTANCE 0.1
# define ROTATE_SPEED 0.01

void	key_control(t_data *data);
void	camera_move_up(t_data *data);
void	camera_move_down(t_data *data);
void	camera_move_left(t_data *data);
void	camera_move_right(t_data *data);
void	camera_rotate_up(t_data *data);
void	camera_rotate_down(t_data *data);
void	camera_rotate_left(t_data *data);
void	camera_rotate_right(t_data *data);
void	camera_rotate_speed_up(t_data *data);
void	camera_rotate_speed_down(t_data *data);
void	camera_zoom_in(t_data *data);
void	camera_zoom_out(t_data *data);
void	camera_stop(t_data *data);
void	camera_reset(t_data *data);

#endif
