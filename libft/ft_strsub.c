/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:41:34 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/20 20:05:18 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;

	if (!s)
		return (NULL);
	subs = ft_strnew(len);
	if (!subs)
		return (NULL);
	i = 0;
	while (len-- > 0)
		subs[i++] = s[start++];
	return (subs);
}
