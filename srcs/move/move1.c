#include "move.h"
#include <string.h>

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

void	key_control(t_camera *camera)
{
	int				i;
	char			ch;
	const t_control	control[] = {{camera_move_up,			'w'},
								 {camera_move_down,			's'},
								 {camera_move_left,			'a'},
								 {camera_move_right,		'd'},
								 {camera_rotate_up,			'i'},
								 {camera_rotate_down,		'k'},
								 {camera_rotate_left,		'j'},
								 {camera_rotate_right,		'l'},
								 {camera_rotate_speed_up,	'm'},
								 {camera_rotate_speed_down,	'n'},
								 {camera_zoom_in,			'z'},
								 {camera_zoom_out,			'x'},
								 {camera_reset,				'r'},
								 {camera_stop,				' '},
								 {quit,						'q'}};
	const int		count = (sizeof(control) / sizeof(*control));

	ch = getch();
	i = 0;
	while (i < count && ch != control[i].key)
		i++;
	if (i < count)
		control[i].control(camera);
}
