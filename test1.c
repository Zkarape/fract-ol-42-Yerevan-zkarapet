#include <mlx.h>

int main()
{
	void *mlx_ptr = mlx_init();
	void *win = mlx_new_window(mlx_ptr, 200, 200, "title");
	mlx_loop(mlx_ptr);
}
