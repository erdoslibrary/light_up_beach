
#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "structures.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}			t_data;

/* Core Functions */
void		init_minirt(t_data *data);
void		events_init(t_data *data);
void		clean_exit(t_data *data);

/* Event Handlers */
int			key_handler(int keysym, t_data *data);
int			close_handler(t_data *data);

/* Rendering Functions */
void		render_minirt(t_data *data);
void		my_pixel_put(int x, int y, t_img *img, int color);

/* Utils */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
