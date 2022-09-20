/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:34:38 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/20 13:42:05 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strncat() appends a maximum of n characters from source string s2 to
** destnation string s1. It returns a pointer to destination s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	dstlen;
	size_t	i;

	dstlen = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[dstlen + i] = s2[i];
		i++;
	}
	s1[dstlen + i] = '\0';
	return (s1);
}
