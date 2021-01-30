#include "../../includes/ultimate.h"

void RotateLine(t_line *l, double angle1, double angle2)
{
	t_vector	v;
	t_point		p;
	v.x = l->xmul;
	v.y = l->ymul;
	v.z = l->zmul;
	p.x = l->xadd;
	p.y = l->yadd;
	p.z = l->zadd;
	RotateXV(&(v), angle1);
	RotateYV(&(v), angle2);
	RotateXP(&(p), angle1);
	RotateYP(&(p), angle2);
	l->xmul = v.x;
	l->xadd = p.x;
	l->ymul = v.y;
	l->yadd = p.y;
	l->zmul = v.z;
	l->zadd = p.z;
}

void RotateTriangle(t_triangle *t, double angle1, double angle2)
{
	RotateXP(&(t->p1), angle1);
	RotateYP(&(t->p1), angle2);
	RotateXP(&(t->p2), angle1);
	RotateYP(&(t->p2), angle2);
	RotateXP(&(t->p3), angle1);
	RotateYP(&(t->p3), angle2);
	RotateXV(&(t->v), angle1);
	RotateYV(&(t->v), angle2);
}