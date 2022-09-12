/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:24 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/23 16:18:29 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Raise integer 'base' to the power of 'exponent'*/
uint64_t	ft_pow(unsigned base, unsigned exponent)
{
	uint64_t	result;

	result = base;
	while (exponent-- > 1)
		result *= base;
	return (result);
}
