/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:24 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/24 22:21:08 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Raise integer 'base' to the power of 'exp'*/
double	ft_pow(double base, double exp)
{
	double	result;

	if (exp == 0.0)
		return (1.0);
	result = base;
	while (exp > 1.0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

long double	ft_powl(long double base, long double exp)
{
	double	result;

	if (exp == 0.0)
		return (1.0);
	result = base;
	while (exp > 1.0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

float	ft_powf(float base, float exp)
{
	float	result;

	if (exp == 0.0)
		return (1.0);
	result = base;
	while (exp > 1.0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

int	ft_powi(int base, int exp)
{
	int	result;

	if (exp == 0.0)
		return (1.0);
	result = base;
	while (exp-- > 1.0)
		result *= base;
	return (result);
}

// Raises 10 to the power of parameter exp
unsigned long long ft_exp10(int exp)
{
	const int			base = 10;
	unsigned long long	result;

	if (exp == 0)
		return (1);
	result = base;
	while (exp-- > 1)
		result *= base;
	return (result);
}
