#include "../../includes/ultimate.h"
#include <mlx.h>
#include <stdio.h>
void mlx_start()
{
	g_data.mlx.mlx = mlx_init();
	g_data.mlx.win = mlx_new_window(g_data.mlx.mlx, g_data.Swidth, g_data.Sheight, "asd");
}

int closewin(int keycode, t_mlx *mlx)
{
	g_data.camcur = g_data.cams->next;
	g_data.objcur = g_data.objects->next;
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	else if (keycode == 8)
	{
		if (g_data.camcur->next)
			g_data.camcur = g_data.camcur->next;
		else
			g_data.camcur = g_data.cams->next;
		get_image(g_data.camcur);
	}
	else if (keycode == 31)
	{
		g_data.objcur = g_data.objcur->next;
		if (!g_data.objcur)
			g_data.objcur = g_data.objects;
	}
	control2(keycode);
	return (1);
}

void control2(int keycode)
{
	if (keycode == 24 || keycode == 27)
	{
		resizeobj(g_data.objcur, keycode == 24 ? 1 : -1);
		get_image(g_data.camcur);
	}
	else if (keycode == 12 || keycode == 14)
	{
		RotateObj(g_data.objcur, keycode == 12 ? -0.1 : 0.1);
		get_image(g_data.camcur);
	}
	else if (keycode == 15 || keycode == 17)
	{
		RotateCam(keycode == 15 ? -0.1 : 0.1, 0, g_data.camcur);
		get_image(g_data.camcur);
	}
}

void resizeobj(t_obj *o, double d)
{
	if (o->type == 1)
		((t_sphere *)o->obj)->radius += d;
	else if (o->type == 3)
		((t_square *)o->obj)->side += d;
	else if (o->type == 4)
		((t_cylinder *)o->obj)->radius += d; 
}