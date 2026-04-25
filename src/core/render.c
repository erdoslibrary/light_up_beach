
#include "minirt.h"

/* 메모리에 있는 이미지 버퍼에 색깔 값을 쓰는 함수*/
// 2차원 좌표를 1차원 메모리 주소로 변환하는 수학 공식
void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
// 이 함수를 사용하지 않고 직접 점을 찍는 코드로 작성하면,
// 화면이 매번 갱신되어 깜빡임 현상이 발생하고 매우 느려진다.

void	render_minirt(t_data *data)
{
	if (data->win && data->img.img_ptr)
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
