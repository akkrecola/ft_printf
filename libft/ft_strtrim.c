/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:09:05 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/23 12:43:21 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_tail(char *s)
{
	char	*start;
	char	*tail;

	start = (char *) s;
	while (*s != '\0')
		s++;
	if (s == start)
		return ((char *) s);
	tail = s - 1;
	while (ft_iswhite(*tail))
		tail--;
	return (tail);
}

static char	*get_start(char const *s)
{
	char	*start;

	start = (char *) s;
	while (ft_iswhite(*start))
		start++;
	return (start);
}

char	*ft_strtrim(char const *s)
{
	char		*start;
	char const	*tail;
	char		*trimmed;
	char		*result_ptr;

	if (!s)
		return (NULL);
	start = get_start(s);
	tail = get_tail(start);
	trimmed = ft_strnew((size_t)(tail - start + 1));
	if (trimmed == NULL)
		return (NULL);
	result_ptr = trimmed;
	while (start <= tail)
		*(trimmed++) = *(start++);
	return (result_ptr);
}
