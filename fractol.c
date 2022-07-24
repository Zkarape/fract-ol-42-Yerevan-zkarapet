#include <stdio.h>
#include <mlx.h>

double mapx(double x, int width, double minR, double maxR)
{
	return (x * (maxR - minR) / width + minR);
}

double mapy(double y, int height, double minI, double maxI)
{
	return (y * (maxI - minI) / height + minI);
}

int main()
{
	void *mlx_ptr = mlx_init();
	void *win = mlx_new_window(mlx_ptr, 500, 500, "title");
	int	x = 0;
	int y = 0;
	int maxIter = 30;
	int i = 0;
	int w = 500;
	int h = 500;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			double	cr = mapx(x, 500, -2, 2);
			double	ci = mapy(y, 500, -2, 2);
			double	cr0 = cr;
			double	ci0 = ci;
			while (i < maxIter)
			{
				double	zr = cr * cr - ci * ci;
				double	zi = 2 * cr * ci;
				cr = zr + cr0;
				ci = zi + ci0;
				if (cr + ci > 2)
					break;
				printf("%d %d\n", x, y);
				i++;
			}
			if (i == maxIter)
			{
				mlx_pixel_put(mlx_ptr, win, x, y, 0xFFFFFF);
			}
			y++;
		}
		x++;
	}
	mlx_loop(mlx_ptr);
}
