/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:04:49 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 10:59:36 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Gets the absolute value of given datatypes.
int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double	ft_fabs(double x)
{
	if (x < 0.0)
		return (-x);
	return (x);
}

long double	ft_fabsl(long double x)
{
	if (x < 0.0L)
		return (-x);
	return (x);
}

long	ft_labs(long x)
{
	if (x < 0L)
		return (-x);
	return (x);
}

long long	ft_llabs(long long x)
{
	if (x < 0LL)
		return (-x);
	return (x);
}
