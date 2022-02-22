#include "move.h"

static int	getch(void)
{
	struct termios	oldattr;
	struct termios	newattr;
	int				ch;
	int				old;

	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	old = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, old | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	fcntl(STDIN_FILENO, F_SETFL, old);
	return (ch);
}

void	camera_zoom_out(t_camera *camera)
{
	camera->pos = vect_move(camera->pos, camera->normal, MOVE_SCALE);
}

void	camera_zoom_in(t_camera *camera)
{
	camera->pos = vect_move(camera->pos, camera->normal, -MOVE_SCALE);
}

void	move_camera(t_camera *camera)
{
	int	ch;

	ch = getch();
	if (ch == 'z')
		camera_zoom_in(camera);
	else if (ch == 'x')
		camera_zoom_out(camera);
	else if (ch == 'w')
		camera_move_up(camera);
	else if (ch == 's')
		camera_move_down(camera);
	else if (ch == 'a')
		camera_move_left(camera);
	else if (ch == 'd')
		camera_move_right(camera);
}
