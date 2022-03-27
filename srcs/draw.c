#include "draw.h"

volatile sig_atomic_t	g_draw_flg = 1;

static void	draw_screen(t_data *data)
{
	printf(TOP_LEFT);
	puts(data->canvas);
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
