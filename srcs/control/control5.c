#include "control.h"

void	camera_stop(t_data *data)
{
	data->base_info.rotate_angle = radian(!data->base_info.rotate_angle);
}

void	camera_reset(t_data *data)
{
	init_base_info(data);
}

void	print_info(t_data *data)
{
	static bool	flg = true;

	if (flg)
	{
		printf(WHITE"\n\
======================================================\n\
[Move camera] w s a d    [Rotate camera] i k j l m n  \n\
[Move light] f t g h y u [Change color] 1 2 3 4 5 6 7 \n\
[Zoom] z x [Pause] space [Reset] r [Quit] q           \n\
======================================================\n");
		printf("%s", data->config.color);
		flg = false;
	}
	else
	{
		printf("\n\
                                                      \n\
                                                      \n\
                                                      \n\
                                                      \n\
                                                      \n");
		flg = true;
	}
}

void	light_move_front(t_data *data)
{
	data->light.pos = vect_new(0, 0, -MOVE_LIGHT);
}

void	light_move_back(t_data *data)
{
	data->light.pos = vect_new(0, 0, MOVE_LIGHT);
}
