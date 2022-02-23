#include "setting.h"

static void	set_color(t_setting *set, char *str)
{
	if (!strncmp(str, "-r", 3))
		set->color = RED;
	else if (!strncmp(str, "-b", 3))
		set->color = BLUE;
	else if (!strncmp(str, "-g", 3))
		set->color = GREEN;
	else if (!strncmp(str, "-y", 3))
		set->color = YELLOW;
	else if (!strncmp(str, "-m", 3))
		set->color = MAGENTA;
	else if (!strncmp(str, "-c", 3))
		set->color = CYAN;
	else
		exit_error("Invalid Color. valid : -rbgymc");
}

void	setting(t_data *data, int ac, char **av)
{
	data->setting.color = WHITE;
	data->setting.charset = "-~=cxFX8NNNNN";
	if (ac <= 1 || ac >= 5)
		exit_error("Usage: ./term3d <filename> [charset] [color : -rbgymc]");
	if (ac >= 3)
		data->setting.charset = av[2];
	if (ac >= 4)
		set_color(&data->setting, av[3]);
}
