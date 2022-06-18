/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:29:31 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/19 18:20:52 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digs(long int ln)
{
	size_t	count;

	count = 0;
	if (ln < 0)
		count += 1;
	while (ln < -9 || ln > 9)
	{
		count++;
		ln = (ln - ln % 10) / 10;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		digs;
	long int	ln;

	ln = (long int) n;
	digs = count_digs(ln);
	str = ft_strnew((size_t) digs);
	if (!str)
		return (NULL);
	if (ln < 0)
	{
		ln *= -1;
		str[0] = '-';
	}
	while (digs > 0)
	{
		digs--;
		if (str[digs] == '-')
			return (str);
		str[digs] = (ln % 10) + '0';
		ln = (ln - ln % 10) / 10;
	}
	return (str);
}
