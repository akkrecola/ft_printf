/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:56:25 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/19 22:53:55 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len-- > 0)
		((char *) dst)[len] = ((const char *) src)[len];
	return (dst);
}
