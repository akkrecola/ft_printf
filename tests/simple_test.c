/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 06:40:02 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 08:04:44 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
/*#define FORMAT " %020.i \n"*/
#define FORMAT "%020d   \n"
#define TESTS 7

static const int	inputs[TESTS] = {
	0,
	-0,
	42,
	-42,
	123,
	INT_MAX,
	INT_MIN,
};

int	main()
{
	for (unsigned i = 0; i < TESTS; i++)
	{
		ft_printf(FORMAT, inputs[i]);
		printf(FORMAT, inputs[i]);
	}
}
