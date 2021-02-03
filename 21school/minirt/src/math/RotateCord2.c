#include "../../includes/ultimate.h"

void RotateAll(double angle1, double angle2)
{
	Rotatelights(angle1, angle2);
	Rotateobjects(angle1, angle2);
	RotateCams(angle1, angle2);
}

void RotateSquare(t_square *s, double angle1, double angle2)
{
	RotateXP(&(s->p1), angle1);
	RotateYP(&(s->p1), angle2);
	RotateXP(&(s->p2), angle1);
	RotateYP(&(s->p2), angle2);
	RotateXP(&(s->p3), angle1);
	RotateYP(&(s->p3), angle2);
	RotateXP(&(s->p4), angle1);
	RotateYP(&(s->p4), angle2);
	RotateXV(&(s->v), angle1);
	RotateYV(&(s->v), angle2);
}

void RotateSquareInit(t_square *s)
{
	double angle1;
	double angle2;
	int	tmp;

	if ((tmp = 1) && s->v.z < 0)
		tmp = -1;
	angle1 = s->v.y != 0 ? tmp * atan(s->v.y / s->v.z) : 0;
	angle2 = s->v.x != 0 ? tmp * asin((s->v.x) / VectorModule(&(s->v))) : 0;
	RotateXP(&(s->pc), angle1);
	RotateYP(&(s->pc), angle2);
	RotateXV(&(s->v), angle1);
	RotateYV(&(s->v), angle2);
	Makepoint(&(s->p1), -s->side/2 + s->pc.x, -s->side/2 + s->pc.y, s->pc.z);
	Makepoint(&(s->p2), -s->side/2 + s->pc.x, s->side/2 + s->pc.y, s->pc.z);
	Makepoint(&(s->p3), s->side/2 + s->pc.x, s->side/2 + s->pc.y, s->pc.z);
	Makepoint(&(s->p4), s->side/2 + s->pc.x, -s->side/2 + s->pc.y, s->pc.z);
	RotateSquare(s,-angle1,-angle2);
}

void RotateCylinder(t_cylinder *c, double angle1, double angle2)
{
	RotateXV(&(c->v), angle1);
	RotateYV(&(c->v), angle2);
	RotateXP(&(c->p), angle1);
	RotateYP(&(c->p), angle2);
}

void RotateCams(double angle1, double angle2)
{
	t_cam *c;

	c = g_data.cams->next;
	while (c)
	{
		RotateCam(angle1, angle2, c);
		c = c->next;
	}
}