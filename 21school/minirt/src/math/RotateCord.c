#include "../../includes/ultimate.h"

void RotateCord(t_cam *c)
{
	double angle1;
	double angle2;

	//if (c->v.z < 0)
	//	RotateAll(pi_num, 0, c);
	angle1 = c->v.y != 0 ? atan(c->v.y / c->v.z) : 0;
	angle2 = c->v.x != 0 ? asin((c->v.x) / VectorModule(&(c->v))) : 0;
	RotateAll(angle1, angle2, c);
}

void Rotatelights(double angle1, double angle2)
{
	t_light *l;

	l = g_data.lights;
	while (l)
	{
		RotateXP(&(l->p), angle1);
		RotateYP(&(l->p), angle2);
		l = l->next;
	}
}

void Rotateobjects(double angle1, double angle2)
{
	t_obj *o;

	o = g_data.objects;
	while (o)
	{
		if (o->type == 1)
			RotateSphere(angle1, angle2, o->obj);
		o = o->next;
	}
}

void RotateCam(double angle1, double angle2, t_cam *c)
{
	RotateXP(&(c->p), angle1);
	RotateYP(&(c->p), angle2);
	RotateXV(&(c->v), angle1);
	RotateYV(&(c->v), angle2);
}

void RotateSphere(double angle1, double angle2, t_sphere *s)
{
	RotateXP(&(s->center), angle1);
	RotateYP(&(s->center), angle2);
}