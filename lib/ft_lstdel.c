/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:57:22 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/18 03:28:26 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Currently NULLs only the last pointer to link (i.e. the head), while
** the assignment could also mean that all pointers to links should be NULLed.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*prev;

	prev = *alst;
	while (*alst)
	{
		*alst = (*alst)->next;
		del(prev->content, prev->content_size);
		free(prev);
		prev = *alst;
	}
	*alst = NULL;
}
