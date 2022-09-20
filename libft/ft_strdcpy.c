/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:00:39 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/19 21:06:55 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
 * Copy string until a delimiter 'd' or the null byte. The copying is done
 * forwards; overlapping strings are not safe.
 *
 * If the copying stops by a found delimiter character 'd', that delimiter is
 * turned into a null byte '\0' in the resulting string `dst`. The source string
 * is left intact.
 */
char	*ft_strdcpy(char *dst, const char *src, char d)
{
	while (*src && *src != d)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
