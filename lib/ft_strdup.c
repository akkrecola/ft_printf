/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:11:06 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/20 20:05:02 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Standard library's strdup sets errno, but errno.h is a forbidden include,
** so errno is excluded also from this function.
*/

char	*ft_strdup(const char *s)
{
	char	*new;

	new = ft_strnew(ft_strlen(s));
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s);
	return (new);
}
