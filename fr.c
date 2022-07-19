#include <stdio.h>
#include "fractol.h"
#include <mlx.h>
//from real to complex
int	fractol(float x, float y)
{
	float	x_c;//x_complex
	float	y_c;//y_complex
	int		n;
	int 	k = 0;

	n = 0;
//	void *mlx_ptr = mlx_init();
//	void *win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fract'ol");
	while(n++ < 100)
	{
		x_c = x * x - y * y;
		y_c = 2 * x * y;
		x = x_c + x;
		y = y_c + y;
		if (x_c * x_c + y_c * y_c > 4)
			break;
		//mlx_pixel_put(mlx_ptr, win_ptr, x, y, 072551);
		k++;
	}
//	mlx_loop(mlx_ptr);
	return (k);
}

int main()
{
	int b = fractol(1, 0);
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fract'ol");
//	char *path_to_img = "/Users/zkarapet/Desktop/img.png";
//	int i = 0,x = 200, y = 200;
//	while (i < 20)
//	{
	if (b != 0)
		mlx_pixel_put(mlx_ptr, win_ptr, 1, 0, 072551);
//		i++;
//	}
//	mlx_png_file_to_image(mlx_ptr, path_to_img, 748, 953);
//	void *img_ptr = mlx_new_image(mlx_ptr, 200, 200);
//	mlx_get_data_addr(img_ptr, 6, 8, 1);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}
