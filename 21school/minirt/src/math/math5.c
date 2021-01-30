#include "../../includes/ultimate.h"

double CheckCylinder(t_line *l, t_cylinder *c)
{
	double angle1;
	double angle2;
	int tmp;
	double res;

	tmp = 1;
	if (c->v.z < 0)
		tmp = -1;
	angle1 = c->v.y != 0 ? tmp * atan(c->v.y / c->v.z) : 0;
	angle2 = c->v.x != 0 ? tmp * asin((c->v.x) / VectorModule(&(c->v))) : 0;
	RotateCylinder(c, angle1, angle2);
	RotateLine(l, angle1, angle2);
	res = CheckCylinder2(l, c);
	RotateCylinder(c, -angle1, -angle2);
	RotateLine(l, -angle1, -angle2);
	return (res);
}

double CheckCylinder2(t_line *l, t_cylinder *c)
{
	double r1;
	double r2;
	double k1;
	double k2;
	double k3;

	k1 = pow(l->xmul, 2) + pow(l->ymul, 2);
	k2 = l->xmul * (l->xadd - c->p.x) + l->ymul * (l->yadd - c->p.y);
	k3 = pow(l->xadd - c->p.x, 2) + pow(l->yadd - c->p.y, 2) - pow(c->radius, 2);
	r1 = (-k2 + sqrt(k2 * k2 - k1 * k3)) / k1;
	r2 = (-k2 - sqrt(k2 * k2 - k1 * k3)) / k1;
	return (CheckCylinder3(l, c, r1, r2));
}

double CheckCylinder3(t_line *l, t_cylinder *c, double r1, double r2)
{
	t_point p;

	if (r2 <= 1)
		p = *getpointonline(l, r1);
	else
		p = *getpointonline(l, r2);
	if (p.z < (-c->height / 2 - l->xadd) / l->xmul ||
		p.z > (c->height / 2 - l->xadd) / l->xmul)
		return (NAN);
	return (r2 <= 1 ? r2 : r1);
}

t_vector GetVectorFromPlane(t_plane p)
{
	t_vector v;
	v.x = p.v.x;
	v.y = p.v.y;
	v.z = p.v.z;
	return (v);
}