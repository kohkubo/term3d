#include "config.h"

static void	set_color(t_config *conf, char *str)
{
	if (!strncmp(str, "-r", 3))
		conf->color = RED;
	else if (!strncmp(str, "-b", 3))
		conf->color = BLUE;
	else if (!strncmp(str, "-g", 3))
		conf->color = GREEN;
	else if (!strncmp(str, "-y", 3))
		conf->color = YELLOW;
	else if (!strncmp(str, "-m", 3))
		conf->color = MAGENTA;
	else if (!strncmp(str, "-c", 3))
		conf->color = CYAN;
	else if (!strncmp(str, "-w", 3))
		conf->color = WHITE;
	else
		exit_error("Invalid Color. valid : -rbgymcw");
}

void	set_config(t_data *data, int ac, char **av)
{
	data->config.color = BLUE;
	data->config.charset = "-~=cxFX8NNNNN";
	if (ac <= 1 || ac >= 5)
		exit_error("Usage: ./term3d <filename> [charset] [color : -rbgymc]");
	if (ac >= 3)
		set_color(&data->config, av[2]);
	if (ac >= 4)
		data->config.charset = av[3];
}
