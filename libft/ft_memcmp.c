/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:02:17 by elehtora          #+#    #+#             */
/*   Updated: 2022/01/15 16:56:15 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*((unsigned char *) s1) != *((unsigned char *) s2))
			return (*((unsigned char *) s1) - *((unsigned char *) s2));
		s1++;
		s2++;
	}
	return (0);
}
