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
	double		center;
	double		radius;
}				t_sphere;