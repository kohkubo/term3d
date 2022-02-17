#include "term3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", av[0]);
		return (EXIT_FAILURE);
	}
	read_rtfile(&data, av[1]);
	draw(&data);
	return (EXIT_SUCCESS);
}
