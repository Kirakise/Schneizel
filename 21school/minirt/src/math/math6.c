#include "../../includes/ultimate.h"

double CheckSquare(t_line *l, t_square *s)
{
	t_plane p;
	double res;
	t_point p1;

	res = NAN;
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
	return (CheckSquare3(s, p1, res));
}

double CheckSquare3(t_square *s, t_point p1, double res)
{
	if ((s->p1.x - p1.x) * (s->p4.y - s->p1.y) - (s->p4.x - s->p1.x) * (s->p1.y - p1.y) >= 0 &&
		(s->p4.x - p1.x) * (s->p3.y - s->p4.y) - (s->p3.x - s->p4.x) * (s->p4.y - p1.y) >= 0 &&
		(s->p3.x - p1.x) * (s->p1.y - s->p3.y) - (s->p1.x - s->p3.x) * (s->p3.y - p1.y) >= 0)
		return (res);
	if ((s->p1.x - p1.x) * (s->p4.y - s->p1.y) - (s->p4.x - s->p1.x) * (s->p1.y - p1.y) <= 0 &&
		(s->p4.x - p1.x) * (s->p3.y - s->p4.y) - (s->p3.x - s->p4.x) * (s->p4.y - p1.y) <= 0 &&
		(s->p3.x - p1.x) * (s->p1.y - s->p3.y) - (s->p1.x - s->p3.x) * (s->p3.y - p1.y) <= 0)
		return (res);
	return (CheckSquare4(s, p1, res));
}

double CheckSquare4(t_square *s, t_point p1, double res)
{
	if ((s->p1.x - p1.x) * (s->p4.y - s->p1.y) - (s->p4.x - s->p1.x) * (s->p1.y - p1.y) >= 0 &&
		(s->p4.x - p1.x) * (s->p3.y - s->p4.y) - (s->p3.x - s->p4.x) * (s->p4.y - p1.y) >= 0 &&
		(s->p3.x - p1.x) * (s->p1.y - s->p3.y) - (s->p1.x - s->p3.x) * (s->p3.y - p1.y) >= 0)
		return (res);
	if ((s->p1.x - p1.x) * (s->p4.y - s->p1.y) - (s->p4.x - s->p1.x) * (s->p1.y - p1.y) <= 0 &&
		(s->p4.x - p1.x) * (s->p3.y - s->p4.y) - (s->p3.x - s->p4.x) * (s->p4.y - p1.y) <= 0 &&
		(s->p3.x - p1.x) * (s->p1.y - s->p3.y) - (s->p1.x - s->p3.x) * (s->p3.y - p1.y) <= 0)
		return (res);
	return (NAN);
}