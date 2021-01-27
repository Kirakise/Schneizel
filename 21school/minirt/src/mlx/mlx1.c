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

void get_image(t_cam *c)
{
	int h;
	int w;
	t_line *l;
	t_point p;

	ChangeCords(c);
	mlx_start();
	h = 1;
	w = 0;
	while(h++ < g_data.Sheight)
	{
		while(w++ < g_data.Swidth)
		{
			p.x = w;
			p.y = h;
			p.z = 1;
			l = makelinep(&(c->p), &p);
			if (!isnan(CheckSphere(l, g_data.objects->next->obj)->t1) || 1)
				mlx_pixel_put(g_data.mlx.mlx, g_data.mlx.win, w, h, 0x00FFFFFF);
		}
	}
}