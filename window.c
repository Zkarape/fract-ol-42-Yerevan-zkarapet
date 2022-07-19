#include <mlx.h>

int main()
{
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fract'ol");
	char *path_to_img = "/Users/zkarapet/Desktop/img.png";
	int i = 0,x = 200, y = 200;
	while (i < 20)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 072551);
		x++;
		y++;
		i++;
	}
	//mlx_png_file_to_image(mlx_ptr, path_to_img, 748, 953);
	//void *img_ptr = mlx_new_image(mlx_ptr, 200, 200);
//	mlx_get_data_addr(img_ptr, 6, 8, 1);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}
