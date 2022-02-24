#include "move.h"

void	camera_rotate_speed_up(t_camera *camera)
{
	camera->rotate_angle += ROTATE_SPEED;
}

void	camera_rotate_speed_down(t_camera *camera)
{
	camera->rotate_angle -= ROTATE_SPEED;
}

void	camera_zoom_in(t_camera *camera)
{
	camera->pos = vect_move(&camera->pos, &camera->normal, MOVE_SCALE);
}

void	camera_zoom_out(t_camera *camera)
{
	camera->pos = vect_move(&camera->pos, &camera->normal, -MOVE_SCALE);
}
