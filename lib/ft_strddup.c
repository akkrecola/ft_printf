/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:40:43 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/19 21:00:07 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Duplicate a (sub)string up to a delimiter 'd' or the null byte.
 */
char	*ft_strndup(const char *s, char d)
{
	char	*new;

	new = ft_strnew(ft_strlen(s, n));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s, n);
	return (new);
}
