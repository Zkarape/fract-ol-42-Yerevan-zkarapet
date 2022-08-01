#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		a;
}				t_vars;

int	key_hook(int x, int y, t_vars *vars)
{
	vars->a = 8;
	printf("%d %d\n", x, y);
	return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
	if (button == 4 || button == 1)
		key_hook(x, y, param);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_mouse_hook(vars.win, &mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
