/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strgetset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:47:58 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 03:52:37 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	main()
{
	const char	*set = ft_strgetset("abcde", "cd", "", 5);
	ft_putstr(set);
	free((char *)set);
}
