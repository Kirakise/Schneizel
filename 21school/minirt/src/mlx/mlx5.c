/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:35:15 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:35:59 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	checkres(double *res, t_obj *o, t_line *l)
{
	double tmp;

	if (o->type == 1 && !isnan(tmp = checksphere(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 2 && !isnan(tmp = checkplane(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 3 && !isnan(tmp = checksquare(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 4 && !isnan(tmp = checkcylinder(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 5 && !isnan(tmp = checktriangle(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
}
