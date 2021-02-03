#include "../../includes/ultimate.h"

void ChangeCordSphere(t_sphere *s, double x, double y, double z)
{
	s->center.x -= x;
	s->center.y -= y;
	s->center.z -= z;
}

void ChangeCordObj(double x, double y, double z)
{
	t_obj *o;

	o = g_data.objects->next;
	while(o)
	{
		if (o->type == 1)
			ChangeCordSphere(o->obj, x, y ,z);
		else if (o->type == 2)
			ChangeCordPlane(o->obj, x, y, z);
		else if (o->type == 3)
			ChangeCordSquare(o->obj, x, y, z);
		else if (o->type == 4)
			ChangeCordCylinder(o->obj, x, y, z);
		else if (o->type == 5)
			ChangeCordTriangle(o->obj, x, y, z);
		o = o->next;
	}
}

void ChangeCordlight(double x, double y, double z)
{
	t_light *l;
	
	l = g_data.lights->next;
	while (l)
	{
		l->p.x -= x;
		l->p.y -= y;
		l->p.z -= z;
		l = l->next;
	}
}


void ChangeCords(t_cam *c)
{
	double x;
	double y;
	double z;
	t_cam *tmp;

	tmp = g_data.cams->next;
	x = c->p.x;
	y = c->p.y;
	z = c->p.z;
	ChangeCordObj(c->p.x, c->p.y, c->p.z);
	ChangeCordlight(c->p.x, c->p.y, c->p.z);
	while (tmp)
	{
		tmp->p.x -= x;
		tmp->p.y -= y;
		tmp->p.z -= z;
		tmp = tmp->next;
	}
	RotateCord(c);
}

void ChangeCordPlane(t_plane *p, double x, double y, double z)
{
	p->p.x -= x;
	p->p.y -= y;
	p->p.z -= z;
}