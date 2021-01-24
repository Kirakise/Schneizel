#include "../includes/ultimate.h"

int initialize()
{
	g_data.objects = objconst();
	g_data.cams = camconst();
	g_data.lights = lightconst();
	if (!g_data.objects || !g_data.cams || !g_data.lights)
		return (0);
	g_data.alratio = -1;
	g_data.alcolor.R = -1;
	g_data.alcolor.G = -1;
	g_data.alcolor.B = -1;
	g_data.Swidth = -1;
	g_data.Sheight = -1;
	g_data.Save = 0;
	return (1);
}

int main(int args, char **argv)
{
	if (!initialize())
		return (-1);
	if (args > 3 || parsefile(argv[1]) == -1 || args <= 1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	g_data.mlx.mlx = mlx_init();
	g_data.mlx.win = mlx_new_window(g_data.mlx.mlx, g_data.Swidth, g_data.Sheight, "Some nasty shit");
	mlx_pixel_put(g_data.mlx.mlx, g_data.mlx.win, 100, 80, 0xFFFFFF0);
	mlx_loop(g_data.mlx.mlx);
}
