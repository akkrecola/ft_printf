/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strddup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:22:43 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/19 21:22:55 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Duplicate a (sub)string up to a delimiter 'd' or the null byte.
 */
char	*ft_strddup(const char *s, char d)
{
	char			*new;
	const size_t	len = ft_strdlen(s, d);

	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s, len);
	return (new);
}
