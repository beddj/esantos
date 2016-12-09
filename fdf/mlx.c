#include "./minilibx_macos/mlx.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_key_func(int keycode, void *mlx, void *win)
{
	int x,y;
	printf("key event:%d\n", keycode);
	mlx_pixel_put(mlx, win, 150, 150, 0xFFFF00);
	mlx_loop(mlx);
	return (0);
}

int main(int argc, char **argv)
{
	void *mlx;
	void *win;
	int x;
	int y;
	int width;
	int height;

	if(argc != 2)
	{
		return (0);
	}


	height = width = ft_atoi(argv[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx,width, height, "mlx 42");
	y = 0;
/*	while( y <= width)
	{
		x = 0;
		while( x <= height)
		{
			mlx_pixel_put(mlx, win, x, y, 0x0000FF);
			x++;
		}
		y+=25;
	}
	*/
	mlx_pixel_put(mlx, win, 100, 100, 0xFFFF00);
/*	x = 0;
	 while( x <= width)
	{
		y = 0;
		while( y <= height)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFF);
			y++;
		}
		x+=25;
	}
	*/
	mlx_key_hook(win, my_key_func,mlx);
	mlx_loop(mlx);
	return(0);
}
