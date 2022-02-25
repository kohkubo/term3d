#include "control.h"

static void	control_other(t_data *data, int ch)
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
	else if (ch == 'p')
		print_info(data);
}

static bool	control_color(t_data *data, char ch)
{
	if (ch == '1')
		data->config.color = RED;
	else if (ch == '2')
		data->config.color = BLUE;
	else if (ch == '3')
		data->config.color = GREEN;
	else if (ch == '4')
		data->config.color = YELLOW;
	else if (ch == '5')
		data->config.color = MAGENTA;
	else if (ch == '6')
		data->config.color = CYAN;
	else if (ch == '7')
		data->config.color = WHITE;
	else
		return (false);
	printf("%s", data->config.color);
	return (true);
}

static bool	control_light(t_data *data, int ch)
{
	if (ch == 't')
		light_move_up(data);
	else if (ch == 'g')
		light_move_down(data);
	else if (ch == 'f')
		light_move_left(data);
	else if (ch == 'h')
		light_move_right(data);
	else if (ch == 'y')
		light_move_front(data);
	else if (ch == 'u')
		light_move_back(data);
	else
		return (false);
	return (true);
}

static bool	control_camera(t_data *data, int ch)
{
	if (ch == 'w')
		camera_move_up(data);
	else if (ch == 's')
		camera_move_down(data);
	else if (ch == 'a')
		camera_move_left(data);
	else if (ch == 'd')
		camera_move_right(data);
	else if (ch == 'i')
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
		return (false);
	return (true);
}

void	key_control(t_data *data)
{
	int	ch;

	ch = getch();
	if (control_camera(data, ch))
		return ;
	if (control_light(data, ch))
		return ;
	if (control_color(data, ch))
		return ;
	control_other(data, ch);
}
