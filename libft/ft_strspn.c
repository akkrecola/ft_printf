/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:11:03 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/21 03:20:26 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Return the index of the first char of 'charset' that does not occur in 's'.
// If no (un)matching char is found, returns index of the first null character.
size_t	ft_strspn(const char *s, const char *charset)
{
	const size_t	set_len = ft_strlen(charset);
	size_t			i;
	size_t			c;
	int				flag;

	i = 0;
	c = 0;
	flag = 0;
	while (s[i])
	{
		while (c <= set_len)
		{
			if (s[i] == charset[c])
				flag = 1;
			c++;
		}
		if (flag == 0)
			return (i);
		flag = 0;
		c = 0;
		i++;
	}
	return (i);
}
