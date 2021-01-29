#ifndef MY_MLX_H
# define MY_MLX_H
#include "my_math.h"
#include "minirt.h"

int closewin(int keycode, t_mlx *mlx);
void mlx_start();
void get_image(t_cam *c);
int	color_to_int(t_color *c);
void mlx_put_color(int c, int x, int y);
int CheckObjects(t_line *l);
void	AddLight(t_color *c, t_vector v, t_point *p, t_vector vv);
int CheckInter(t_line *l, t_point *p);
double	AddBligh(t_vector vv, t_vector vr, double brightness);
t_vector ComputeReflectedVector(t_vector vl, t_vector vn);
#endif