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

/*
zoom in   : z
zoome out : x
left      : a
right     : d
up        : w
down      : s
reset     : r
*/
void	move_camera(t_camera *camera)
{
	int	ch;

	ch = getch();
	if (ch == 'z')
		camera->pos.z += 5;
	else if (ch == 'x')
		camera->pos.z -= 5;
	else if (ch == 'a')
		camera->pos.x += 1;
	else if (ch == 'd')
		camera->pos.x -= 1;
	else if (ch == 'w')
		camera->pos.y += 1;
	else if (ch == 's')
		camera->pos.y -= 1;
	else if (ch == 'r')
		camera->pos.z *= -1;
}
