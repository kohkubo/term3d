#include "term3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	set_config(&data, ac, av);
	read_file(&data, av[1]);
	init_data(&data);
	draw(&data);
	return (EXIT_SUCCESS);
}
