/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:12 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/19 16:08:27 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	verify_needle(const char *haystack, const char *needle)
{
	while (*haystack != '\0' && *needle != '\0' && *haystack == *needle)
	{
		haystack++;
		needle++;
	}
	if (*needle != '\0')
		return (0);
	return (1);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			if (verify_needle(haystack, needle) == 1)
				return ((char *) haystack);
		}
		haystack++;
	}
	return (NULL);
}
