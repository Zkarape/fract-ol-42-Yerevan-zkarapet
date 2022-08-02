#include "fractol.h"

//void	zoom_in(int x, int y, t_mlx *coord)
//{
//	coord->r = x + (coord->x - coord->width / 2) * coord->scale_factor;
//	coord->i = y - (coord->y - coord->height / 2) * coord->scale_factor;
//}
//
//void	zoom_out(int x, int y, t_mlx *coord)
//{
//	coord->x = (coord->r - x) / coord->scale_factor + coord->width / 2;
//	coord->y = (y - coord->i) / coord->scale_factor + coord->height / 2;
//}

void	zoom_in(int x, int y, t_mlx *coord)
{
	coord->r = (x / coord->scale_factor + coord->r) - (x / coord->scale_factor);
	printf("%d %f x == %d\n", __LINE__, coord->r, x);
	coord->i = (y / coord->scale_factor + coord->i) - (y / coord->scale_factor);
	printf("%d %f y == %d\n", __LINE__, coord->i, y);
}

void	zoom_out(int x, int y, t_mlx *coord)
{
	coord->r = (x / coord->scale_factor + coord->r) - (x * coord->scale_factor);
	printf("%d %f\n", __LINE__, coord->r);
	coord->i = (y / coord->scale_factor + coord->i) - (y * coord->scale_factor);
	printf("%d %f\n", __LINE__, coord->i);
}

int	close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_mlx *coord)
{
	if (mousecode == 4)
		zoom_in(x, y, coord);
	else if (mousecode == 5)
		zoom_out(x, y, coord);
	return (0);
}

void	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		mlx_key_hook(data->win, &close, data);
}
