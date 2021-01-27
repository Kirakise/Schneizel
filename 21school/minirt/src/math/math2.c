#include "../../includes/ultimate.h"

double		distance(t_point *t1, t_point *t2)
{
	return (sqrt(pow(t2->x - t1->x, 2) + pow(t2->y - t1->y, 2) + pow(t2->z - t1->z, 2)));
}

t_line		*makeline(t_point *p, t_vector *v)
{
	t_line	*l;

	l = malloc(sizeof(struct s_line));
	l->xmul = v->x;
	l->xadd = p->x;
	l->ymul = v->y;
	l->yadd = p->y;
	l->zmul = v->z;
	l->zadd = p->z;

	return  (l);
}

t_point		*getpointonline(t_line *l, int t)
{
	t_point	*p;

	p = malloc(sizeof(struct s_point));
	p->x = l->xmul * t + l->xadd;
	p->y = l->ymul * t + l->yadd;
	p->z = l->zmul * t + l->zadd;
	return (p);
}