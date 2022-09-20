/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:38:13 by elehtora          #+#    #+#             */
/*   Updated: 2022/03/03 18:43:31 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_isdigit(long int n)
{
	return (-9 <= n && n <= 9);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;

	ln = (long int) n;
	if (!ft_isdigit(ln))
		ft_putnbr_fd(((int)ln - ((int)ln % 10)) / 10, fd);
	else if (ln < 0)
		write(fd, "-", 1);
	if (ln < 0)
		ln *= (-1);
	ln = ln % 10 + '0';
	write(fd, &ln, 1);
}
