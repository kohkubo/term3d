#include "config.h"

void	set_config(t_data *data, int ac, char **av)
{
	data->config.color = WHITE;
	data->config.charset = "-~=cxFX8NNNNN";
	if (ac <= 1 || ac >= 4)
		exit_error("Usage: ./term3d <filename> [charset]");
	if (ac >= 3)
		data->config.charset = av[2];
	if (strlen(data->config.charset) == 0)
		exit_error("Error: charset is empty");
	data->config.charset_size = strlen(data->config.charset);
}
