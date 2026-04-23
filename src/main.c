
#include "minirt.h"

int main(void) 
{
	t_data data;

	init_minirt(&data);
	render_minirt(&data);
	mlx_loop(data.mlx);
	return (0);
}
