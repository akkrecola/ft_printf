/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 03:01:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 03:06:02 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// Frees memory allocated to either or both strings, and joins them together,
// returning a newly allocated concatenation of a and b.
// select values 'a' and 'b' free strings a and b respectively, and
// value 'c' frees both. Misusing this selection causes a segmentation fault.
// If the allocation of the new string fails, no memory is freed and the
// function returns NULL.
char	*ft_freejoin(const char *a, const char *b, uint8_t select)
{
	char	*joined;

	joined = ft_strjoin(a, b);
	if (!joined)
		return (NULL);
	if (select == 'a')
		free((void *)a);
	else if (select == 'b')
		free((void *)b);
	else if (select == 'c')
	{
		free((void *)a);
		free((void *)b);
	}
	return (joined);
}
