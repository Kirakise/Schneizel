/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:50:53 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/06 18:30:04 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*tmp;
	t_list		*tmp2;
	t_list		*tmp3;
	void		(*wtf)	(void *);

	wtf = del;
	if (!lst)
		return (0);
	tmp = 0;
	while (lst)
	{
		tmp2 = ft_lstnew(f(lst->content));
		tmp3 = lst->next;
		lst = tmp3;
		ft_lstadd_back(&tmp, tmp2);
	}
	return (tmp);
}
