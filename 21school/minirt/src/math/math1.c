#include "../../includes/ultimate.h"
#include <math.h>

t_result	*CheckSphere(t_line *l, t_sphere *s)
{
	double		k1;
	double		k2;
	double		k3;
	t_result	*r;

	r = malloc(sizeof(struct s_result));
	r->nan = 0;
	k1 = pow(l->xmul, 2) + pow(l->ymul, 2) + pow(l->zmul, 2);
	k2 = l->xmul * (l->xadd - s->center.x) + l->ymul * (l->yadd - s->center.y) + l->zmul * (l->zadd - s->center.z);
	k3 = pow(l->xadd - s->center.x, 2) + pow(l->yadd - s->center.y, 2) + pow(l->zadd - s->center.z, 2);
	if (((k1 == 0 && k2 == 0) || k2*k2 - 4*k1*k3 < 0) && (r->nan = 1))
		return (r);
	if (k1 == 0)
	{
		r->t1 = -k3/k2;
		r->t2 = r->t1;
		return (r);
	}
	r->t1 = (-k2 + sqrt(k2 * k2 - k1 * k3)) / k1;
	r->t2 = (-k2 - sqrt(k2 * k2 - k1 * k3)) / k1;
	return (r);
}

t_result	*CheckPlane(t_line *l, t_plane *p)
{
	double		d;
	t_result	*r;
	double		k1;
	
	r = malloc(sizeof(struct s_result));
	r->nan = 0;
	d = p->v.x * p->p.x + p->v.y * p->p.y + p->v.z * p->p.z;
	k1 = p->v.x * l->xmul + p->v.y * l->ymul + p->v.z * l->zmul;
	if (k1 == 0)
	{
		r->nan = 1;
		return (r);
	}
	r->t1 = d - p->v.x * l->xadd - p->v.y * l->yadd - p->v.z * l->zadd;
	return (r);
}

