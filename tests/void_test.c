/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:13:44 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 09:00:48 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
#define TESTS 3
#define VOID_FORMAT "%0.20p\n"

int	main(void)
{
	void	*address = ft_memalloc(100);

	for (unsigned i = 0; i < TESTS; i++)
	{
		ft_printf(VOID_FORMAT, address);
		printf(VOID_FORMAT, address);
	}
	free(address);
}
