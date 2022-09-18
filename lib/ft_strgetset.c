/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgetset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:10:23 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 03:44:19 by elehtora         ###   ########.fr       */
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
 * This function is exponentially taxing if either 'tset' or 'dset'
 * is expanded, and linearily when 's' is expanded, so use it with caution.
 *
 * Note: 'tset' and 'dset' must be valid C strings, i.e. null
 * terminated. 's' must be a valid string at least in case 'maxlen' is less
 * than the length of 's'.
 */
#define GETSET_BUFSIZE 256
char	*ft_strgetset(const char *s, char *tset, char *dset, size_t maxlen)
{
	char			resultset[GETSET_BUFSIZE];

	if (!s)
		return (NULL);
	ft_bzero(&resultset[0], GETSET_BUFSIZE);
	while (*s && !ft_strchr(dset, *s) && maxlen--)
	{
		if (ft_strchr(tset, *s))
			ft_charappend(&resultset[0], *s);
		s++;
	}
	return (ft_strdup(&resultset[0]));
}
