#include "term3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	set_config(&data, ac, av);
	if (ac == 1)
		set_tours_data(&data);
	else
		load_file(&data, av[1]);
	init_data(&data);
	draw(&data);
	return (EXIT_SUCCESS);
}
