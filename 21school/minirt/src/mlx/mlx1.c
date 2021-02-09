/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:27:34 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:27:35 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"
#include <mlx.h>

int		color_to_int(t_color *c)
{
	return ((c->r << 16) + (c->g << 8) + c->b);
}

void	mlx_put_color(int c, int x, int y)
{
	mlx_pixel_put(g_data.mlx.mlx, g_data.mlx.win, x, y, c);
}

void	get_image(t_cam *c)
{
	int		h;
	int		w;
	t_line	l;
	t_point	p;
	double	tmp;

	tmp = g_data.sheight + g_data.swidth;
	changecords(c);
	h = 0;
	while (h++ < g_data.sheight && !(w = 0))
	{
		while (w++ < g_data.swidth)
		{
			p.x = (w - g_data.swidth / 2.0) * 1 / g_data.swidth;
			p.y = (g_data.sheight / 2.0 - h) * 1 / g_data.sheight;
			p.z = c->v.z * (60 / c->fow);
			l = makelinep(&(c->p), &p);
			mlx_put_color(checkobjects(&l), w, h);
		}
	}
}
