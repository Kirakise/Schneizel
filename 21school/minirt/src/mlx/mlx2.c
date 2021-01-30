#include "../../includes/ultimate.h"
int CheckObjects(t_line *l)
{
	t_obj	*o;
	double res;
	t_color color;
	t_vector v;
	double tmp;

	makecolor(&color, 0, 0, 0);
	res = 20000000;
	o = g_data.objects->next;
	while(o)
	{
		if (o->type == 1 && !isnan(tmp = CheckSphere(l, o->obj))
		 && tmp > 1 && De(tmp, res) == -1 && (res = tmp))
		 {
		 	v = GetVectorOfLine(makelinep(&((t_sphere *)o->obj)->center, getpointonline(l, res)));
			color = ((t_sphere *)o->obj)->color;
		 }
		o = o->next;
	}
	if (res < 20000000)
		AddLight(&color, v, getpointonline(l, res), GetVectorOfLine(l));
	return (color_to_int(&color));
}

int CheckInter(t_line *l, t_point *p)
{
	t_obj *o;
	double tmp;
	double res;

	o = g_data.objects->next;
	res = 2000000000;
	while (o)
	{
		if (o->type == 1 && !isnan(tmp = CheckSphere(l, o->obj)) && tmp > 0 && De(tmp, res) == -1)
			res = tmp;
		o = o->next;
	}
	if (res < 2000000000 && EqPoint(p, getpointonline(l, res)))
		return (1);
	return (0);
}

void	AddLight(t_color *c, t_vector v, t_point *p, t_vector vv)
{
	t_light *l;
	t_line	*tmp;
	t_vector vtmp;
	double result;
	result = g_data.alratio;
	l = g_data.lights->next;
	foo();
	while (l)
	{
		tmp = makelinep(p, &(l->p));
		vtmp = GetVectorOfLine(tmp);
		free(tmp);
		tmp = makelinep(&(l->p), p);
		if (CheckInter(tmp, p) && cos(GetAngle(&v, &vtmp)) > 0)
		{
			result += cos(GetAngle(&v, &vtmp)) * l->brightness;
			result += AddBligh(vv, ComputeReflectedVector(vtmp, v), l->brightness);
		}
		free(tmp);
		l = l->next;
	}
	AddLightColor(c, result);
}

void AddLightColor(t_color *c, double light)
{
	c->B *= light;
	c->G *= light;
	c->R *= light;
	if(c->B > 255)
		c->B = 255;
	if(c->G > 255)
		c->G = 255;
	if(c->R > 255)
		c->R = 255;
	if (c->B < 0)
		c->B = 0;
	if (c->R < 0)
		c->R = 0;
	if (c->G < 0)
		c->G = 0;
}