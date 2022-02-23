#include "move.h"

void	camera_move_left(t_camera *camera)
{
	camera->pos = vect_move(&camera->pos, &camera->right, -MOVE_DISTANCE);
}

void	camera_move_right(t_camera *camera)
{
	camera->pos = vect_move(&camera->pos, &camera->right, MOVE_DISTANCE);
}

void	camera_move_up(t_camera *camera)
{
	camera->pos = vect_move(&camera->pos, &camera->up, MOVE_DISTANCE);
}

void	camera_move_down(t_camera *camera)
{
	camera->pos = vect_move(&camera->pos, &camera->up, -MOVE_DISTANCE);
}
