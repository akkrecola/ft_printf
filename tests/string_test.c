/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 06:34:29 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/21 02:14:27 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("|\tPrinted: %i\n", ft_printf("This is a string: %s", "Fuck you."));
	printf("|\tPrinted: %i\n", printf("This is a string: %s", "Fuck you."));
}
