/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:13:13 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/17 04:59:08 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;
	t_list	*tmp_new;

	tmp_new = NULL;
	head = NULL;
	while (lst)
	{
		new = ft_lstnew(0, 0);
		if (!new)
			return (NULL);
		new = f(lst);
		if (!head)
			head = new;
		if (tmp_new)
			tmp_new->next = new;
		tmp_new = new;
		lst = lst->next;
	}
	return (head);
}
