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
	g_data.alcolor.R = -1;
	g_data.alcolor.G = -1;
	g_data.alcolor.B = -1;
	g_data.Swidth = -1;
	g_data.Sheight = -1;
	g_data.Save = 0;
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
	get_image(g_data.cams->next);
	mlx_hook(g_data.mlx.win, 2, 1L << 0, closewin, &(g_data.mlx));
	mlx_loop(g_data.mlx.mlx);
}
