#include "../../includes/ultimate.h"

int	EqPoint(t_point *p1, t_point *p2)
{
	if (De(p1->x, p2->x))
		return (0);
	if (De(p1->y, p2->y))
		return (0);
	if (De(p1->z, p2->z))
		return (0);
	return (1);
}

int De(double d1, double d2)
{
	if (d1 < d2 - delta)
		return (-1);
	if (d1 > d2 + delta)
		return (1);
	return (0);
}

t_vector GetVectorOfLine(t_line *v)
{
	t_vector t;

	t.x = v->xmul;
	t.y = v->ymul;
	t.z = v->zmul;
	return (t);
}