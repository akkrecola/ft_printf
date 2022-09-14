/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:14:24 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 00:34:10 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "ft_printf.h"

#ifndef TESTS_PRINTF_H
# define TESTS_PRINTF_H

// Number of test inputs below.
# define TOTAL_TEST_INPUTS 7
const char	*g_test_inputs[TOTAL_TEST_INPUTS] =
{
	"A single percent sign, error! ->%<-",
	"Signed integer (i): %i, formatted signed integer (d): %# .10d.", // 1
	"Unsigned integer: %u, octal: %o, lowercase hex: %x, "
		"uppercase hex: %X.", // 2
	"String: %s.", // 3
	"Char: %c, percent sign: %%.", // 4
	"Float: %f.", // 5
	"Void: %p.",
};

#endif
