/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:22:40 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 05:34:26 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define FORMAT "%-10s\n"
#define STRING "Yeeee HAI!"

int	main(void)
{
	ft_printf(FORMAT, STRING);
	printf(FORMAT, STRING);
}
