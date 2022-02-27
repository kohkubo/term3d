#include "draw.h"

extern bool	g_draw_flg;

static void	draw_screen(t_data *data)
{
	int	x;
	int	y;

	printf(TOP_LEFT);
	y = data->base_info.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->base_info.width)
			printf("%c ", data->canvas[y * data->base_info.width + x++]);
		printf("\n");
		y--;
	}
	fflush(stdout);
}

static void	draw_init(t_data *data, t_thread_line **thread_line)
{
	*thread_line = (t_thread_line *)ft_xcalloc(\
	data->base_info.height, sizeof(t_thread_line));
	printf(DISABLE_CURSOR);
	printf(CLEAR_SCREEN);
}

static void	draw_end(t_data *data, t_thread_line *thread_line)
{
	printf(END);
	printf(ENABLE_CURSOR);
	free(thread_line);
	free(data->canvas);
	free(data->object);
}

void	draw(t_data *data)
{
	t_thread_line	*thread_line;

	thread_line = NULL;
	draw_init(data, &thread_line);
	while (g_draw_flg)
	{
		thread_store_canvas(data, thread_line);
		draw_screen(data);
		key_control(data);
		rotate(data);
	}
	draw_end(data, thread_line);
}
