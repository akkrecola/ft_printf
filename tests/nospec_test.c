/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nospec_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:03:08 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/21 03:19:39 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define FORMAT "|\tPrinted: %i\n"
/*#define STRING " % m %       "*/
#define STRING "  %m        m#  %#+0mmm    %"
/*#define STRING "%    "*/

int	main(void)
{
	printf(FORMAT, ft_printf(STRING));
	printf(FORMAT, printf(STRING));
}
