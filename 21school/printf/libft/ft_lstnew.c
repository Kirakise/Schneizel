/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:05:40 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 19:06:22 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (0);
	a->content = content;
	a->next = 0;
	return (a);
}
