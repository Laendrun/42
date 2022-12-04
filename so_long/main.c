#include "mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point {
	int	x;
	int	y;
}				t_point;

void	put_mlx_pixel(t_data *data, int x, int y, int color);
void	draw_rect(t_data *img, t_point start, t_point end, int color);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	t_point	start;
	t_point	end;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "so_long");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	start.x = 5;
	start.y = 5;
	end.x = 10;
	end.y = 10;
	draw_rect(&img, start, end, 0x00FF0000);
	start.x = 10;
	start.y = 10;
	end.x = 250;
	end.y = 25;
	draw_rect(&img, start, end, 0x000000FF);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	printf("Hello world, minilbx test !\n");
	return (0);
}

void	draw_rect(t_data *img, t_point start, t_point end, int color)
{
	size_t	i;

	i = start.x;
	while (start.y <= end.y)
	{
		while (i <= end.x)
		{
			put_mlx_pixel(img, i, start.y, color);
			i++;
		}
		i = start.x;
		start.y++;
	}

	put_mlx_pixel(img, start.x, start.y, color);
	put_mlx_pixel(img, end.x, end.y, color);
}

void	put_mlx_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}