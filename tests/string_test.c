/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 06:34:29 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/24 14:16:08 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define FORMAT "%.5s\n"

int	main()
{
	ft_printf(FORMAT, NULL);
	/*printf(FORMAT, NULL);*/
}
