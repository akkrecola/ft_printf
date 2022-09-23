/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:39:44 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 09:27:50 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#define INT_TESTS 8
#define FORMAT "{% 03d}\n"

const short numbers[] =
{
	0,
	42,
	-42,
	32768,
	SHRT_MAX + 1,
	LONG_MAX,
	LONG_MIN,
	ULLONG_MAX,
};

int	main(void)
{
	for (unsigned i = 0; i < INT_TESTS; i++)
	{
		ft_printf(FORMAT, numbers[i]);
		printf(FORMAT, numbers[i]);
	}
}
