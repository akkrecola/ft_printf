/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:03:39 by elehtora          #+#    #+#             */
/*   Updated: 2022/03/22 21:37:31 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Checks a memory area for a value c, and either returns pointer to that value
** or NULL if value is not found.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if ((*((unsigned char *) s)) == (unsigned char) c)
			return ((void *) s);
		s++;
	}
	return (NULL);
}
