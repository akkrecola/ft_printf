/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:24 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 12:21:53 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Raise integer 'base' to the power of 'exp'*/
double	ft_pow(double base, double exp)
{
	double	result;

	result = base;
	while (exp > 1.0f)
	{
		result *= base;
		exp -= 1;
	}
	return (result);
}

float	ft_powf(float base, float exp)
{
	float	result;

	result = base;
	while (exp > 1.0f)
	{
		result *= base;
		exp -= 1;
	}
	return (result);
}

int		ft_powi(int base, int exp)
{
	int	result;

	result = base;
	while (exp-- > 1)
		result *= base;
	return (result);
}
