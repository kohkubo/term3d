#include "draw.h"

extern bool	g_draw_flg;

static void	draw_screen(t_data *data)
{
	char	buf[BUFSIZ];
	int		x;
	int		y;

	setbuf(stdout, buf);
	printf(TOP_LEFT);
	printf(DISABLE_CURSOR);
	printf(BOLD);
	printf("%s", data->config.color);
	y = data->camera.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->camera.width)
			printf("%c ", data->canvas[y * data->camera.width + x++]);
		printf("\n");
		y--;
	}
	fflush(stdout);
	printf(END);
	printf(ENABLE_CURSOR);
}

void	draw(t_data *data)
{
	t_thread_line	*thread_line;

	thread_line = (t_thread_line *)ft_xcalloc(\
	data->camera.height, sizeof(t_thread_line));
	while (g_draw_flg)
	{
		thread_store_canvas(data, thread_line);
		draw_screen(data);
		key_control(&data->camera);
		rotate(data);
	}
}
