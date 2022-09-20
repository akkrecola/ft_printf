/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:03:39 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/19 14:49:01 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Sets a maximum of len bytes from memory area b to constant byte c.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	while (len-- > 0)
		((unsigned char *) b)[len] = (unsigned char) c;
	return (b);
}
