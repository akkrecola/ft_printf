/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:00:16 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/21 12:21:32 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Append a character to a string. It's assumed that the string has sufficient
 * space to fit the character, otherwise you're dealing with a buffer overflow.
 *
 * Returns a pointer to the string appended to.
 */
char	*ft_strappend(char *str, char append)
{
	char	*atnull = ft_strchr(str, '\0');

	if (atnull)
	{
		*atnull = append;
		*(atnull + 1) = '\0';
	}
	return (str);
}
