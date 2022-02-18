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
	if (getch() == 'z')
		camera->pos.z += 1;
	if (getch() == 'x')
		camera->pos.z -= 1;
	if (getch() == 'a')
		camera->pos.x -= 0.1;
	if (getch() == 'd')
		camera->pos.x += 0.1;
	if (getch() == 'w')
		camera->pos.y += 0.1;
	if (getch() == 's')
		camera->pos.y -= 0.1;
	else if (getch() == 'r')
	{
		camera->pos.x = 0;
		camera->pos.y = 0;
		camera->pos.z = 10;
	}
}
