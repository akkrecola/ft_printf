/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_until_specifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:20:38 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/14 16:37:15 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"

void	print_test(const char *input)
{
	ft_printf(input);
	ft_putchar('\n');
}

int	main(void)
{
	for (int i = 0; i < TOTAL_TEST_INPUTS; i++)
		print_test(g_test_inputs[i]);
}
