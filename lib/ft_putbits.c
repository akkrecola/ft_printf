/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:55:09 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/23 15:56:38 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbits(void *var, uint8_t bytes)
{
	const uint64_t	printvar = *(uint64_t *)var;
	uint8_t			shift;

	shift = bytes * 8;
	while (shift-- > 0)
	{
		if (printvar & 1L << shift)
			ft_putchar('1');
		else
			ft_putchar('0');
		if (shift % 4 == 0 && shift)
			ft_putchar(' ');
		if ((shift) % 8 == 0 && shift)
			ft_putchar(' ');
	}
	ft_putendl("");
}
