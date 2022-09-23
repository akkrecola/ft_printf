/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 00:05:02 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/16 04:07:27 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define TESTS 7
const char	*formats[TESTS] =
{
	"Simple float: %f",
	"Floating meaning of life: %f",
	"Float .12345 with 4 precision, banker DOWN: %.4f",
	"Float .12355 with 4 precision, banker UP: %.4f",
	"Float 1.512355 with 0 precision, banker UP: %.0f",
	"Float 1.512355 with 1 precision, banker DOWN: %.1f",
	"Float 1.65001 with 1 precision, banker UP: %.1f",
};

const double	floats[TESTS] =
{
	123.456,
	0.42,
	0.12345,
	0.12355,
	1.512355,
	1.512355,
	1.65001,
};

int	main(void)
{
	printf("OWN\tSTD\n");
	for (unsigned i = 0; i < TESTS; i++)
	{
		ft_printf(formats[i], floats[i]);
		ft_putchar('\n');
		printf(formats[i], floats[i]);
		ft_putchar('\n');
	}
}
