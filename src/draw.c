#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	int		memory_offset;
	char	*get_data;

	memory_offset = y * data->line_length + x * (data->bpp / 8);
	get_data = data->addr + memory_offset;
	*(unsigned int *)get_data = color;
}

