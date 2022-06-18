/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:03:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/20 20:05:14 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to all chars of string s, then returns a fresh
** string with modifications by function f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	if (!s || !f)
		return (NULL);
	new_str = ft_strnew(ft_strlen(s));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = f(s[i]);
		i++;
	}
	return (new_str);
}
