/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpyone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:33:34 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/17 01:38:12 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function is basically a NULL protected lstnew with an appropriate name.
** Copies (using malloc(3)) a link of a list in it's entirety to another link.
** If the source link is NULL, returns NULL. If either the link's content or
** its size is nul, the function also returns NULL.
*/

t_list	*ft_lstcpyone(t_list *link)
{
	t_list	*new;

	if (!link || !(link->content) || !(link->content_size))
		return (NULL);
	new = ft_lstnew(link->content, link->content_size);
	return (new);
}
