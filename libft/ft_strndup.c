/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:40:43 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 11:14:04 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *Duplicate a (sub)string up to 'n' characters. Allocates at most (n + 1) bytes
 *of space and copies the string 's', null terminating the result.
 *
 *If the length of string 's' is less than 'n', truncation occurs.
 *
 *Of the allocation fails, i.e. there's insufficient space for the allocation,
 *ft_strndup returns NULL. Otherwise, it returns a pointer to the newly created
 *string.
 */
char	*ft_strndup(const char *s, size_t n)
{
	const size_t	len = ft_strnlen(s, n);
	char			*new;

	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	ft_memmove(new, s, len);
	return (new);
}
