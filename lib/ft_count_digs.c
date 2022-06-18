/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:44:17 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/22 01:12:39 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts and returns the number of digits in n.
**
** Assumes the input to be a valid integer, i.e. no less than 1 in length.
** Inputs out of integer range result in undefined behaviour.
*/

size_t	ft_count_digs(int n)
{
	size_t		count;
	long int	ln;

	ln = (long int) n;
	if (ln < 0)
		ln *= -1;
	count = 0;
	while (ln > 9)
	{
		ln = (ln - ln % 10) / 10;
		count++;
	}
	return (count + 1);
}
