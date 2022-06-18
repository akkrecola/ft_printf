/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:18:22 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/20 12:46:07 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen < len)
	{
		ft_memset(dst, '\0', len);
		ft_strcpy(dst, src);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
