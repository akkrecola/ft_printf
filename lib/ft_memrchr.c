/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:25:15 by elehtora          #+#    #+#             */
/*   Updated: 2022/03/22 21:37:43 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if (((unsigned char *) s)[n] == (unsigned char) c)
			return (&(((void *) s)[n]));
	}
	return (NULL);
}
