#include <mlx.h>
#include <math.h>

#define roundf(x) floor(x + 0.5f);

void 	line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int dx = (x2 - x1 >= 0 ? 1 : -1);
	int dy = (y2 - y1 >= 0 ? 1 : -1);

	int lengthX = abs(x2 - x1);
	int lengthY = abs(y2 - y1);

	int length = max(lengthX, lengthY);

	if (length == 0)
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);

	if (lengthY <= lengthX)
	{
		//Start values
		int x = x1;
		int y = y1;
		int d = -lengthX;

		//Main loop
		length++;
		while (length--)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			x += dx;
			d += 2 * lengthY;
			if (d > 0)
			{
				d -= 2 * lengthX;
				y += dy;
			}
		}
	}
	else
	{
		//Start values
		int x = x1;
		int y = y1;
		int d = -lengthY;

		//Main loop
		length++;
		while (length--)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			y += dy;
			d += 2 * lengthX;
			if (d > 0)
			{
				d -= 2 * lengthY;
				x += dx;
			}
		}
	}
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	line(mlx_ptr, win_ptr, 15, 15, 235,235);
	mlx_loop(mlx_ptr);
}
