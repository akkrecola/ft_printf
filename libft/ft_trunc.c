/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:00:11 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 01:01:38 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_truncl(long double x)
{
	return ((long double)(long long)x);
}

double	ft_trunc(double x)
{
	return ((double)(long)x);
}
