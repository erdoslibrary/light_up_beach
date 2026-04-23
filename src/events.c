
#include "minirt.h"

int key_handler(int keysym, t_data *data) 
{
	if (keysym == XK_Escape)
	close_handler(data);
	return (0);
}

int close_handler(t_data *data) 
{
	clean_exit(data);
	return (0);
}
