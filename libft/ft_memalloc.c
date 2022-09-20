/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:31:06 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/17 06:04:47 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocates and returns a fresh memory area. Memory allocated is initialized
** to 0. Return NULL on failed allocation.
*/

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = (char *) malloc(size);
	if (area == NULL)
		return (NULL);
	ft_bzero(area, size);
	return (area);
}
