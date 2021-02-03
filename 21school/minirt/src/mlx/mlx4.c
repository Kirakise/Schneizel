#include "../../includes/ultimate.h"

int CheckObjects(t_line *l)
{
	t_obj	*o;
	t_result res;

	makecolor(&res.color, 0, 0, 0);
	res.res = INFINITY;
	o = g_data.objects->next;
	while(o)
	{
		CheckObjects2(l, o, &res);
		o = o->next;
	}
	if (!isnan(res.res) && (res.color.B > 0 || res.color.G > 0 || res.color.R > 0))
		AddLight(&res.color, res.v, getpointonline(l, res.res), GetVectorOfLine(l));
	else
		AddLightColor(&res.color, g_data.alratio);
	return (color_to_int(&res.color));
}

void CheckObjects2(t_line *l, t_obj *o, t_result *res)
{
	double tmp;

	if (o->type == 1 && !isnan(tmp = CheckSphere(l, o->obj))
	&& tmp > 1 && De(tmp, res->res) == -1 && (res->res = tmp))
	{
		res->v = GetVectorOfLine(makelinep(&((t_sphere *)o->obj)->center,
		getpointonline(l, res->res)));
		res->color = ((t_sphere *)o->obj)->color;
	}
	else if (o->type == 2 && !isnan(tmp = CheckPlane(l, o->obj))
	&& tmp > 1 && De(tmp, res->res) == -1 && (res->res = tmp))
	{
		res->v = GetVectorFromPlane(*(t_plane *)o->obj);
		res->color = ((t_plane *)o->obj)->color;
	}
	else if (o->type == 3 &&  !isnan(tmp = CheckSquare(l, o->obj))
	&& tmp > 1 && De(tmp, res->res) == -1 && (res->res = tmp))
	{
		res->v = ((t_square *)o->obj)->v;
		res->color = ((t_square *)o->obj)->color;
	}
	else
		CheckObjects3(l, o, res);
}

void CheckObjects3(t_line *l, t_obj *o, t_result *res)
{
	double tmp;

	if (o->type == 4 && !isnan(tmp = CheckCylinder(l, o->obj))
	&& tmp > 1 && De(tmp, res->res) == -1 && (res->res = tmp))
	{
		res->v = GetCylinderNorm(*(t_cylinder *)o->obj, *getpointonline(l, res->res));
		res->color = ((t_cylinder *)o->obj)->color;
	}
	else if (o->type == 5 && !isnan(tmp = CheckTriangle(l, o->obj))
	&& tmp > 1 && De(tmp, res->res) == -1 && (res->res = tmp))
	{
		res->v = ((t_triangle *)o->obj)->v;
		res->color = ((t_triangle *)o->obj)->color;
	}
}	