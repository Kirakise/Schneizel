#ifndef MY_MATH_H
# define MY_MATH_H

typedef struct	s_color
{
	int		R;
	int		G;
	int		B;
}				t_color;

typedef struct	s_vector{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_point{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef	struct	s_line{
	double		xmul;
	double		xadd;
	double		ymul;
	double		yadd;
	double		zmul;
	double		zadd;
}				t_line;

typedef struct	s_sphere{
	t_point		center;
	double		radius;
	t_color		color;
}				t_sphere;

typedef struct	s_plane{
	t_vector	v;
	t_point		p;
	t_color		color;
}				t_plane;

typedef struct	s_result{
	double		t1;
	double		t2;
	int			nan;
}				t_result;
#endif