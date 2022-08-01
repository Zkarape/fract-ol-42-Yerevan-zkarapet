#include <stdio.h>
#include <mlx.h>

double mapx(double x, int width, double minR, double maxR)
{
	return ((x * (maxR - minR) / width) + minR);
}

double mapy(double y, int height, double minI, double maxI)
{
	return ((y * (maxI - minI) / height) + minI);
}

double map(double x, double in_min, double in_max, double out_min, double out_max)
{
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

int main()
{
	void *mlx_ptr = mlx_init();
	void *win = mlx_new_window(mlx_ptr, 1000, 1000, "title");
	int	x = 0;
	int y = 0;
	int maxIter = 100;
	int i = 0;
	int w = 800;
	int h = 800;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			double	cr = map(x, 0, 800, -2, 2);
			double	ci = map(y, 0, 800, -2, 2);
			double	cr0 = cr;
			double	ci0 = ci;
			while (i < maxIter)
			{
				double	zr = cr * cr - ci * ci;
				double	zi = 2 * cr * ci;
				cr = zr + cr0;
				ci = zi + ci0;
				if (cr + ci > 2)
					break ;
				i++;
			}
			if (i == maxIter)
				mlx_pixel_put(mlx_ptr, win, x, y, 0xFFFFFF);
			else
				mlx_pixel_put(mlx_ptr, win, x, y, 0x42FF00);
			y++;
		}
		x++;
	}
	mlx_loop(mlx_ptr);
}
