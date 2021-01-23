#include "my_math.h"
#include <math.h>

double	distance(t_point t1, t_point t2)
{
	return (sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2) + pow(t2.z - t1.z, 2)));
}

double	CheckSphere(t_line l, t_sphere s)
{
	double k1;
	double k2;
	double k3;

	k1 = pow(l.xmul)
}