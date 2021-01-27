#ifndef MY_MLX_H
# define MY_MLX_H
#include "my_math.h"
#include "minirt.h"

int closewin(int keycode, t_mlx *mlx);
void mlx_start();
void get_image(t_cam *c);

#endif