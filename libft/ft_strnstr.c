/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:12 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/20 20:04:03 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strequ_noterm(char const *s1, char const *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (*s1 != '\0' && *s2 != '\0' && i < len)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		i++;
	}
	if (*s2 != '\0')
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
		{
			if (strequ_noterm(haystack, needle, len) == 1)
				return ((char *) haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
