#include "../../includes/ultimate.h"
#include <mlx.h>

void mlx_start()
{
	g_data.mlx.mlx = mlx_init();
	g_data.mlx.win = mlx_new_window(g_data.mlx.mlx, g_data.Swidth, g_data.Sheight, "asd");
}

int closewin(int keycode, t_mlx *mlx)
{
	keycode = 12;
	mlx_destroy_window(mlx->mlx, mlx->win);
	return (1);
}

int	color_to_int(t_color *c)
{
	return ((c->R << 16) + (c->G << 8) + c->B);
}

void mlx_put_color(int c, int x, int y)
{
	mlx_pixel_put(g_data.mlx.mlx, g_data.mlx.win, x, y, c);
}

void get_image(t_cam *c)
{
	int h;
	int w;
	t_line *l;
	t_point p;

	ChangeCords(c);
	mlx_start();
	h = 0;
	while(h++ < g_data.Sheight && !(w = 0))
	{
		while(w++ < g_data.Swidth)
		{
			p.x = (w - g_data.Swidth / 2.0) * 1 / g_data.Swidth;
			p.y = (g_data.Sheight / 2.0 - h) * 1 / g_data.Sheight;
			p.z = 1;
			l = makelinep(&(c->p), &p);
			mlx_put_color(CheckObjects(l), w, h);
			free(l);
		}
	}
}