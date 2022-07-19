#include <mlx.h>

int main()//int x, int y
{
	int n = 20;
	int x = 200;
	int y = 200;
	void *mlx_ptr = mlx_init();
	void *win = mlx_new_window(mlx_ptr, 500, 500, "title");
	void *img = mlx_new_image(mlx_ptr, 500, 500);
	int put = mlx_put_image_to_window(mlx_ptr, win, img, 0, 0);
	unsigned int color = mlx_get_color_value(mlx_ptr, 255);
	while (n--)
	{
		mlx_pixel_put(mlx_ptr, win, x, y, 255);
		x--;
		y--;
	}
	mlx_loop(mlx_ptr);
}
