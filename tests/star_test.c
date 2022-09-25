/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:06:34 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 07:24:48 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Validchar reads a string 's' for max 'len' bytes while the bytes are
 * contained in the character set 'charset'. It will return either a pointer
 * to a mismatching character, or NULL if all characters are valid (not
 * invalid input).
 */
char	*ft_invalidchars(const char *s, const char *charset, size_t len)
{
	char	*c;

	while (*s && len--)
	{
		c = ft_strchr(charset, *s);
		if (c)
			return (c);
		s++;
	}
	return (NULL);
}
