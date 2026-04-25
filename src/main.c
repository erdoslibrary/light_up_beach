
#include "minirt.h"

/* 파싱 없이 하드코딩할 도형/광원/주변광 세팅*/
static t_scene	*scene_tmp(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*light;
	double		ka;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(WIDTH, HEIGHT);
	scene->camera = camera(&scene->canvas, point(0, 0, 0));
	// world
	// light
	// ambient
}

int	main(void)
{
	t_data	data;

	data.scene = scene_tmp();
	if (!data.scene)
	{
		print("Error\n");
		return (1);
	}
	init_minirt(&data);
	render_minirt(&data);
	mlx_loop(data.mlx);
	return (0);
}
