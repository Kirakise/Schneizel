#include "../../includes/ultimate.h"

int CheckObjects(t_line *l)
{
	t_obj	*o;
	double res;
	t_color color;
	double tmp;

	makecolor(&color, 0, 0 ,0);
	res = 20000000;
	o = g_data.objects->next;
	while(o)
	{
		if (o->type == 1 && !isnan(tmp = CheckSphere(l, o->obj))
		 && tmp > 1 && tmp < res && (res = tmp))
			//color = color_to_int(&((t_sphere *)o->obj)->color);
			color = ((t_sphere *)o->obj)->color;
		o = o->next;
	}
	return (color);
}

int	AddLight(t_color *c, t_vector *v, t_point *p)
{
	t_light *l;
	double result;

	result = g_data.alratio;
	l = g_data.lights->next;
}

