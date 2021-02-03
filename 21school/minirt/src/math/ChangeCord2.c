#include "../../includes/ultimate.h"

void ChangeCordSquare(t_square *s, double x, double y, double z)
{
	Makepoint(&(s->p1), s->p1.x - x, s->p1.y - y, s->p1.z - z);
	Makepoint(&(s->p2), s->p2.x - x, s->p2.y - y, s->p2.z - z);
	Makepoint(&(s->p3), s->p3.x - x, s->p3.y - y, s->p3.z - z);
	Makepoint(&(s->p4), s->p4.x - x, s->p4.y - y, s->p4.z - z);
	Makepoint(&(s->pc), s->pc.x - x, s->pc.y - y, s->pc.z - z);
}

void ChangeCordCylinder(t_cylinder *c, double x, double y, double z)
{
	c->p.x -= x;
	c->p.y -= y;
	c->p.z -= z;
}

void ChangeCordTriangle(t_triangle *s, double x, double y, double z)
{
	Makepoint(&(s->p1), s->p1.x - x, s->p1.y - y, s->p1.z - z);
	Makepoint(&(s->p2), s->p2.x - x, s->p2.y - y, s->p2.z - z);
	Makepoint(&(s->p3), s->p3.x - x, s->p3.y - y, s->p3.z - z);
}