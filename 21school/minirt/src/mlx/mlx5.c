#include "../../includes/ultimate.h"

void CheckRes(double *res, t_obj *o, t_line *l)
{
	double tmp;

	if (o->type == 1 && !isnan(tmp = CheckSphere(l, o->obj)) && tmp > 0 && De(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 2 && !isnan(tmp = CheckPlane(l, o->obj)) && tmp > 0 && De(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 3 && !isnan(tmp = CheckSquare(l, o->obj)) && tmp > 0 && De(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 4 && !isnan(tmp = CheckCylinder(l, o->obj)) && tmp > 0 && De(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 5 && !isnan(tmp = CheckTriangle(l, o->obj)) && tmp > 0 && De(tmp, *res) == -1)
		*res = tmp;
}