#include "move.h"

void	change_color(t_data *data, char ch)
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
}
