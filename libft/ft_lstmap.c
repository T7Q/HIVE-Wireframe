/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:42:35 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/30 16:55:26 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*temp;

	if (!lst)
		return (NULL);
	res = f(lst);
	temp = res;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (!(temp = temp->next))
			return (NULL);
	}
	return (res);
}
