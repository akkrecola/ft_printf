/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:34:58 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/22 23:22:28 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#define HEX_FORMAT "%0#8X\n"
#define HEX_TESTS 4

const unsigned int basic_inputs[] =
{
	0,
	42,
	-42,
	UINT_MAX,
};

int	main(void)
{
	for (unsigned i = 0; i < HEX_TESTS; i++)
	{
		ft_printf(HEX_FORMAT, basic_inputs[i]);
		printf(HEX_FORMAT, basic_inputs[i]);
	}
}
