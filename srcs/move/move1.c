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

static void	other_control(t_camera *camera, int ch)
{
	if (ch == 'z')
		camera_zoom_in(camera);
	else if (ch == 'x')
		camera_zoom_out(camera);
	else if (ch == ' ')
		camera_stop(camera);
	else if (ch == 'r')
		camera_reset(camera);
	else if (ch == 'q')
		quit(camera);
}

static void	rotate_control(t_camera *camera, int ch)
{
	if (ch == 'i')
		camera_rotate_up(camera);
	else if (ch == 'k')
		camera_rotate_down(camera);
	else if (ch == 'j')
		camera_rotate_left(camera);
	else if (ch == 'l')
		camera_rotate_right(camera);
	else if (ch == 'm')
		camera_rotate_speed_up(camera);
	else if (ch == 'n')
		camera_rotate_speed_down(camera);
	else
		other_control(camera, ch);
}

void	key_control(t_camera *camera)
{
	int	ch;

	ch = getch();
	if (ch == 'w')
		camera_move_up(camera);
	else if (ch == 's')
		camera_move_down(camera);
	else if (ch == 'a')
		camera_move_left(camera);
	else if (ch == 'd')
		camera_move_right(camera);
	else
		rotate_control(camera, ch);
}
