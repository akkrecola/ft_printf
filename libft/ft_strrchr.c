/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:27:40 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/19 16:56:57 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	s += ft_strlen(s);
	while (start < s && (char) *s != (char) c)
		s--;
	if (*((char *) s) == (char) c)
		return ((char *) s);
	return (NULL);
}
