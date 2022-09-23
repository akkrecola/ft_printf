/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literal_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:16 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 09:22:02 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define TESTS 1
#define FORMAT "%"

int	main(void)
{
	ft_printf(FORMAT);
	printf(FORMAT);
}
