#include "fractol.h"

void	zoom_in(int x, int y, t_mlx *coord)
{
	coord->scale_factor = ft_double_atoi(coord->scale_arg);
	coord->x1 =  x * coord->scale_factor;
	coord->y1 = y * coord->scale_factor;
}

void	zoom_out(int x, int y, t_mlx *coord)
{
	x = x / coord->scale_factor;
	y = y / coord->scale_factor;
}

int	close(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

void	mouse_hook(int mousecode, int x, int y, t_mlx *coord)
{
	if (mousecode == 4)
		zoom_in(x, y, coord);
	else if (keycode == 5)
		zoom_out(x, y, coord);
}

void	key_hook(int keycode, t_mlx *coord, t_data *data)
{
	else if (keycode == 53)
		mlx_hook(data->win, 53, 1L<<0, close, data);
}
