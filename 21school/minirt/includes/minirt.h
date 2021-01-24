#ifndef MINIRT_H
# define MINIRT_H
# include "my_math.h"
# include <mlx.h>
# define DIST 0.1

typedef struct	s_obj
{
	void *obj;
	int	type;
	struct s_obj *next;
}				t_obj;

typedef struct	s_cam
{
	t_point			p;
	t_vector		v;
	int				fow;
	struct s_cam *next;
}				t_cam;

typedef struct	s_light
{
	t_point		p;
	double		brightness;
	t_color		color;
	struct s_light *next;
}				t_light;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;


typedef struct	s_data{
	t_obj *objects;
	t_cam *cams;
	t_light *lights;
	t_mlx	mlx;
	double	alratio;
	t_color	alcolor;
	int		Swidth;
	int		Sheight;
	int		Save;
}				t_data;

t_data			g_data;
#endif