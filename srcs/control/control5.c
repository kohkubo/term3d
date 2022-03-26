#include "control.h"

void	camera_stop(t_data *data)
{
	static double	old_angle = 0;

	if (old_angle == 0)
	{
		old_angle = data->base_info.rotate_angle;
		data->base_info.rotate_angle = 0;
	}
	else
	{
		data->base_info.rotate_angle = old_angle;
		old_angle = 0;
	}
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
=============================================================================\n\
[Move Camera]   Up: w Down: s Left: a Right: d                          	 \n\
[Rotate Camera] Up: i Down: k Left: j Right: l SppedUp: m SpeedDown: n 		 \n\
[Set Light]     Up: t Down: g Left: f Right: h Front: y Back: u			 	 \n\
[Change Color]  Red: 1 Blue: 2 Green: 3 Yellow: 4 Magenta: 5 Cyan: 6 White: 7\n\
[Zoom] In: z Out: x    [Pause] space    [Reset] r    [Quit] q				 \n\
============================================================================\n");
		printf("%s", data->config.color);
		flg = false;
	}
	else
	{
		printf(CLEAR_SCREEN);
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
