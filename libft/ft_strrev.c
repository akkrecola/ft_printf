/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:10:34 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 03:38:47 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Reverses a string 'str'.
char	*ft_strrev(const char *str)
{
	size_t	len;
	char	*rev;
	char	*tmp;

	len = ft_strlen(str);
	rev = ft_strnew(len);
	tmp = rev;
	while (len-- > 0)
		*tmp++ = str[len];
	return (rev);
}
