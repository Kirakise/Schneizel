#include "../../includes/ultimate.h"


t_vector ComputeReflectedVector(t_vector vl, t_vector vn)
{
	t_vector r;
	double k;

	k = vl.z * vn.z + vl.y + vn.y + vl.x * vn.x;

	r.x = -(vn.x*k - vl.x);
	r.y = -(vn.y * k - vl.y);
	r.z = -(vn.z*k - vl.z);
	return (r);
}

double	AddBligh(t_vector vv, t_vector vr, double brightness)
{
	double result;
	result = pow(cos(GetAngle(&vv,&vr)),400) * brightness;
	if (result <= 0)
		return 0;
	else
	{
		foo();
		return result;
	}
}