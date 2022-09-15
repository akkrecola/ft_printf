/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:51:14 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 20:19:48 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Join two strings, separating them with a delimiting string. Delimiter
// 'delim' can be omitted by passing a NULL in it's place.
char	*ft_strdjoin(char const *head, char const *delim, char const *tail)
{
	const size_t	len = ft_strlen(head) + ft_strlen(delim) + ft_strlen(tail);
	char			*joined;

	joined = ft_strnew(len);
	if (!joined || !head || !tail)
		return (NULL);
	ft_strcpy(joined, head);
	if (delim)
		ft_strcpy(ft_strchr(joined, '\0'), delim);
	ft_strcpy(ft_strchr(joined, '\0'), tail);

	return (joined);
}
