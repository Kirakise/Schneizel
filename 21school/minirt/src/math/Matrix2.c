#include "../../includes/ultimate.h"

void RotateXP(t_point *v, double angle)
{
	double y;
	double z;

	y = v->y * cos(angle) + v->z * -sin(angle);
	z = v->y * sin(angle) + v->z * cos(angle);
	v->y = y;
	v->z = z;
}

void RotateYP(t_point *v, double angle)
{
	double x;
	double z;

	x = v->x * cos(angle) + v->z * -sin(angle);
	z = v->x * sin(angle) + v->z * cos(angle);
	v->x = x;
	v->z = z;
}

void RotateZP(t_point *v, double angle)
{
	double x;
	double y;

	x = v->x * cos(angle) + v->y * sin(angle);
	y = v->x * -sin(angle) + v->y * cos(angle);
	v->x = x;
	v->y = y;
}
