#include <fcntl.h>

#include "control.h"

int	fcntl_wrapper(int fd, int cmd, int arg)
{
	int	ret;

	ret = fcntl(fd, cmd, arg);
	if (ret == -1)
		exit_error("fcntl");
	return (ret);
}

void	tcgetattr_wrapper(int fd, struct termios *termios)
{
	if (tcgetattr(fd, termios) == -1)
		exit_error("tcgetattr");
}

void	tcsetattr_wrapper(int fd, int cmd, struct termios *termios)
{
	if (tcsetattr(fd, cmd, termios) == -1)
		exit_error("tcsetattr");
}

int	getch(void)
{
	struct termios	oldattr;
	struct termios	newattr;
	int				ch;
	int				old;

	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr_wrapper(STDIN_FILENO, TCSANOW, &newattr);
	old = fcntl_wrapper(STDIN_FILENO, F_GETFL, 0);
	fcntl_wrapper(STDIN_FILENO, F_SETFL, old | O_NONBLOCK);
	ch = getchar();
	tcsetattr_wrapper(STDIN_FILENO, TCSANOW, &oldattr);
	fcntl_wrapper(STDIN_FILENO, F_SETFL, old);
	return (ch);
}
