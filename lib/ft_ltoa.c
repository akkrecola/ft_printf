/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 04:41:53 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 19:19:36 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#define LLONG_MIN_IN_STR "-9223372036854775808"
#define FT_LTOA_BUFLEN 22

static int	count_digits(unsigned long long n)
{
	uint8_t	digits;

	digits = 1;
	while (n > 9)
	{
		digits++;
		n = (n - (n % 10)) / 10;
	}
	return ((int)digits);
}

char		*ft_ltoa(long long n)
{
	char	buf[FT_LTOA_BUFLEN];
	uint8_t	len;

	if (n == LLONG_MIN)
		return (ft_strdup(LLONG_MIN_IN_STR));
	ft_bzero(&buf[0], FT_LTOA_BUFLEN);
	len = 0;
	if (n < 0)
	{
		buf[0] = '-';
		n *= -1;
		len += 1;
	}
	len += count_digits(n);
	while (len-- && !(buf[len] == '-'))
	{
		buf[len] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
	}
	return (ft_strdup(&buf[0]));
}

// Converts an (unsigned long long) integer to a string format
char		*ft_ltoa_unsigned(unsigned long long n)
{
	int		len;
	char	*str;

	len = count_digits(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n = (n - (n % 10)) / 10;
	}
	return (str);
}
