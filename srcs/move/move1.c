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

static void	other_control(t_data *data, int ch)
{
	if (ch == 'z')
		camera_zoom_in(data);
	else if (ch == 'x')
		camera_zoom_out(data);
	else if (ch == ' ')
		camera_stop(data);
	else if (ch == 'r')
		camera_reset(data);
	else if (ch == 'q')
		exit(EXIT_SUCCESS);
}

static void	rotate_control(t_data *data, int ch)
{
	if (ch == 'i')
		camera_rotate_up(data);
	else if (ch == 'k')
		camera_rotate_down(data);
	else if (ch == 'j')
		camera_rotate_left(data);
	else if (ch == 'l')
		camera_rotate_right(data);
	else if (ch == 'm')
		camera_rotate_speed_up(data);
	else if (ch == 'n')
		camera_rotate_speed_down(data);
	else
		other_control(data, ch);
}

void	key_control(t_data *data)
{
	int	ch;

	ch = getch();
	if (ch == 'w')
		camera_move_up(data);
	else if (ch == 's')
		camera_move_down(data);
	else if (ch == 'a')
		camera_move_left(data);
	else if (ch == 'd')
		camera_move_right(data);
	else
		rotate_control(data, ch);
}
