/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:40:43 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/19 14:18:38 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Copies from source to dstination for n bytes or until c is found in source.
** Returns a pointer to the following byte of c if c is found, NULL otherwise.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*((unsigned char *) dst) = *((unsigned char *) src);
		if ((*(unsigned char *) src) == (unsigned char) c)
			return (dst + 1);
		dst++;
		src++;
	}
	return (NULL);
}
