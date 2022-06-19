/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:18:37 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/19 21:24:27 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * Locates first occurance of any char in string 'charset' in the string 's',
 * and returns a pointer to the character located.
 *
 * If either 'charset' or 's' are not valid C strings (null terminated), the
 * behavior is undefined.
 */
char	*ft_strpbrk(const char *s, const char *charset)
{
	unsigned char	i;

	while (*s != 0)
	{
		i = 0;
		while (charset[i] != 0)
		{
			if (*s == charset[i])
				return ((char *)s);
			i++;
		}
		s++;
	}
	return (NULL);
}
