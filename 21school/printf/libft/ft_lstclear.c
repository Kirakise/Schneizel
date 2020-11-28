/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:27:47 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 19:28:27 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *tmp2;

	if (!lst)
		return ;
	tmp = 0;
	tmp2 = *lst;
	while (tmp2)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
