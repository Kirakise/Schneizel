#include "../../includes/ultimate.h"
#include <fcntl.h>
#include <stdio.h>

int ParsePlane(char *s)
{
	t_plane *p;
	t_obj	*o;

	p = malloc(sizeof(struct s_plane));
	if (!p)
		return (-1);
	o = g_data.objects->next;
	while (o->next)
		o = o->next;
	o->next = objconst();
	o = o->next;
	o->obj = p;
	o->type = 2;
	p->p.x = ft_atoi_double(&s);
	p->p.y = ft_atoi_double(&s);
	p->p.z = ft_atoi_double(&s);
	p->v.x = ft_atoi_double(&s);
	p->v.y = ft_atoi_double(&s);
	p->v.z = ft_atoi_double(&s);
	p->color.R = ft_atoi(&s);
	p->color.G = ft_atoi(&s);
	p->color.B = ft_atoi(&s);
	return (1);
}

int ParseSquare(char *s)
{
	t_square *sq;
	t_obj *o;

	sq = malloc(sizeof(struct s_square));
	if (!sq)
		return (-1);
	o = g_data.objects->next;
	while (o->next)
		o = o->next;
	o->next = objconst();
	o = o->next;
	o->obj = sq;
	o->type = 3;
	sq->pc.x = ft_atoi_double(&s);
	sq->pc.y = ft_atoi_double(&s);
	sq->pc.z = ft_atoi_double(&s);
	sq->v.x = ft_atoi_double(&s);
	sq->v.y = ft_atoi_double(&s);
	sq->v.z = ft_atoi_double(&s);
	sq->side = ft_atoi_double(&s);
	sq->color.R = ft_atoi(&s);
	sq->color.G = ft_atoi(&s);
	sq->color.B = ft_atoi(&s);
	RotateSquareInit(sq);
	return (1);
}

int ParseCylinder(char *s)
{
	t_cylinder *c;
	t_obj *o;

	c = malloc(sizeof(struct s_cylinder));
	if (!c)
		return (-1);
	o = g_data.objects->next;
	while (o->next)
		o = o->next;
	o->next = objconst();
	o = o->next;
	o->type = 4;
	o->obj = c;
	c->p.x = ft_atoi_double(&s);
	c->p.y = ft_atoi_double(&s);
	c->p.z = ft_atoi_double(&s);
	c->v.x = ft_atoi_double(&s);
	c->v.y = ft_atoi_double(&s);
	c->v.z = ft_atoi_double(&s);
	c->radius = ft_atoi_double(&s) / 2;
	c->height = ft_atoi_double(&s);
	c->color.R = ft_atoi(&s);
	c->color.G = ft_atoi(&s);
	c->color.B = ft_atoi(&s);
	return (1);
}

int ParseTriangle(char *s)
{
	t_triangle *t;
	t_obj *o;

	t = malloc(sizeof(struct s_triangle));
	if (!t)
		return (-1);
	o = g_data.objects->next;
	while (o->next)
		o = o->next;
	o->next = objconst();
	o = o->next;
	o->obj = t;
	o->type = 5;
	t->p1.x = ft_atoi_double(&s);
	t->p1.y = ft_atoi_double(&s);
	t->p1.z = ft_atoi_double(&s);
	t->p2.x = ft_atoi_double(&s);
	t->p2.y = ft_atoi_double(&s);
	t->p2.z = ft_atoi_double(&s);
	t->p3.x = ft_atoi_double(&s);
	t->p3.y = ft_atoi_double(&s);
	t->p3.z = ft_atoi_double(&s);
	t->color.R = ft_atoi(&s);
	t->color.G = ft_atoi(&s);
	t->color.B = ft_atoi(&s);
	return (1);
}