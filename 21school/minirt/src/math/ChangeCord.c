#include "../../includes/ultimate.h"

void ChangeCordSphere(t_sphere *s, int x, int y, int z)
{
	s->center.x -= x;
	s->center.y -= y;
	s->center.z -= z;
}

void ChangeCordObj(int x, int y, int z)
{
	t_obj *o;

	o = g_data.objects;
	while(o)
	{
		if (o->type == 1)
			ChangeCordSphere(o->obj, x, y ,z);
		o = o->next;
	}
}

void ChangeCordlight(int x, int y, int z)
{
	t_light *l;
	
	l = g_data.lights;
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
	ChangeCordObj(c->p.x, c->p.y, c->p.z);
	ChangeCordlight(c->p.x, c->p.y, c->p.z);
	c->p.x = 0;
	c->p.y = 0;
	c->p.z = 0;
	RotateCord(c);
}