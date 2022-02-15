#include "term3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("Usage: %s <filename>\n", av[0]);
		return (EXIT_FAILURE);
	}
	draw(&data);
	return (EXIT_SUCCESS);
}
