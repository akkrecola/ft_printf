/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 04:41:53 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 05:18:20 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned long n)
{
	int	digits;

	digits = 1;
	while (n > 9)
	{
		digits++;
		n = (n - (n % 10)) / 10;
	}
	return (digits);
}

// Converts a (long) integer to a string format
char		*ft_itol_unsigned(unsigned long n)
{
	int		len;
	char	buf[32];
	char	*str;

	len = count_digits(n);
	ft_bzero(&buf[0], 32);
	str = ft_strnew(len);
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n = (n - (n % 10)) / 10;
	}
	return (str);
}
