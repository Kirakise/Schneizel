/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:51:25 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:51:38 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "my_math.h"
# include <mlx.h>

# define DIST 0.1

typedef struct		s_obj
{
	void			*obj;
	int				type;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_light
{
	t_point			p;
	double			brightness;
	t_color			color;
	struct s_light	*next;
}					t_light;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct		s_data{
	t_obj			*objects;
	t_cam			*camcur;
	t_obj			*objcur;
	t_cam			*cams;
	t_light			*lights;
	t_mlx			mlx;
	double			alratio;
	t_color			alcolor;
	int				swidth;
	int				sheight;
	int				save;
}					t_data;
int					closewin2(int a);
#endif
