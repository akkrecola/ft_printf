/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neginf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 09:27:20 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 11:41:21 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <math.h>
#define FORMAT "{%+lf}\n"
#define TESTS 16


static const double	inputs[TESTS] =
{
	42.420l,
	-42.420l,
	0.00000l,
	-0.00000l,
	0.00500l,
	DBL_MIN,
	LDBL_MAX,
	LDBL_MIN,
	-1.0 / 0.0l,
	NAN,
	0.5l,
	1.5l,
	458.356000,
	-1067.39999,
	1444565444646.6465424242242l,
	-1444565444646.6465424242242454654l,
};

int	main(void)
{
	for (unsigned i = 0; i < TESTS; i++)
	{
		ft_printf(FORMAT, inputs[i]);
		printf(FORMAT, inputs[i]);
	}
}

