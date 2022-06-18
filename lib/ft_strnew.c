/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:31:06 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/20 20:05:16 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*area;
	size_t	i;

	area = (char *) malloc(size + 1);
	if (area == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		area[i] = '\0';
		i++;
	}
	return (area);
}
