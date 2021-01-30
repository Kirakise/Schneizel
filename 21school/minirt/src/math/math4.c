#include "../../includes/ultimate.h"

t_plane GetPlane(t_point p1, t_point p2, t_point p3)
{
	t_plane p;

	p.v.x = (p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y);
	p.v.y = (p3.x - p1.x) * (p2.z - p1.z) - (p3.z - p1.z) * (p2.x - p1.x);
	p.v.z = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	p.p = p1;
	return (p);
}

double CheckTriangle(t_line *l, t_triangle *t)
{
	t_plane p;
	double	res;
	t_point p1;

	p = GetPlane(t->p1, t->p2, t->p3);
	res = CheckPlane(l,&p);
	p1 = *getpointonline(l, res);
	if (isnan(res))
		return (res);
	if ((t->p1.x - p1.x) * (t->p2.y - t->p1.y) - (t->p2.x - t->p1.x) * (t->p1.y - p1.y) >= 0 &&
		(t->p2.x - p1.x) * (t->p3.y - t->p2.y) - (t->p3.x - t->p2.x) * (t->p2.y - p1.y) >= 0 &&
		(t->p3.x - p1.x) * (t->p1.y - t->p3.y) - (t->p1.x - t->p3.x) * (t->p3.y - p1.y) >= 0)
		return (res);
	if ((t->p1.x - p1.x) * (t->p2.y - t->p1.y) - (t->p2.x - t->p1.x) * (t->p1.y - p1.y) <= 0 &&
		(t->p2.x - p1.x) * (t->p3.y - t->p2.y) - (t->p3.x - t->p2.x) * (t->p2.y - p1.y) <= 0 &&
		(t->p3.x - p1.x) * (t->p1.y - t->p3.y) - (t->p1.x - t->p3.x) * (t->p3.y - p1.y) <= 0)
		return (res);
	return (NAN);
}

double CheckSquare(t_line *l, t_square *s)
{
	t_plane p;
	double res;
	t_point p1;

	p = GetPlane(s->p1, s->p2, s->p3);
	res = CheckPlane(l, &p);
	if (isnan(res))
		return (res);
	p1 = *getpointonline(l, res);
	if ((s->p1.x - p1.x) * (s->p2.y - s->p1.y) - (s->p2.x - s->p1.x) * (s->p1.y - p1.y) >= 0 &&
		(s->p2.x - p1.x) * (s->p3.y - s->p2.y) - (s->p3.x - s->p2.x) * (s->p2.y - p1.y) >= 0 &&
		(s->p3.x - p1.x) * (s->p1.y - s->p3.y) - (s->p1.x - s->p3.x) * (s->p3.y - p1.y) >= 0)
		return (res);
	if ((s->p1.x - p1.x) * (s->p2.y - s->p1.y) - (s->p2.x - s->p1.x) * (s->p1.y - p1.y) <= 0 &&
		(s->p2.x - p1.x) * (s->p3.y - s->p2.y) - (s->p3.x - s->p2.x) * (s->p2.y - p1.y) <= 0 &&
		(s->p3.x - p1.x) * (s->p1.y - s->p3.y) - (s->p1.x - s->p3.x) * (s->p3.y - p1.y) <= 0)
		return (res);
	return (CheckSquare2(s, p1, res));
}

double CheckSquare2(t_square *s, t_point p1, double res)
{
	if ((s->p1.x - p1.x) * (s->p2.y - s->p1.y) - (s->p2.x - s->p1.x) * (s->p1.y - p1.y) >= 0 &&
		(s->p2.x - p1.x) * (s->p3.y - s->p2.y) - (s->p3.x - s->p2.x) * (s->p2.y - p1.y) >= 0 &&
		(s->p3.x - p1.x) * (s->p1.y - s->p3.y) - (s->p1.x - s->p3.x) * (s->p3.y - p1.y) >= 0)
		return (res);
	if ((s->p1.x - p1.x) * (s->p2.y - s->p1.y) - (s->p2.x - s->p1.x) * (s->p1.y - p1.y) <= 0 &&
		(s->p2.x - p1.x) * (s->p3.y - s->p2.y) - (s->p3.x - s->p2.x) * (s->p2.y - p1.y) <= 0 &&
		(s->p3.x - p1.x) * (s->p1.y - s->p3.y) - (s->p1.x - s->p3.x) * (s->p3.y - p1.y) <= 0)
		return (res);
	return (NAN);
}