#include "../../includes/ultimate.h"
#include <mlx.h>

void RotateObj(t_obj *o, double angle)
{
	if (o->type == 2)
		RotatePlane(o->obj, angle, 0);
	if (o->type == 3)
		RotateSquare(o->obj, angle, 0);
	if (o->type == 4)
		RotateCylinder(o->obj, angle, 0);
}