
#include "minirt.h"

static void malloc_error(void) 
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void events_init(t_data *data) 
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_handler, data);
}

void init_minirt(t_data *data) 
{
	data->mlx = mlx_init();
	if (NULL == data->mlx)
		malloc_error();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "miniRT");
	if (NULL == data->win) 
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_error();
	}
	data->img.img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (NULL == data->img.img_ptr) 
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_error();
	}
	data->img.pixels_ptr = mlx_get_data_addr(data->img.img_ptr, 
				&data->img.bpp, &data->img.line_len, &data->img.endian);
	events_init(data);
}
