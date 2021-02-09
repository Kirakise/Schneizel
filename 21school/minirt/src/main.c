/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:30:37 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/03 18:31:38 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ultimate.h"
#include <stdio.h>

t_data	g_data;

int	initialize(void)
{
	g_data.objects = objconst();
	g_data.cams = camconst();
	g_data.lights = lightconst();
	if (!g_data.objects || !g_data.cams || !g_data.lights)
		return (0);
	g_data.alratio = -1;
	g_data.alcolor.r = -1;
	g_data.alcolor.g = -1;
	g_data.alcolor.b = -1;
	g_data.swidth = -1;
	g_data.sheight = -1;
	g_data.save = 0;
	return (1);
}

int	main(int args, char **argv)
{
	if (!initialize())
		return (-1);
	if (args > 3 || parsefile(argv[1]) == -1 || args <= 1)
	{
		ft_putstr("Error with scene\n");
		return (-1);
	}
	mlx_start();
	g_data.camcur = g_data.cams->next;
	get_image(g_data.cams->next);
	mlx_hook(g_data.mlx.win, 2, 1L << 0, closewin, &(g_data.mlx));
	mlx_hook(g_data.mlx.win, 17, 0L, closewin2, 0);
	mlx_loop(g_data.mlx.mlx);
}
