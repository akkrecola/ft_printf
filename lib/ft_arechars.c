/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arechars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:30:49 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/21 00:31:26 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The function searches str for an char occurance from charset, and returns
 * the first character in the charset that's found, or 0 if none of the
 * chars were found.
 *
 * The input charset is expected to be a real C-string (null terminated)
 * containing the characters in sequence and nothing else.
 *
 * The function is case sensitive.
 *
 * NOTE: Search is limited to printable characters of the ASCII character set,
 * i.e. ASCII 32-126 inclusive.
 */
char	ft_arechars(const char *str, const char *charset)
{
	size_t	chars_len;
	size_t	i;

	chars_len = ft_strlen(charset);
	i = 0;
	while (str)
	{
		while (i < chars_len)
		{
			if (*str == charset[i])
				return (charset[i]);
			i++;
		}
		str++;
	}
	return (0);
}
