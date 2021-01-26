#include "../../includes/ultimate.h"

void RotateAll(double angle1, double angle2, t_cam *c)
{
	Rotatelights(angle1, angle2);
	Rotateobjects(angle1, angle2);
	RotateCam(angle1, angle2, c);
}