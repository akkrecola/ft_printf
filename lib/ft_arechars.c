/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arechars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erkka <elehtora@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:05:27 by Erkka             #+#    #+#             */
/*   Updated: 2022/06/01 19:09:37 by Erkka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The function searches str for an char occurance from charset, and returns
// the first character in the charset that's found, or 0 if none of the
// chars were found.
//
// The input charset is expected to be a real C-string (null terminated)
// containing the characters in sequence and nothing else.
//
// The function is case sensitive.
//
// NOTE: Search is limited to printable characters of the ASCII character set,
// i.e. ASCII 32-126 inclusive.

int	ft_arechars(char *str, const char *charset)
{
	size_t	chars_len;
	size_t	i;

	chars_len = ft_strlen(charset);
	i = 0;
	while (i < chars_len)
	{
		if (ft_strchr(str, charset[i]))
			return (charset[i]);
		i++;
	}
	return (0);
}
