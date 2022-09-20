/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:18:16 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/20 20:05:09 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	newstr = ft_strnew(len1 + ft_strlen(s2));
	if (!newstr)
		return (NULL);
	ft_strcpy(newstr, s1);
	ft_strcpy((newstr + len1), s2);
	return (newstr);
}
