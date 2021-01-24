#include "../../includes/ultimate.h"

int ParseRes(char *s)
{
	if (g_data.Swidth > 0 || g_data.Sheight > 0)
		return (-1);
	g_data.Swidth = ft_atoi(&s);
	g_data.Sheight = ft_atoi(&s);
	if (g_data.Swidth < 1 || g_data.Sheight < 1)
		return (-1);
	return (1);
}

int ParseAmb(char *s)
{
	if(g_data.alratio != -1 || g_data.alcolor.R != -1 ||
		g_data.alcolor.G != -1 || g_data.alcolor.B != -1)
		return (-1);
	g_data.alratio = ft_atoi_double(&s);
	g_data.alcolor.R = ft_atoi(&s);
	g_data.alcolor.G = ft_atoi(&s);
	g_data.alcolor.B = ft_atoi(&s);
	if (g_data.alratio < 0 || g_data.alratio > 1 || g_data.alcolor.R > 255 ||
		g_data.alcolor.R < 0 || g_data.alcolor.G > 255 || g_data.alcolor.G < 0
		|| g_data.alcolor.B > 255 || g_data.alcolor.B < 0)
		return (-1);
	return (1);
}

int ParseCam(char *s)
{
	t_cam	*c;

	c = g_data.cams;
	while (c->next)
		c = c->next;
	if(!(c->next = camconst()))
		return (-1);
	c = c->next;
	c->p.x = ft_atoi_double(&s);
	c->p.y = ft_atoi_double(&s);
	c->p.z = ft_atoi_double(&s);
	c->v.x = ft_atoi_double(&s);
	c->v.y = ft_atoi_double(&s);
	c->v.z = ft_atoi_double(&s);
	c->fow = ft_atoi(&s);
	return (1);
}

int ParseLight(char *s)
{
	t_light *l;

	l = g_data.lights;
	while (l->next)
		l = l->next;
	if(!(l->next = lightconst()))
		return (-1);
	l = l->next;
	l->p.x = ft_atoi_double(&s);
	l->p.y = ft_atoi_double(&s);
	l->p.z = ft_atoi_double(&s);
	l->brightness = ft_atoi_double(&s);
	l->color.R = ft_atoi(&s);
	l->color.G = ft_atoi(&s);
	l->color.B = ft_atoi(&s);
	return (1);
}

int ParseSphere(char *s)
{
	t_obj *o;
	t_sphere *s1;

	o = g_data.objects;
	while (o->next)
		o = o->next;
	if(!(o->next = objconst()))
		return (-1);
	o = o->next;
	o->type = 1;
	if(!(o->obj = malloc(sizeof(struct s_sphere))))
		return (-1);
	s1 = o->obj;
	s1->center.x = ft_atoi_double(&s);
	s1->center.y = ft_atoi_double(&s);
	s1->center.z = ft_atoi_double(&s);
	s1->radius = ft_atoi_double(&s) / 2;
	s1->color.R = ft_atoi(&s);
	s1->color.G = ft_atoi(&s);
	s1->color.B = ft_atoi(&s);
	return (1);
}