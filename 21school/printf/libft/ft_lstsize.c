/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:13:24 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 19:14:04 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *list)
{
	int		i;
	t_list	*tmp;

	if (!list)
		return (0);
	tmp = list;
	i = 1;
	while (tmp->next && i++)
		tmp = tmp->next;
	return (i);
}
