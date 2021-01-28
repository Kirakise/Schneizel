#ifndef MY_MATH_H
# define MY_MATH_H
#include <math.h>
#define pi_num 3.1415926
#define delta  0.001
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
	double		res;
	t_color		color;
}				t_result;

typedef struct	s_cam
{
	t_point			p;
	t_vector		v;
	int				fow;
	struct s_cam *next;
}				t_cam;

double trunc(double d);
t_point		*getpointonline(t_line *l, double t);
t_line		*makeline(t_point *p, t_vector *v);
double		distance(t_point *t1, t_point *t2);
t_result	*CheckPlane(t_line *l, t_plane *p);
double		CheckSphere(t_line *l, t_sphere *s);
t_line		*makelinep(t_point *p1, t_point *p2);
void ChangeCords(t_cam *c);
void RotateZV(t_vector *v, double angle);
void RotateYV(t_vector *v, double angle);
void RotateXV(t_vector *v, double angle);
double GetAngle(t_vector *v1, t_vector *v2);
void RotateXP(t_point *v, double angle);
void RotateYP(t_point *v, double angle);
void RotateZP(t_point *v, double angle);
void RotateCord(t_cam *c);
void Rotatelights(double angle1, double angle2);
void Rotateobjects(double angle1, double angle2);
void RotateCam(double angle1, double angle2, t_cam *c);
void RotateSphere(double angle1, double angle2, t_sphere *s);
double VectorModule(t_vector *t);
void RotateAll(double angle1, double angle2, t_cam *c);
void		makecolor(t_color *c, int R, int G, int B);
int	EqPoint(t_point *p1, t_point *p2);
int De(double d1, double d2);
t_vector GetVectorOfLine(t_line *v);
void AddLightColor(t_color *c, double light);
#endif