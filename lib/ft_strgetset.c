/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgetset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:10:23 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/17 20:29:19 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

/*
 * Search for members of a charset 'target' in 's' until a member of charset
 * 'delims', length 'maxlen' or the null byte is met. If 'maxlen' is set to
 * 0, the entire string 's' is searched. Null byte cannot be found.
 *
 * This function is exponentially taxing if either 'targetset' or 'delimset'
 * is expanded, and linearily when 's' is expanded, so use it with caution.
 *
 * Note: 'targetset' and 'delimset' must be valid C strings, i.e. null
 * terminated. 's' must be a valid string at least in case 'maxlen' is less
 * than the length of 's'.
 */
char	*ft_strgetset(const char *s, char *targetset, char *delimset, size_t maxlen)
{
	size_t	i;
	char	*resultset;
	char	*target;

	resultset = ft_strnew(ft_strlen(targetset));
	if (!resultset)
		return (NULL);
	i = 0;
	while (s[i] && (i < maxlen || maxlen == 0) && !ft_strchr(delimset, s[i]))
	{
		target = NULL;
		target = ft_strchr(targetset, s[i]);
		if (target && !ft_strchr(resultset, *target))
			ft_strappend(resultset, *target);
		i++;
	}
	if (!(*resultset))
	{
		free(resultset);
		return (NULL);
	}
	return (resultset);
}
