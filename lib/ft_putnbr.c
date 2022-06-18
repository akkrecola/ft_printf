/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:38:13 by elehtora          #+#    #+#             */
/*   Updated: 2022/03/22 21:43:19 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_isdigit(long int c)
{
	return (-9 <= c && c <= 9);
}

void	ft_putnbr(int n)
{
	long int	ln;

	ln = (long int) n;
	if (!ft_isdigit(ln))
		ft_putnbr(((int)ln - ((int)ln % 10)) / 10);
	else if (ln < 0)
		write(1, "-", 1);
	if (ln < 0)
		ln *= (-1);
	ln = ln % 10 + '0';
	write(1, &ln, 1);
}
