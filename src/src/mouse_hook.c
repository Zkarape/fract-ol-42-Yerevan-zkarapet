#include "fractol.h"

//void	zoom_in(int x, int y, t_mlx *coord)
//{
//	coord->r = x + (coord->x - coord->width / 2) * coord->scale_factor;
//	coord->i = y - (coord->y - coord->height / 2) * coord->scale_factor;
//	coord->scale_factor *= 2;
//	coord->maxiter++;
//}
//
//void	zoom_out(int x, int y, t_mlx *coord)
//{
//	coord->x = (coord->r - x) / coord->scale_factor + coord->width / 2;
//	coord->y = (y - coord->i) / coord->scale_factor + coord->height / 2;
//	coord->scale_factor /= 2;
//	coord->maxiter--;
//}

void	zoom_in(int x, int y, t_mlx *coord)
{
	coord->r = ((double)x / coord->scale_factor + coord->r) - ((double)x / coord->scale_factor * 1.3);
	coord->i = ((double)y / coord->scale_factor + coord->i) - ((double)y / coord->scale_factor * 1.3);
	coord->scale_factor *= 1.3;
	coord->maxiter++;
}

void	zoom_out(int x, int y, t_mlx *coord)
{
	coord->r = ((double)x / coord->scale_factor + coord->r) - ((double)x / coord->scale_factor / 1.3);
	coord->i = ((double)y / coord->scale_factor + coord->i) - ((double)y / coord->scale_factor / 1.3);
	coord->scale_factor /= 1.3;
	coord->maxiter--;
}

int	mouse_hook(int mousecode, int x, int y, t_mlx *coord)
{
	int		palette[8] = {0x8A39E1, 0xF1D00A, 0x2EB086, 0x54BAB9,
		0x5FD068, 0xFAC213, 0xFF06B7, 0xD4D925};
	if (mousecode == 5)
		zoom_in(x, y, coord);
	else if (mousecode == 4)
		zoom_out(x, y, coord);
	mandelbrot(palette, coord, coord->data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	return (0);
}
